package com.doge.torrent.connection.message;

public record BitField(
		byte[] bitField
) {

	public static final int BYTE_LENGTH = 8;

	public boolean hasPiece(int piece) {
		int bytePos = piece / BYTE_LENGTH;
		int bitPos = piece % BYTE_LENGTH;
		return (bitField[bytePos] & (1 << bitPos)) > 0;
	}

	public void setPiece(int piece) {
		int bytePos = piece / BYTE_LENGTH;
		int bitPos = piece % BYTE_LENGTH;
		bitField[bytePos] |= (byte) (1 << bitPos);
	}

	public static BitField fromMessage(Message message) {
		if (message.id() != MessageId.BITFIELD) {
			throw new IllegalArgumentException("Message is not a bitfield");
		}

		return new BitField(message.payload());
	}

}
