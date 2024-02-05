package com.doge.torrent.connection;

import com.doge.torrent.announce.model.Peer;
import com.doge.torrent.connection.message.BitField;
import com.doge.torrent.connection.message.Message;
import com.doge.torrent.connection.message.MessageId;
import com.doge.torrent.connection.piece.PieceProgress;
import com.doge.torrent.files.model.TorrentPiece;
import com.doge.torrent.logging.Logger;
import com.doge.torrent.logging.TorrentLoggerFactory;

import java.util.concurrent.BlockingQueue;

public class ClientWorker implements Runnable {

	private final BlockingQueue<TorrentPiece> pieceQueue;
	private final BlockingQueue<PieceProgress> finishedQueue;
	private final ClientConnector connector;
	private final Peer peer;
	private BitField bitField;
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
		try {
			LOGGER.info("Started download for peer: " + peer);
			connector.connect(peer);
			connector.sendMessage(Message.UNCHOKE);
			LOGGER.info("Sent unchoke to peer: " + peer);
			connector.sendMessage(Message.INTERESTED);
			connector.readMessage();
			LOGGER.info("Sent interested to peer: " + peer);
		} catch (Exception e) {
			LOGGER.error("Error while connecting to peer: " + peer, e);
			return;
		}
		while (!Thread.currentThread().isInterrupted() && !pieceQueue.isEmpty()) {
			try {
				TorrentPiece piece = pieceQueue.take();
				if (connector.hasPiece(piece)) {
					LOGGER.info("Peer: " + peer + " has piece: " + piece + "starting download");
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

	private void readMessage() {
		Message message = connector.readMessage();
		if (isValidMessage(message)) {
			LOGGER.debug("Received message from peer: " + peer + "Message: " + message);
			if (message.id() == MessageId.BITFIELD) {
				bitField = new BitField(message.payload());
			}
		}
	}

	private boolean isValidMessage(Message message) {
		return message != null && !message.isKeepAlive();
	}
}
