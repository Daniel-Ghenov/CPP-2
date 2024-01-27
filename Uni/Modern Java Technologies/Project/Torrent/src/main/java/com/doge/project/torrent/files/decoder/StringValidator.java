package com.doge.project.torrent.files.decoder;

import static java.lang.Character.isDigit;

public class StringValidator implements Validator {

	@Override public boolean validate(char c) {
		return isDigit(c);
	}
}
