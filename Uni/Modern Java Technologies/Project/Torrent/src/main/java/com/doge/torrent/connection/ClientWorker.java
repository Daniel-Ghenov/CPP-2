package com.doge.torrent.connection;

import com.doge.torrent.announce.model.Peer;
import com.doge.torrent.connection.message.Message;
import com.doge.torrent.files.model.TorrentPiece;
import com.doge.torrent.logging.TorrentLoggerFactory;

import java.util.concurrent.BlockingQueue;
import java.util.logging.Logger;

public class ClientWorker implements Runnable {

	private final BlockingQueue<TorrentPiece> pieceQueue;
	private final BlockingQueue<Message> messageQueue;
	private final ClientConnector connector;
	private final Peer peer;
	private static final Logger LOGGER = TorrentLoggerFactory.getLogger(ClientWorker.class);
	public ClientWorker(BlockingQueue<TorrentPiece> pieceQueue,
						BlockingQueue<Message> messageQueue,
						ClientConnector connector,
						Peer peer) {
		this.pieceQueue = pieceQueue;
		this.messageQueue = messageQueue;
		this.connector = connector;
		this.peer = peer;
	}

	@Override
	public void run() {
		connector.connect(peer);
		while (!Thread.currentThread().isInterrupted() && !pieceQueue.isEmpty()) {
			try {
				TorrentPiece piece = pieceQueue.take();
				Message received = connector.downloadPiece(piece);
				if (received == null || received.isKeepAlive()) {
					LOGGER.warning("Received invalid message from peer " + peer);
					pieceQueue.put(piece);
				} else {
					LOGGER.info("Received valid message from peer " + peer);
					messageQueue.put(received);
				}
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}
	}

	private boolean isValidMessage(Message message) {
		return message != null && !message.isKeepAlive();
	}
}
