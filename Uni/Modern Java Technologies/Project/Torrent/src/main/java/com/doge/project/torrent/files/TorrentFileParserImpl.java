package com.doge.project.torrent.files;

import com.doge.project.torrent.files.decoder.Bencode;
import com.doge.project.torrent.files.decoder.TorrentDecoder;
import com.doge.project.torrent.files.model.TorrentFile;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;

import static com.doge.project.torrent.files.decoder.BencodeType.bencodeDictionary;

public class TorrentFileParserImpl implements TorrentFileParser {

	private final TorrentDecoder decoder;

	public TorrentFileParserImpl() {
		this(new Bencode());
	}

	public TorrentFileParserImpl(TorrentDecoder decoder) {
		this.decoder = decoder;
	}

	@Override public TorrentFile parse(byte[] content) {
		Map<String, Object> dict = decoder.decode(content, bencodeDictionary);
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
