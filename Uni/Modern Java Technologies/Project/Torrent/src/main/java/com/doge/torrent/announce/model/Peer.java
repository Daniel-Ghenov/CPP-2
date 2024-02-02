package com.doge.torrent.announce.model;

import java.net.InetSocketAddress;

public record Peer(
		InetSocketAddress address
) {

	public static final int PEER_BYTE_LENGTH = 6;
	private static final int IP_LENGTH = 4;
	private static final int PORT_START = 4;
	private static final int PORT_END = 5;
	private static final int PORT_START_SHIFT = 8;

	public static Peer fromByteArr(byte[] bytes) {
		if (bytes.length != PEER_BYTE_LENGTH) {
			throw new IllegalArgumentException("Peer byte array must be 6 bytes long");
		}
		String ip = getIp(bytes);
		Integer port = getPort(bytes);
		return new Peer(new InetSocketAddress(ip, port));
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
