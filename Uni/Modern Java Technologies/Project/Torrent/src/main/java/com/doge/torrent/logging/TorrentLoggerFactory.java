package com.doge.torrent.logging;

import java.util.logging.Logger;

public class TorrentLoggerFactory {

	private static String staticLoggersName = null;

	public static Logger getLogger(Class<?> clazz) {
		String name = staticLoggersName;
		if (name == null) {
			name = clazz.getName();
		}
		return Logger.getLogger(name);
	}

}
