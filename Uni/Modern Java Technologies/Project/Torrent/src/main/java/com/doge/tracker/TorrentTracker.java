package com.doge.tracker;

import com.doge.torrent.announce.model.Peer;
import com.doge.tracker.cleanup.CleanupWorker;
import com.doge.tracker.model.PeerInsertion;
import com.doge.tracker.model.TorrentTrackerResponse;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.Collectors;

public class TorrentTracker {
	private static final Long DEFAULT_INTERVAL = 1800L;

	private static final Long PEER_DELETION_INTERVAL = 2400L;

	private final Map<String, List<PeerInsertion>> peersByInfoHash;

	public TorrentTracker() {
		this(new ConcurrentHashMap<>());
	}

	public TorrentTracker(Map<String, List<PeerInsertion>> peersByInfoHash) {
		this.peersByInfoHash = peersByInfoHash;
		startCleanupWorker();
	}

	public TorrentTrackerResponse getResponseForInfoHash(String infoHash) {
		return new TorrentTrackerResponse(DEFAULT_INTERVAL, getPeersByInfoHash(infoHash));
	}

	public List<Peer> getPeersByInfoHash(String infoHash) {
		return peersByInfoHash.get(infoHash)
				.stream()
				.map(PeerInsertion::peer)
				.collect(Collectors.toList());

	}

	public void addPeer(String infoHash, Peer peer) {
		peersByInfoHash.computeIfAbsent(infoHash, k -> Collections.synchronizedList(new ArrayList<>()));
		peersByInfoHash.get(infoHash).add(new PeerInsertion(peer, LocalDateTime.now()));
	}

	private void startCleanupWorker() {
		new Thread(new CleanupWorker<>(PEER_DELETION_INTERVAL, peersByInfoHash)).start();
	}
}
