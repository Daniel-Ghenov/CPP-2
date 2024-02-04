package com.doge.torrent.connection;

import com.doge.torrent.announce.model.Peer;
import com.doge.torrent.connection.exception.ClientConnectionException;
import com.doge.torrent.connection.message.BitField;
import com.doge.torrent.connection.message.Handshake;
import com.doge.torrent.connection.message.Message;
import com.doge.torrent.connection.piece.PieceProgress;
import com.doge.torrent.files.model.TorrentPiece;
import com.doge.torrent.logging.Logger;
import com.doge.torrent.logging.TorrentLoggerFactory;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Arrays;

import static com.doge.torrent.files.hasher.TorrentHasher.hash;

public class TCPClientConnector implements ClientConnector {
	private static final Logger LOGGER = TorrentLoggerFactory.getLogger(TCPClientConnector.class);
	private static final int MAX_BLOCK_SIZE = 16384;
	private Peer peer;
	private final String infoHash;
	private final String peerId;
	private Socket socket;
	private InputStream in;
	private OutputStream out;
	private BitField bitField;

	public TCPClientConnector(String infoHash, String peerId) {
		this.infoHash = infoHash;
		this.peerId = peerId;
	}

	@Override
	public void connect(Peer peer) {
		this.peer = peer;
		try (Socket socket = new Socket(peer.address().getAddress(), peer.address().getPort())) {
			this.socket = socket;
			this.in = socket.getInputStream();
			this.out = socket.getOutputStream();

			Handshake handshake = new Handshake(infoHash, peerId);
			out.write(handshake.toMessage());
			byte[] response = new byte[Handshake.HANDSHAKE_LENGTH];
			in.read(response);
			Handshake responseHandshake = Handshake.fromMessage(response);
			responseHandshake.validatePeerHandshake(handshake);

		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	@Override
	public void disconnect() {
		try {
			socket.close();
		} catch (IOException e) {
			LOGGER.error("Failed to close socket");
		}
	}

	@Override
	public PieceProgress downloadPiece(TorrentPiece piece) {
		if (bitField == null) {
			throw new ClientConnectionException("Bitfield not set");
		}
		if (!bitField.hasPiece(piece.index())) {
			return null;
		}
		PieceProgress progress = new PieceProgress(piece);
		while (!progress.isComplete()) {
			Message message = Message.request(piece.index(), progress.requested(), MAX_BLOCK_SIZE);
			sendMessages(message);
			Message response = Message.fromBytes(readMessage());
			if (response.isPiece()) {
				progress.addBlock(response);
			}
		}
		if (!validatePiece(progress)) {
			throw new ClientConnectionException("Error downloading piece. Invalid hash.");
		}
		return progress;
	}

	private boolean validatePiece(PieceProgress progress) {
		byte[] hash = hash(progress.data()).getBytes();
		if (!Arrays.equals(progress.hash(), hash)) {
			LOGGER.error("Piece hash does not match");
			return false;
		}
		return true;
	}

	private byte[] readMessage() {
		try {
			int length = in.read();
			if (length == -1) {
				throw new ClientConnectionException("Connection closed");
			}
			byte[] bytes = new byte[length];
			in.read(bytes);
			return bytes;
		} catch (IOException e) {
			throw new ClientConnectionException(e);
		}
	}

	@Override
	public void sendMessages(Message message) {
		try {
			out.write(message.toBytes());
		} catch (IOException e) {
			throw new ClientConnectionException(e);
		}
	}

	@Override
	public boolean hasPiece(TorrentPiece piece) {
		return bitField.hasPiece(piece.index());
	}
}
