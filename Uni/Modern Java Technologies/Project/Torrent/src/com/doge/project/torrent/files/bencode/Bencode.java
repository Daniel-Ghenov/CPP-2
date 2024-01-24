package com.doge.project.torrent.files.bencode;

import com.doge.project.torrent.files.bencode.exception.BencodeException;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.charset.Charset;

public class Bencode {

	private static final Charset DEFAULT_CHARSET = Charset.forName("UTF-8");

	static final char NUMBER = 'i';

	static final char LIST = 'l';

	static final char DICTIONARY = 'd';

	static final char TERMINATOR = 'e';

	static final char SEPARATOR = ':';

	private final Charset charset;

	public Bencode() {
		this(DEFAULT_CHARSET);
	}

	public Bencode(Charset charset) {
		this.charset = charset;
	}

	public BencodeType<?> getType(byte[] bencode) {
		BencodeInputStream is = new BencodeInputStream(new ByteArrayInputStream(bencode));

		try {
			return is.getNextType();
		} catch (IOException e) {
			throw new BencodeException(e);
		}
	}

	public <T> T decode(String bencode, BencodeType<T> type) {
		return decode(bencode.getBytes(charset), type);
	}

	public <T> T decode(byte[] bencode, BencodeType<T> type) {
		BencodeInputStream is = new BencodeInputStream(new ByteArrayInputStream(bencode));

		try {
			if (type == BencodeType.bencodeString) {
				return (T) is.readString();
			} else if (type == BencodeType.bencodeNumber) {
				return (T) is.readNumber();
			} else if (type == BencodeType.bencodeList) {
				return (T) is.readList();
			} else if (type == BencodeType.bencodeDictionary) {
				return (T) is.readDictionary();
			}
		} catch (IOException e) {
			throw new BencodeException(e);
		}
	}

}
