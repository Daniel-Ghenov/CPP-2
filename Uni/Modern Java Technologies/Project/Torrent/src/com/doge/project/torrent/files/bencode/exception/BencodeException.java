package com.doge.project.torrent.files.bencode.exception;

public class BencodeException extends RuntimeException {

	public BencodeException(String message) {
		super(message);
	}

	public BencodeException(Throwable cause) {
		super(cause);
	}

}
