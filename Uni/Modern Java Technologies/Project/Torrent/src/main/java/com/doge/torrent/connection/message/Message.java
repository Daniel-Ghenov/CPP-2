package com.doge.torrent.connection.message;

import java.nio.ByteBuffer;

import static com.doge.torrent.utils.ByteUtils.toByte;

public record Message(
	MessageId id,
	byte[] payload
) {
	private static final int MESSAGE_LENGTH_SIZE = 4;
	private static final int MESSAGE_ID_SIZE = 1;

	public byte[] toBytes() {
		int length = payload.length + MESSAGE_ID_SIZE;
		byte[] bytes = new byte[length + MESSAGE_LENGTH_SIZE];
		ByteBuffer.wrap(bytes).putInt(length);
		bytes[MESSAGE_LENGTH_SIZE] = toByte(id.getId());
		System.arraycopy(payload, 0, bytes, MESSAGE_LENGTH_SIZE + MESSAGE_ID_SIZE, payload.length);

		return bytes;
	}

	public static Message fromBytes(byte[] bytes) {
		int length = ByteBuffer.wrap(bytes).getInt();

		if (length == 0) {
			return new Message(MessageId.KEEP_ALIVE, new byte[0]);
		}

		byte id = bytes[MESSAGE_LENGTH_SIZE];
		byte[] payload = new byte[length - MESSAGE_ID_SIZE];
		System.arraycopy(bytes, MESSAGE_LENGTH_SIZE + MESSAGE_ID_SIZE, payload, 0, payload.length);
		return new Message(MessageId.fromId(id), payload);
	}

	public boolean isKeepAlive() {
		return id == MessageId.KEEP_ALIVE;
	}

}
