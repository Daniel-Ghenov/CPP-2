package com.doge.torrent.files.bencode;

import com.doge.torrent.files.bencode.exception.BencodeException;
import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class BencodeTest {


	@Test
	void testGetTypeWhenNextTypeNumber() {
		String input = "i123e";

		Bencode bencode = new Bencode();
		BencodeType<?> type = bencode.getType(input.getBytes());

		assertEquals(BencodeType.bencodeNumber, type);
	}

	@Test
	void testGetTypeWhenNextTypeString() {
		String input = "4:spam";

		Bencode bencode = new Bencode();
		BencodeType<?> type = bencode.getType(input.getBytes());

		assertEquals(BencodeType.bencodeString, type);
	}

	@Test
	void testGetTypeWhenNextTypeList() {
		String input = "l4:spam4:eggse";

		Bencode bencode = new Bencode();
		BencodeType<?> type = bencode.getType(input.getBytes());

		assertEquals(BencodeType.bencodeList, type);
	}

	@Test
	void testGetTypeWhenNextTypeDictionary() {
		String input = "d3:cow3:moo4:spam4:eggse";

		Bencode bencode = new Bencode();
		BencodeType<?> type = bencode.getType(input.getBytes());

		assertEquals(BencodeType.bencodeDictionary, type);
	}

	@Test
	void testGetTypeWhenNextTypeUnknown() {
		String input = "x";

		Bencode bencode = new Bencode();
		BencodeType<?> type = bencode.getType(input.getBytes());

		assertEquals(BencodeType.bencodeUnknown, type);
	}

	@Test
	void testDecodeWhenTypeNullShouldThrow() {
		String input = "i123e";

		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.decode(input, null));
	}

	@Test
	void testDecodeWhenTypeUnknownShouldThrow() {
		String input = "i123e";

		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.decode(input, BencodeType.bencodeUnknown));
	}

	@Test
	void testDecodeWhenBencodeNullShouldThrow() {
		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.decode((String) null, BencodeType.bencodeNumber));
	}

	@Test
	void testDecodeWhenTypeNullAndByteArrShouldThrow() {
		byte[] input = "i123e".getBytes();

		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.decode(input, null));
	}

	@Test
	void testDecodeWhenTypeUnknownAndByteArrShouldThrow() {
		byte[] input = "i123e".getBytes();

		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.decode(input, BencodeType.bencodeUnknown));
	}

	@Test
	void testDecodeWhenBencodeNullAndByteArrShouldThrow() {
		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.decode((byte[]) null, BencodeType.bencodeNumber));
	}

	@Test
	void testDecodeWhenTypeNumberAndPositive() {
		String input = "i123e";

		Bencode bencode = new Bencode();
		Long num = bencode.decode(input, BencodeType.bencodeNumber);

		assertEquals(123L, num);
	}

	@Test
	void testDecodeWhenTypeNumberAndZero() {
		String input = "i0e";

		Bencode bencode = new Bencode();
		Long num = bencode.decode(input, BencodeType.bencodeNumber);

		assertEquals(0L, num);
	}

	@Test
	void testDecodeWhenTypeNumberAndNegative() {
		String input = "i-250e";

		Bencode bencode = new Bencode();
		Long num = bencode.decode(input, BencodeType.bencodeNumber);

		assertEquals(-250L, num);
	}

	@Test
	void testDecodeWhenTypeString() {
		String input = "4:spam";

		Bencode bencode = new Bencode();
		String str = bencode.decode(input, BencodeType.bencodeString);

		assertEquals("spam", str);
	}

	@Test
	void testDecodeWhenTypeList() {
		String input = "l4:spam4:eggse";

		Bencode bencode = new Bencode();
		List<Object> list = bencode.decode(input, BencodeType.bencodeList);

		assertIterableEquals(List.of("spam", "eggs"), list);
	}

	@Test
	void testDecodeWhenTypeDictionary() {
		String input = "d3:cow3:moo4:spam4:eggse";

		Bencode bencode = new Bencode();
		Map<String, Object> list = bencode.decode(input, BencodeType.bencodeDictionary);

		assertEquals(Map.of("cow", "moo", "spam", "eggs"), list);
	}

	@Test
	void testEncodeLongWhenNullShouldThrow() {
		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.encode((Long) null));
	}

	@Test
	void testEncodeStringWhenNullShouldThrow() {
		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.encode((String) null));
	}

	@Test
	void testEncodeListWhenNullShouldThrow() {
		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.encode((List<?>) null));
	}

	@Test
	void testEncodeMapWhenNullShouldThrow() {
		Bencode bencode = new Bencode();
		assertThrows(BencodeException.class, () -> bencode.encode((Map<?, ?>) null));
	}

	@Test
	void testEncodeLong() {
		Bencode bencode = new Bencode();
		byte[] encoded = bencode.encode(123L);

		assertEquals("i123e", new String(encoded));
	}

	@Test
	void testEncodeString() {
		Bencode bencode = new Bencode();
		byte[] encoded = bencode.encode("spam");

		assertEquals("4:spam", new String(encoded));
	}

	@Test
	void testEncodeList() {
		Bencode bencode = new Bencode();
		byte[] encoded = bencode.encode(List.of("spam", "eggs"));

		assertEquals("l4:spam4:eggse", new String(encoded));
	}

	@Test
	void testEncodeMap() {
		Bencode bencode = new Bencode();
		byte[] encoded = bencode.encode(Map.of("cow", "moo", "spam", "eggs"));

		assertEquals("d3:cow3:moo4:spam4:eggse", new String(encoded));
	}

}