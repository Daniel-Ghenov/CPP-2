package com.doge.torrent;

import com.doge.torrent.announce.Announcer;
import com.doge.torrent.announce.AnnouncerImpl;
import com.doge.torrent.download.TorrentDownloader;
import com.doge.torrent.files.TorrentFileParser;
import com.doge.torrent.files.TorrentFileParserImpl;
import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.ConsoleAppender;
import org.apache.log4j.PatternLayout;

public class Main {

	public static void main(String[] args) {
		TorrentFileParser parser = new TorrentFileParserImpl();

		String path = "C:\\Users\\PC-Admin\\Desktop\\Torrent\\test2.torrent";

		Announcer announcer = new AnnouncerImpl();
		TorrentDownloader downloader = new TorrentDownloader(parser, announcer);
		downloader.download(path);
	}

}
