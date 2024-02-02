package com.doge.torrent.connection;

import com.doge.torrent.announce.model.Peer;
import com.doge.torrent.connection.message.Handshake;
import com.doge.torrent.connection.message.Message;
import com.doge.torrent.files.model.TorrentPiece;
import com.doge.torrent.logging.TorrentLoggerFactory;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.logging.Logger;

public class TCPClientConnector implements ClientConnector {
	private Peer peer;
	private final String infoHash;
	private final String peerId;

	private static final Logger LOGGER = TorrentLoggerFactory.getLogger(TCPClientConnector.class);

	public TCPClientConnector(String infoHash, String peerId) {
		this.infoHash = infoHash;
		this.peerId = peerId;
	}

	@Override
	public void connect(Peer peer) {
		this.peer = peer;
		try (Socket socket = new Socket(peer.address().getAddress(), peer.address().getPort())) {
			InputStream in = socket.getInputStream();
			OutputStream out = socket.getOutputStream();

			Handshake handshake = new Handshake(infoHash, peerId);
			out.write(handshake.toMessage());
			byte[] response = new byte[Handshake.HANDSHAKE_LENGTH];
			in.read(response);
			Handshake responseHandshake = Handshake.fromMessage(response);
			responseHandshake.validateClientHandshake(handshake);

		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	@Override
	public void disconnect() {

	}

	@Override
	public Message downloadPiece(TorrentPiece piece) {
		return null;
	}
}
