package com.doge.tracker.server;

import com.doge.torrent.files.bencode.TorrentEncoder;
import com.doge.tracker.TorrentTracker;
import com.doge.tracker.server.handlers.AnnounceHandler;
import com.sun.net.httpserver.HttpServer;

import java.io.IOException;
import java.net.InetSocketAddress;

public class TorrentTrackerServer {

	private final TorrentTracker torrentTracker;

	private final TorrentEncoder torrentEncoder;

	private static final int PORT = 8080;

	private static final int BACKLOG = 0;

	public TorrentTrackerServer(TorrentTracker torrentTracker, TorrentEncoder torrentEncoder) {
		this.torrentTracker = torrentTracker;
		this.torrentEncoder = torrentEncoder;
	}

	public void start() {
		try {
			HttpServer server = HttpServer.create(new InetSocketAddress(PORT), BACKLOG);
			server.createContext("/announce", new AnnounceHandler(torrentTracker, torrentEncoder));
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

}
