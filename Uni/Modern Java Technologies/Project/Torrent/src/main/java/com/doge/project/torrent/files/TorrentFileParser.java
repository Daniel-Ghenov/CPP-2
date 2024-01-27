package com.doge.project.torrent.files;

import com.doge.project.torrent.files.model.TorrentFile;

public interface TorrentFileParser {

	TorrentFile parse(byte[] content);

	TorrentFile parseFromPath(String path);

}
