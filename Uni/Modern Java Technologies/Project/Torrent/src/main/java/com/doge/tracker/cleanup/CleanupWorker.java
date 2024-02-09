package com.doge.tracker.cleanup;

import java.util.List;
import java.util.Map;

public class CleanupWorker<T extends Inserted> implements Runnable {
	private final Long deletionInterval;

	private final Map<?, List<T>> insertedMap;

	public CleanupWorker(Long deletionInterval, Map<?, List<T>> insertedMap) {
		this.deletionInterval = deletionInterval;
		this.insertedMap = insertedMap;
	}

	@Override public void run() {
		while (!Thread.currentThread().isInterrupted()) {
			cleanup();
			try {
				Thread.sleep(deletionInterval);
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}

	}

	private void cleanup() {
		insertedMap.values().forEach(this::cleanList);
	}

	private void cleanList(List<T> list) {
		list.removeIf(inserted -> inserted.getInsertionTime()
				  .isBefore(inserted.getInsertionTime().minusSeconds(deletionInterval)));
	}
}
