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

	@SuppressWarnings("unchecked")
	public static TorrentFile fromMap(Map<String, Object> map) {
		String announce = (String) map.get("announce");
		List<String> announceList = (List<String>) map.get("announce-list");
		List<String> urlList = (List<String>) map.get("url-list");
		Map<String, Object> infoMap = (Map<String, Object>) map.get("info");
		TorrentInfo info = TorrentInfo.fromMap(infoMap);
		String infoHash = hashEncodedMap(infoMap);
		return new TorrentFile(announce, announceList, urlList, info, infoHash);
	}

}
