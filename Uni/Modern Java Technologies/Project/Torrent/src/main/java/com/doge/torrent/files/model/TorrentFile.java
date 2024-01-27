package com.doge.torrent.files.model;

import java.util.List;
import java.util.Map;

public record TorrentFile(
	String announce,
	List<String> announceList,
	List<String> urlList,
	TorrentInfo info
) {

	@SuppressWarnings("unchecked")
	public static TorrentFile fromMap(Map<String, Object> map) {
		String announce = (String) map.get("announce");
		List<String> announceList = (List<String>) map.get("announce-list");
		List<String> urlList = (List<String>) map.get("url-list");
		TorrentInfo info = TorrentInfo.fromMap((Map<String, Object>) (map.get("info")));
		return new TorrentFile(announce, announceList, urlList, info);
	}

}
