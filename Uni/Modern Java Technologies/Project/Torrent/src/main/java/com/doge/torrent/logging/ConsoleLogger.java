package com.doge.torrent.logging;

import java.time.LocalDateTime;

public class ConsoleLogger implements Logger {

	private final Level level;

	private final String name;

	public ConsoleLogger(String name) {
		this(Level.INFO, name);
	}

	public ConsoleLogger(Level level, String name) {
		this.level = level;
		this.name = name;
	}

	@Override
	public void debug(String message) {
		if (!isDebugEnabled()) {
			return;
		}
		log(message, Level.DEBUG);
	}

	@Override
	public void info(String message) {
		if (!isInfoEnabled()) {
			return;
		}
		log(message, Level.INFO);
	}

	@Override
	public void error(String message) {
		if (!isErrorEnabled()) {
			return;
		}
		log(message, Level.ERROR);
	}

	@Override
	public void error(String message, Throwable throwable) {
		if (!isErrorEnabled()) {
			return;
		}
		log(message, Level.ERROR);
		throwable.printStackTrace();
	}

	@Override
	public void warn(String message) {
		if (!isWarnEnabled()) {
			return;
		}
		log(message, Level.WARN);
	}

	@Override
	public void warn(String message, Throwable throwable) {
		if (!isWarnEnabled()) {
			return;
		}
		log(message, Level.WARN);
		throwable.printStackTrace();
	}

	@Override
	public void trace(String message) {
		if (!isTraceEnabled()) {
			return;
		}
		log(message, Level.TRACE);
	}

	@Override
	public void trace(String message, Throwable throwable) {
		if (!isTraceEnabled()) {
			return;
		}
		log(message, Level.TRACE);
		throwable.printStackTrace();
	}

	private void log(String message, Level level) {
		LocalDateTime now = LocalDateTime.now();
		String newMessage = String.format("%s [%s] %s: %s", now, name, level.name(), message);
		System.out.println(newMessage);
	}

	@Override
	public boolean isDebugEnabled() {
		return this.level.getLevel() >= Level.DEBUG.getLevel();
	}

	@Override
	public boolean isInfoEnabled() {
		return this.level.getLevel() >= Level.INFO.getLevel();
	}

	@Override
	public boolean isErrorEnabled() {
		return this.level.getLevel() >= Level.ERROR.getLevel();
	}

	@Override
	public boolean isWarnEnabled() {
		return this.level.getLevel() >= Level.WARN.getLevel();
	}

	@Override
	public boolean isTraceEnabled() {
		return this.level.getLevel() >= Level.TRACE.getLevel();
	}
}
