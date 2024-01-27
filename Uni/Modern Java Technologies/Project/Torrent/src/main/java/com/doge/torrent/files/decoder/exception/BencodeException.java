package com.doge.torrent.files.decoder.exception;

public class BencodeException extends RuntimeException {

	public BencodeException(String message) {
		super(message);
	}

	public BencodeException(Throwable cause) {
		super(cause);
	}

}
