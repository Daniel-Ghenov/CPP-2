package com.doge.torrent.announce;

import com.doge.torrent.announce.model.AnnounceRequest;
import com.doge.torrent.announce.model.AnnounceResponse;
import com.doge.torrent.files.bencode.Bencode;
import com.doge.torrent.files.bencode.TorrentDecoder;
import com.doge.torrent.logging.TorrentLoggerFactory;
import com.doge.torrent.utils.URIBuilder;
import org.slf4j.Logger;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;
import java.util.Map;

import static com.doge.torrent.files.bencode.BencodeType.bencodeDictionary;

public class AnnouncerImpl implements Announcer {

	private static final Logger LOGGER = TorrentLoggerFactory.getLogger(AnnouncerImpl.class);

	public static final Integer DEFAULT_PORT = 50420;

	private static final int MIN_SUCCESS_STATUS_CODE = 200;
	private static final int MAX_SUCCESS_STATUS_CODE = 299;

	private final HttpClient httpClient;

	private final TorrentDecoder torrentDecoder;

	public AnnouncerImpl() {
		this(HttpClient.newHttpClient(), new Bencode());
	}

	public AnnouncerImpl(HttpClient httpClient, TorrentDecoder torrentDecoder) {
		this.httpClient = httpClient;
		this.torrentDecoder = torrentDecoder;
	}

	@Override
	public AnnounceResponse announce(AnnounceRequest request) {
		URI uri = buildUri(request);
		HttpRequest httpRequest = HttpRequest.newBuilder(uri)
											 .GET()
											 .build();

		return getAnnounceResponse(httpRequest);
	}

	private AnnounceResponse getAnnounceResponse(HttpRequest httpRequest) {
		LOGGER.debug("Sending request: " + httpRequest);
		try {
			HttpResponse<String> response = httpClient.send(httpRequest,
									HttpResponse.BodyHandlers.ofString());
		    if (response.statusCode() < MIN_SUCCESS_STATUS_CODE ||
				response.statusCode() > MAX_SUCCESS_STATUS_CODE) {
				throw new RuntimeException("Invalid status code: " + response.statusCode());
			}
			return parseResponse(response.body());

		} catch (IOException | InterruptedException e) {
			throw new RuntimeException(e);
		}
	}

	private AnnounceResponse parseResponse(String body) {

		Map<String, Object> decoded = torrentDecoder.decode(body, bencodeDictionary);
		LOGGER.debug("Decoded response: " + decoded);
		if (decoded.containsKey("failure reason")) {
			throw new RuntimeException("Failure reason: " + decoded.get("failure reason"));
		}
		return AnnounceResponse.fromMap(decoded);
	}

	private URI buildUri(AnnounceRequest request) {
		LOGGER.info("Building URI for request: " + request);
		return URIBuilder.fromURL(request.trackerAnnounceUrl())
						 .queryParam("info_hash", request.infoHash(),
									 StandardCharsets.ISO_8859_1)
						 .queryParam("peer_id", request.peerId(),
									 StandardCharsets.ISO_8859_1)
						 .queryParam("downloaded", request.downloaded())
						 .queryParam("uploaded", request.uploaded())
						 .queryParam("left", request.left())
						 .queryParam("compact", request.compact())
						 .queryParam("port", DEFAULT_PORT)
						 .buildURI();
	}
}
