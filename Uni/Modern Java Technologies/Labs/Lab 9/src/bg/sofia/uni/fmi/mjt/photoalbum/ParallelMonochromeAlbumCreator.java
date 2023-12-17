package bg.sofia.uni.fmi.mjt.photoalbum;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.concurrent.ConcurrentSkipListSet;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class ParallelMonochromeAlbumCreator implements MonochromeAlbumCreator{

    private static final int THREADS_TO_VIRTUAL_MULTIPLIER = 3;

    final int processorsCount;

    final ImageQueue imageQueue;

    public ParallelMonochromeAlbumCreator(int processorsCount) {
        this.processorsCount = processorsCount;
        imageQueue = new ImageQueue();
    }

    @Override
    public void processImages(String sourceDirectory, String outputDirectory) {

        Path path = Path.of(sourceDirectory);
        Set<Path> toVisit;

        try (Stream<Path> stream = Files.walk(path)) {
            toVisit = stream.filter(Files::isRegularFile)
                    .collect(Collectors.toCollection(ConcurrentSkipListSet::new));

        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
        Path destination = Path.of(outputDirectory);

        List <Thread> producers = Collections.nCopies(processorsCount, Thread.ofVirtual().start(
                () -> {
                    while(!toVisit.isEmpty()) {
                        Path next = getPath(toVisit);
                        Image img = loadImage(next);
                        imageQueue.add(img);
                    }
                }
        ));
        List<Thread> consumers = Collections.nCopies(processorsCount, Thread.ofVirtual().start(
                () -> {
                    while (!imageQueue.isEmpty()) {
                        Image toProcess = imageQueue.get();
                        Image monochromeImg = convertToBlackAndWhite(toProcess);
                        writeImageToFile(monochromeImg, destination);
                    }
                }
        ));
    }

    private synchronized Path getPath(Set<Path> toVisit) {
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
        BufferedImage processedData = new BufferedImage(image.data.getWidth(), image.data.getHeight(), BufferedImage.TYPE_BYTE_GRAY);
        processedData.getGraphics().drawImage(image.data, 0, 0, null);

        return new Image(image.name, processedData);
    }
    private void writeImageToFile(Image image, Path output) {
        try {
            BufferedImage bufferedImage = image.data;

            ImageIO.write(bufferedImage, image.name, File);

        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }
}
