package bg.sofia.uni.fmi.mjt.photoalbum;

import java.util.LinkedList;
import java.util.Queue;

public class ImageQueue  {
    private final Queue<Image> images;

    public ImageQueue(Queue<Image> images) {
        this.images = images;
    }
    public ImageQueue() {
        this.images = new LinkedList<>();
    }

    public synchronized void add(Image image) {
        images.add(image);
        notifyAll();
    }

    public synchronized Image get() {
        Image img = images.poll();
        notifyAll();
        return img;
    }

    public synchronized boolean isEmpty() {
        return images.isEmpty();
    }
}
