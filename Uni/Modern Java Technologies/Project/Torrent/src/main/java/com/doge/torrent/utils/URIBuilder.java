package com.doge.torrent.utils;

import java.net.URI;

public class URIBuilder {

	private final StringBuilder builder;

	private URIBuilder(String url) {
		this.builder = new StringBuilder(url);
	}

	public static URIBuilder fromURL(String url) {
		return new URIBuilder(url);
	}

	public URIBuilder queryParam(String key, Iterable<?> values) {
		for (Object value : values) {
			queryParam(key, value);
		}
		return this;
	}

	public URIBuilder queryParam(String key, Object value) {
		if (builder.indexOf("?") == -1) {
			builder.append("?");
		} else {
			builder.append("&");
		}
		builder.append(key).append("=").append(value);
		return this;
	}

	public String build() {
		return builder.toString();
	}

	public URI buildURI() {
		return URI.create(build());
	}

}
