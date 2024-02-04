package com.doge.torrent.files.model;

import java.util.List;
import java.util.Map;

import static com.doge.torrent.files.hasher.TorrentHasher.hashEncodedMap;

public record TorrentFile(
	String announce,
	List<String> announceList,
	List<String> urlList,
	TorrentInfo info,
	String infoHash
) {

	public String getAnnounceUrl() {
		if (announceList == null || announceList.isEmpty()) {
			return announce;
		}
		return announceList.getFirst();
	}

}
