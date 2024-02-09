package com.doge.tracker.model;

import com.doge.torrent.announce.model.Peer;
import com.doge.tracker.cleanup.Inserted;

import java.time.LocalDateTime;

public record PeerInsertion(
		Peer peer,
		LocalDateTime insertionTime
) implements Inserted {
	@Override public LocalDateTime getInsertionTime() {
		return insertionTime;
	}
}
