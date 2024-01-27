package com.doge.torrent.files.model;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public record TorrentInfo(
		Long length,
		String name,
		Long pieceLength,
		List<SourceFile> files,
		List<TorrentPiece> pieces
) {

	public static final int PIECE_BYTE_LENGTH = 20;

	@SuppressWarnings("unchecked")
	public static TorrentInfo fromMap(Map<String, Object> map) {
		Long length = (Long) map.get("length");
		String name = (String) map.get("name");
		Long pieceLength = (Long) map.get("piece length");
		List<TorrentPiece> pieces = getPieces((String) map.get("pieces"));
		List<Map<String, Object>> filesObjects = (List<Map<String, Object>>) map.get("files");
		List<SourceFile> files = null;

		if (filesObjects == null) {
			files = new ArrayList<>();
		} else {
			files = filesObjects.stream().map(SourceFile::fromMap).toList();
		}
		return new TorrentInfo(length, name, pieceLength, files, pieces);
	}

	private static List<TorrentPiece> getPieces(String pieces) {
		List<String> chunks = new ArrayList<>();
		for (int i = 0; i < pieces.length(); i += PIECE_BYTE_LENGTH) {
			chunks.add(pieces.substring(i, Math.min(pieces.length(), i + PIECE_BYTE_LENGTH)));
		}
		return chunks.stream().map(str -> new TorrentPiece(str.getBytes())).toList();
	}
}
