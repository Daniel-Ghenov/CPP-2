package com.doge.torrent.download;

import com.doge.torrent.announce.Announcer;
import com.doge.torrent.announce.model.AnnounceRequest;
import com.doge.torrent.announce.model.AnnounceRequestBuilder;
import com.doge.torrent.announce.model.AnnounceResponse;
import com.doge.torrent.announce.model.Event;
import com.doge.torrent.announce.model.Peer;
import com.doge.torrent.connection.ClientConnector;
import com.doge.torrent.connection.ClientWorker;
import com.doge.torrent.connection.TCPClientConnector;
import com.doge.torrent.connection.piece.PieceProgress;
import com.doge.torrent.download.files.FileTorrentSaver;
import com.doge.torrent.download.files.TorrentSaver;
import com.doge.torrent.files.TorrentFileParser;
import com.doge.torrent.files.model.TorrentFile;
import com.doge.torrent.files.model.TorrentPiece;

import java.util.List;
import java.util.Random;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;
import com.doge.torrent.logging.Logger;
import com.doge.torrent.logging.TorrentLoggerFactory;

public class TorrentDownloader {

	private static final Logger LOGGER = TorrentLoggerFactory.getLogger(TorrentDownloader.class);
	private static final String DEFAULT_PEER_ID = "DOGE-TORRENT";
	private static final int PEER_ID_INT_MIN_NUMBER = 1_000_000;
	private static final int PEER_ID_INT_MAX_NUMBER = 9_999_999;
	private final TorrentFileParser parser;
	private final ExecutorService executorService;
	private final Announcer announcer;
	private final String peerId;
	private List<Peer> peers;

	public TorrentDownloader(TorrentFileParser parser, Announcer announcer) {
		this.parser = parser;
		this.announcer = announcer;
		this.executorService = Executors.newVirtualThreadPerTaskExecutor();
		this.peerId = generatePeerId();
	}

	private String generatePeerId() {
		Random random = new Random();
		int peerIdInt = random.nextInt(PEER_ID_INT_MAX_NUMBER - PEER_ID_INT_MIN_NUMBER);
		peerIdInt += PEER_ID_INT_MIN_NUMBER;
		return DEFAULT_PEER_ID + "-" + peerIdInt;
	}

	public void download(String path) {
		TorrentFile file = parser.parseFromPath(path);
		AnnounceRequest request = AnnounceRequestBuilder.fromUrl(file.getAnnounceUrl())
			.infoHash(file.infoHash())
			.peerId(peerId)
			.left(file.info().length())
			.event(Event.STARTED)
			.build();

		AnnounceResponse response = announcer.announce(request);
		LOGGER.info("Announce response: " + response);

		peers = response.peers();
		LOGGER.info("Peers: " + peers);

		BlockingQueue<PieceProgress> finishedQueue = new LinkedBlockingQueue<>();
		BlockingQueue<TorrentPiece> pieceQueue = new LinkedBlockingQueue<>(file.info().pieces());

		TorrentSaver saver = new FileTorrentSaver(path + file.info().name());

		peers.forEach(peer -> runDownloadForPeer(finishedQueue, pieceQueue, file, peer));
		runDownloadedWorker(finishedQueue, saver, file, file.info().pieces().size());
		while (true) {
			if (finishedQueue.size() == file.info().pieces().size()) {
				executorService.shutdown();
				break;
			}
		}
	}

	private void runDownloadedWorker(BlockingQueue<PieceProgress> finishedQueue,
									 TorrentSaver saver,
									 TorrentFile file,
									 int pieceCount) {

		DownloadedWorker worker = new DownloadedWorker(finishedQueue,
									saver, file.info().pieceLength(), pieceCount);
		executorService.submit(worker);
		LOGGER.info("Started downloaded worker");

	}

	private void runDownloadForPeer(BlockingQueue<PieceProgress> finishedQueue,
									BlockingQueue<TorrentPiece> pieceQueue,
									TorrentFile file,
									Peer peer) {
		ClientConnector connector = new TCPClientConnector(file.infoHash(), peerId);
		ClientWorker worker = new ClientWorker(pieceQueue, finishedQueue, connector, peer);
		executorService.submit(worker);

	}
}
