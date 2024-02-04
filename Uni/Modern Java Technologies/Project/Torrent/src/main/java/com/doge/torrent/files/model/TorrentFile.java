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
		List<String> announceList = parseAnnounceList(map);
		List<String> urlList = (List<String>) map.get("url-list");
		Map<String, Object> infoMap = (Map<String, Object>) map.get("info");
		TorrentInfo info = TorrentInfo.fromMap(infoMap);
		String infoHash = hashEncodedMap(infoMap);
		return new TorrentFile(announce, announceList, urlList, info, infoHash);
	}

	private static List<String> parseAnnounceList(Map<String, Object> map) {
		List<List<String>> announceList = (List<List<String>>) map.get("announce-list");
		if (announceList == null) {
			return List.of();
		}
		return announceList.stream().flatMap(List::stream).toList();
	}

	public String getAnnounceUrl() {
		if (announceList == null || announceList.isEmpty()) {
			return announce;
		}
		return announceList.getFirst();
	}

}
