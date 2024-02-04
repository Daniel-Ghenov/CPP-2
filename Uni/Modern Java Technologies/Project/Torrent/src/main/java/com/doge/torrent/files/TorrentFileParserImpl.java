package com.doge.torrent.files;

import com.doge.torrent.files.bencode.Bencode;
import com.doge.torrent.files.bencode.TorrentDecoder;
import com.doge.torrent.files.model.SourceFile;
import com.doge.torrent.files.model.TorrentFile;
import com.doge.torrent.files.bencode.BencodeType;
import com.doge.torrent.files.model.TorrentInfo;
import com.doge.torrent.files.model.TorrentPiece;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import static com.doge.torrent.files.hasher.TorrentHasher.hashEncodedMap;

public class TorrentFileParserImpl implements TorrentFileParser {

	private final TorrentDecoder decoder;

	public TorrentFileParserImpl() {
		this(new Bencode());
	}

	public TorrentFileParserImpl(TorrentDecoder decoder) {
		this.decoder = decoder;
	}

	@SuppressWarnings("unchecked")
	@Override
	public TorrentFile parse(byte[] content) {
		Map<String, Object> dict = decoder.decode(content, BencodeType.bencodeDictionary);
		String announce = (String) dict.get("announce");
		List<String> announceList = parseAnnounceList(dict);
		List<String> urlList = (List<String>) dict.get("url-list");
		Map<String, Object> infoMap = (Map<String, Object>) dict.get("info");
		TorrentInfo info = fromMap(infoMap);
		String infoHash = hashEncodedMap(infoMap);
		return new TorrentFile(announce, announceList, urlList, info, infoHash);
	}

	@SuppressWarnings("unchecked")
	public static TorrentInfo fromMap(Map<String, Object> map) {
		Long length = (Long) map.get("length");
		String name = (String) map.get("name");
		Long pieceLength = (Long) map.get("piece length");
		List<TorrentPiece> pieces = getPieces((String) map.get("pieces"), pieceLength);
		List<Map<String, Object>> filesObjects = (List<Map<String, Object>>) map.get("files");
		List<SourceFile> files = null;

		if (filesObjects == null) {
			files = new ArrayList<>();
		} else {
			files = filesObjects.stream().map(SourceFile::fromMap).toList();
		}
		return new TorrentInfo(length, name, pieceLength, files, pieces);
	}

	private static List<TorrentPiece> getPieces(String pieces, Long pieceLength) {
		List<TorrentPiece> chunks = new ArrayList<>();
		for (int i = 0; i < pieces.length(); i += TorrentInfo.PIECE_BYTE_LENGTH) {
			String hash = pieces.substring(i, Math.min(pieces.length(), i + TorrentInfo.PIECE_BYTE_LENGTH));
			TorrentPiece piece = new TorrentPiece(hash.getBytes(),
									  i / TorrentInfo.PIECE_BYTE_LENGTH,
									  pieceLength);
			chunks.add(piece);
		}
		return chunks;
	}

	@SuppressWarnings("unchecked")
	private static List<String> parseAnnounceList(Map<String, Object> map) {
		List<List<String>> announceList = (List<List<String>>) map.get("announce-list");
		if (announceList == null) {
			return List.of();
		}
		return announceList.stream().flatMap(List::stream).toList();
	}

	@Override
	public TorrentFile parseFromPath(String path) {
		try {
			byte[] content = Files.readAllBytes(Paths.get(path));
			return parse(content);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}
