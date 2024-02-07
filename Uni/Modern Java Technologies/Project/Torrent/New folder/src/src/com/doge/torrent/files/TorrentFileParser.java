package com.doge.torrent.files;

import com.doge.torrent.files.model.TorrentFile;

public interface TorrentFileParser {

	TorrentFile parse(byte[] content);

	TorrentFile parseFromPath(String path);

}
