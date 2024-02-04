package com.doge.torrent.files.hasher;

import com.doge.torrent.files.bencode.Bencode;
import com.doge.torrent.files.bencode.TorrentEncoder;
import com.doge.torrent.files.hasher.exception.HashingException;
import com.doge.torrent.logging.TorrentLoggerFactory;
import org.slf4j.Logger;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Map;

public class TorrentHasher {

	private static final String HASH_ALGORITHM = "SHA-1";
	private static final Charset DEFAULT_CHARSET = StandardCharsets.ISO_8859_1;
	private static final Logger LOGGER = TorrentLoggerFactory.getLogger(TorrentHasher.class);

	private static final TorrentEncoder ENCODER = new Bencode();

	public static String hash(String bytes) {
		return hash(bytes.getBytes(), DEFAULT_CHARSET);
	}

	public static String hash(String bytes, Charset charset) {
		return hash(bytes.getBytes(), charset);
	}

	public static String hash(byte[] bytes) {
		return hash(bytes, DEFAULT_CHARSET);
	}

	public static String hash(byte[] bytes, Charset charset) {
		try {
			LOGGER.debug("Hashing bytes: " + new String(bytes, charset));
			MessageDigest digest = MessageDigest.getInstance(HASH_ALGORITHM);
			byte[] hashedBytes = digest.digest(bytes);
			String hashedString = new String(hashedBytes, charset);
			LOGGER.debug("Hashed bytes: " + hashedString);
			return hashedString;
		} catch (NoSuchAlgorithmException e) {
			throw new HashingException(e);
		}
	}

	public static String hashEncodedMap(Map<?, ?> map) {
		return hash(ENCODER.encode(map), DEFAULT_CHARSET);
	}

	public static String hashEncodedMap(Map<?, ?> map, Charset charset) {
		return hash(ENCODER.encode(map), charset);
	}
}
