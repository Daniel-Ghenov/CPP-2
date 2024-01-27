package com.doge.project.torrent.files.decoder;

import com.doge.project.torrent.files.decoder.exception.BencodeException;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public class Bencode implements TorrentDecoder {

	private static final Charset DEFAULT_CHARSET = StandardCharsets.UTF_8;

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

	@Override
	public BencodeType<?> getType(byte[] bencode) {
		BencodeInputStream is = new BencodeInputStream(new ByteArrayInputStream(bencode));

		try {
			return is.getNextType();
		} catch (IOException e) {
			throw new BencodeException(e);
		}
	}

	@Override
	public <T> T decode(String bencode, BencodeType<T> type) {
		if (bencode == null) {
			throw new BencodeException("Bencode cannot be null");
		}
		if (type == null) {
			throw new BencodeException("Type cannot be null");
		}
		if (type == BencodeType.bencodeUnknown) {
			throw new BencodeException("Type cannot be unknown");
		}

		return decode(bencode.getBytes(charset), type);
	}

	@Override
	@SuppressWarnings("unchecked")
	public <T> T decode(byte[] bencode, BencodeType<T> type) {

		if (bencode == null) {
			throw new BencodeException("Bencode cannot be null");
		}
		if (type == null) {
			throw new BencodeException("Type cannot be null");
		}
		if (type == BencodeType.bencodeUnknown) {
			throw new BencodeException("Type cannot be unknown");
		}

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
		throw new BencodeException("Unknown type: " + type);
	}

}
