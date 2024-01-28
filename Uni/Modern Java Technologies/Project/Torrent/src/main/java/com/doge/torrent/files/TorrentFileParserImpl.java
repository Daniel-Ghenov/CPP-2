package com.doge.torrent.files;

import com.doge.torrent.files.bencode.Bencode;
import com.doge.torrent.files.bencode.TorrentDecoder;
import com.doge.torrent.files.model.TorrentFile;
import com.doge.torrent.files.bencode.BencodeType;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;

public class TorrentFileParserImpl implements TorrentFileParser {

	private final TorrentDecoder decoder;

	public TorrentFileParserImpl() {
		this(new Bencode());
	}

	public TorrentFileParserImpl(TorrentDecoder decoder) {
		this.decoder = decoder;
	}

	@Override public TorrentFile parse(byte[] content) {
		Map<String, Object> dict = decoder.decode(content, BencodeType.bencodeDictionary);
		return TorrentFile.fromMap(dict);
	}

	@Override public TorrentFile parseFromPath(String path) {
		try {
			byte[] content = Files.readAllBytes(Paths.get(path));
			return parse(content);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}
