package com.doge.torrent.announce.model;

import java.net.InetSocketAddress;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public record Peer(
		InetSocketAddress address,
		String peerId
) {
	private static final Charset DEFAULT_CHARSET = StandardCharsets.ISO_8859_1;
	public static final int PEER_BYTE_LENGTH_NO_ID = 6;
	public static final int PEER_BYTE_LENGTH_WITH_ID = 10;
	private static final int IP_LENGTH = 4;
	private static final int PORT_START = 4;
	private static final int PORT_END = 5;
	private static final int PORT_START_SHIFT = 8;

	public Peer(String ip, Integer port, String peerId) {
		this(new InetSocketAddress(ip, port), peerId);
	}

	public static Peer fromByteArr(byte[] bytes) {
		String ip = getIp(bytes);
		Integer port = getPort(bytes);
		String peerId = getPeerId(bytes);
		return new Peer(new InetSocketAddress(ip, port), null);
	}

	private static String getPeerId(byte[] bytes) {
		if (bytes.length < PEER_BYTE_LENGTH_WITH_ID) {
			return null;
		}
		return new String(bytes, PEER_BYTE_LENGTH_NO_ID, PEER_BYTE_LENGTH_WITH_ID, DEFAULT_CHARSET);
	}

	private static String getIp(byte[] bytes) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < IP_LENGTH; i++) {
			sb.append(bytes[i]);
			if (i != IP_LENGTH - 1) {
				sb.append(".");
			}
		}
		return sb.toString();
	}

	private static Integer getPort(byte[] bytes) {
		return ((int) (bytes[PORT_START]) << PORT_START_SHIFT) | (bytes[PORT_END]);
	}
}
