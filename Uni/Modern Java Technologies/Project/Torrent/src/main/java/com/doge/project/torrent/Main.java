package com.doge.project.torrent;

import com.doge.project.torrent.files.TorrentFileParser;
import com.doge.project.torrent.files.TorrentFileParserImpl;

public class Main {

	public static void main(String[] args) {
		TorrentFileParser parser = new TorrentFileParserImpl();

		String path = "C:\\Users\\PC-Admin\\Desktop\\Torrent\\test2.torrent";

		System.out.println(parser.parseFromPath(path));

	}

}
