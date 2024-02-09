package com.doge.tracker.server.handlers;

import com.doge.torrent.announce.model.Peer;
import com.doge.torrent.files.bencode.TorrentEncoder;
import com.doge.tracker.TorrentTracker;
import com.doge.tracker.model.TorrentTrackerResponse;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AnnounceHandler implements HttpHandler {
	private final TorrentTracker torrentTracker;

	private final TorrentEncoder torrentEncoder;

	private static final int BAD_REQUEST = 400;

	private static final int OK = 200;

	public AnnounceHandler(TorrentTracker torrentTracker, TorrentEncoder torrentEncoder) {
		this.torrentTracker = torrentTracker;
		this.torrentEncoder = torrentEncoder;
	}

	@Override public void handle(HttpExchange exchange) throws IOException {
		if (!exchange.getRequestMethod().equals("GET")) {
			exchange.sendResponseHeaders(BAD_REQUEST, -1);
			return;
		}
		Map<String, String> queryParams = extractQueryParams(exchange.getRequestURI().getQuery());
		byte[] response = getResponse(queryParams);

		exchange.sendResponseHeaders(OK, response.length);
		exchange.getResponseBody().write(response);
	}

	private byte[] getResponse(Map<String, String> queryParams) {
		String infoHash = queryParams.get("info_hash");
		TorrentTrackerResponse response = torrentTracker.getResponseForInfoHash(infoHash);
		Map<String, Object> responseMap = new HashMap<>();

		responseMap.put("interval", response.interval());
		List<Map<String, Object>> peers = response.peers().stream().map(this::peerToMap).toList();
		responseMap.put("peers", peers);

		return torrentEncoder.encode(responseMap);
	}

	private Map<String, Object> peerToMap(Peer peer) {
		Map<String, Object> peerMap = new HashMap<>();
		peerMap.put("ip", peer.address().getHostName());
		peerMap.put("port", peer.address().getPort());
		peerMap.put("peer_id", peer.peerId());
		return peerMap;
	}

	private Map<String, String> extractQueryParams(String query) {
		Map<String , String> queryParams = new HashMap<>();
		Arrays.stream(query.split("&" ))
				.map(param -> param.split("="))
				.forEach(param -> queryParams.put(param[0], param[1]));
		return queryParams;
	}
}
