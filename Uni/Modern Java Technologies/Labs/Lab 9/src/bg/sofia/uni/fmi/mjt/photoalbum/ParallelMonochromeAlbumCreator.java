package bg.sofia.uni.fmi.mjt.photoalbum;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import java.util.concurrent.ConcurrentSkipListSet;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class ParallelMonochromeAlbumCreator implements MonochromeAlbumCreator {

    private static final int THREADS_TO_VIRTUAL_MULTIPLIER = 3;

    final int processorsCount;

    final ImageQueue imageQueue;

    public ParallelMonochromeAlbumCreator(int processorsCount) {
        this.processorsCount = processorsCount;
        imageQueue = new ImageQueue();
    }

    @Override
    public void processImages(String sourceDirectory, String outputDirectory) {
        Set<Path> toVisit = getToVisit(sourceDirectory);
        Path destination = Path.of(outputDirectory);

        List<Thread> producers = Collections.nCopies(processorsCount * THREADS_TO_VIRTUAL_MULTIPLIER,
                                                      Thread.ofVirtual().start(getProducerTask(toVisit)
        ));
        List<Thread> consumers = Collections.nCopies(processorsCount * THREADS_TO_VIRTUAL_MULTIPLIER,
                                                     Thread.ofVirtual().start(getConsumerTask(destination)
        ));
        terminateExecution(producers, consumers);
    }

    private Runnable getProducerTask(Set<Path> toVisit) {
        return () -> {
            while (!toVisit.isEmpty()) {
                Path next = getPath(toVisit);
                Image img = loadImage(next);
                imageQueue.add(img);
            }
        };
    }

    private Runnable getConsumerTask(Path destination) {
        return () -> {
            while (!imageQueue.isEmpty()) {
                Image toProcess = imageQueue.get();
                Image monochromeImg = convertToBlackAndWhite(toProcess);
                writeImageToFile(monochromeImg, destination);
            }
        };
    }

    private static void terminateExecution(List<Thread> producers, List<Thread> consumers) {
        try {
            for (Thread producer : producers) {
                producer.join();
            }
            for (Thread consumer : consumers) {
                consumer.interrupt();
            }
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    private Set<Path> getToVisit(String sourceDirectory) {
        Path path = Path.of(sourceDirectory);
        Set<Path> toVisit;

        try (Stream<Path> stream = Files.walk(path)) {
            toVisit = stream.filter(Files::isRegularFile)
                            .collect(Collectors.toCollection(ConcurrentSkipListSet::new));

        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
        return toVisit;
    }

    private synchronized Path getPath(Set<Path> toVisit) {
        if (toVisit.isEmpty()) {
            return null;
        }
        Path next = toVisit.iterator().next();
        toVisit.remove(next);
        notifyAll();
        return next;
    }

    private Image loadImage(Path imagePath) {
        try {
            BufferedImage imageData = ImageIO.read(imagePath.toFile());
            return new Image(imagePath.getFileName().toString(), imageData);
        } catch (IOException e) {
            throw new UncheckedIOException(String.format("Failed to load image %s", imagePath.toString()), e);
        }
    }

    private Image convertToBlackAndWhite(Image image) {
        BufferedImage processedData = new BufferedImage(image.data.getWidth(),
                                                        image.data.getHeight(),
                                                        BufferedImage.TYPE_BYTE_GRAY);
        processedData.getGraphics().drawImage(image.data, 0, 0, null);

        return new Image(image.name, processedData);
    }

    private void writeImageToFile(Image image, Path output) {
        try {
            BufferedImage bufferedImage = image.data;

            ImageIO.write(bufferedImage, "jpg", output.resolve(image.name).toFile());

        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }
}
