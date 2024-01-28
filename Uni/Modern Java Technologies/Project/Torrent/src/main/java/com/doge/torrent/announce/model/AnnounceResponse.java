package com.doge.torrent.announce.model;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public record AnnounceResponse(
		Long interval,
		List<Peer> peers
) {

	public static AnnounceResponse fromMap(Map<String, Object> map) {
		Long interval = (Long) map.get("interval");
		String peersString = (String) map.get("peers");
		List<Peer> peers = getPeers(peersString);
		return new AnnounceResponse(interval, peers);
	}

	private static List<Peer> getPeers(String peersString) {
		List<Peer> peers = new ArrayList<>();
		for (int i = 0; i < peersString.length(); i += Peer.PEER_BYTE_LENGTH) {
			int end = Math.min(peersString.length(), i + Peer.PEER_BYTE_LENGTH);
			peers.add(Peer.fromByteArr(peersString.substring(i, end).getBytes()));
		}
		return peers;
	}
}
