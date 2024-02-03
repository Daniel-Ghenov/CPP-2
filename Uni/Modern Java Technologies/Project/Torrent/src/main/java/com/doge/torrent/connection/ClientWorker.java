package com.doge.torrent.connection;

import com.doge.torrent.announce.model.Peer;
import com.doge.torrent.connection.message.Message;
import com.doge.torrent.connection.piece.PieceProgress;
import com.doge.torrent.files.model.TorrentPiece;
import com.doge.torrent.logging.TorrentLoggerFactory;
import org.slf4j.Logger;

import java.util.concurrent.BlockingQueue;

public class ClientWorker implements Runnable {

	private final BlockingQueue<TorrentPiece> pieceQueue;
	private final BlockingQueue<PieceProgress> finishedQueue;
	private final ClientConnector connector;
	private final Peer peer;
	private static final Logger LOGGER = TorrentLoggerFactory.getLogger(ClientWorker.class);
	public ClientWorker(
			BlockingQueue<TorrentPiece> pieceQueue,
			BlockingQueue<PieceProgress> finishedQueue,
			ClientConnector connector,
			Peer peer) {
		this.pieceQueue = pieceQueue;
		this.finishedQueue = finishedQueue;
		this.connector = connector;
		this.peer = peer;
	}

	@Override
	public void run() {
		connector.connect(peer);
		connector.sendMessages(Message.UNCHOKE);
		connector.sendMessages(Message.INTERESTED);
		while (!Thread.currentThread().isInterrupted() && !pieceQueue.isEmpty()) {
			try {
				TorrentPiece piece = pieceQueue.take();

				if (connector.hasPiece(piece)) {
					PieceProgress downloaded = connector.downloadPiece(piece);
					if (downloaded.isComplete()) {
						finishedQueue.put(downloaded);
					} else {
						pieceQueue.put(piece);
					}
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
