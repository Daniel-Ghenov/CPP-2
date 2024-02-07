package com.doge.torrent.download;

import com.doge.torrent.connection.piece.PieceProgress;
import com.doge.torrent.download.files.TorrentSaver;

import java.util.concurrent.BlockingQueue;

public class DownloadedWorker implements Runnable {

	private final BlockingQueue<PieceProgress> downloadedQueue;
	private final TorrentSaver saver;
	private final byte[] buffer;
	private int downloaded = 0;
	private final int pieceCount;

	public DownloadedWorker(BlockingQueue<PieceProgress> downloadedQueue,
							TorrentSaver saver,
							Long length,
							int pieceCount) {
		this.downloadedQueue = downloadedQueue;
		this.saver = saver;
		this.buffer = new byte[length.intValue()];
		this.pieceCount = pieceCount;
	}

	public DownloadedWorker(BlockingQueue<PieceProgress> downloadedQueue,
							TorrentSaver saver,
							int length,
							int pieceCount) {
		this.downloadedQueue = downloadedQueue;
		this.saver = saver;
		this.buffer = new byte[length];
		this.pieceCount = pieceCount;
	}

	@Override
	public void run() {
		while (!Thread.currentThread().isInterrupted()) {
			try {
				if (downloaded == pieceCount) {
					saver.save(buffer);
					break;
				}
				PieceProgress piece = downloadedQueue.take();
				System.arraycopy(piece.data(), 0, buffer,
					 (int) (piece.pieceIndex() * piece.pieceLength()), (int) piece.pieceLength());
				downloaded++;

			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}
	}
}
