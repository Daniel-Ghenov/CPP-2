package com.doge.torrent.logging;

import java.util.Optional;
import java.util.logging.Level;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class TorrentLoggerFactory {

	private static String staticLoggersName = null;
	private static Level level = Level.ALL;

	public static Logger getLogger(Class<?> clazz) {
		String name = Optional.ofNullable(staticLoggersName).orElse(clazz.getName());

		Logger logger = LoggerFactory.getLogger(name);
		return logger;
	}

}
