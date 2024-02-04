package com.doge.torrent.announce.model;

public enum Event {

	STARTED("started"),
	STOPPED("stopped"),
	COMPLETED("completed");

	private final String value;

	Event(String value) {
		this.value = value;
	}

	public String value() {
		return value;
	}
}
