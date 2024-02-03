package com.doge.torrent.files.hasher;

import com.doge.torrent.files.bencode.Bencode;
import com.doge.torrent.files.bencode.TorrentEncoder;
import com.doge.torrent.files.hasher.exception.HashingException;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Map;

public class TorrentHasher {

	private static final String HASH_ALGORITHM = "SHA-1";

	private static final TorrentEncoder ENCODER = new Bencode();

	public static String hash(String bytes) {
		return hash(bytes.getBytes());
	}

	public static String hash(byte[] bytes) {
		try {
			MessageDigest digest = MessageDigest.getInstance(HASH_ALGORITHM);
			return new String(digest.digest(bytes));
		} catch (NoSuchAlgorithmException e) {
			throw new HashingException(e);
		}
	}

	public static String hashEncodedMap(Map<?, ?> map) {
		return hash(ENCODER.encode(map));
	}
}
