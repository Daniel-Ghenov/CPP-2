package bg.sofia.uni.fmi.mjt.space.exception;

public class TimeFrameMismatchException extends RuntimeException {

	public TimeFrameMismatchException() {
		super();
	}

	public TimeFrameMismatchException(String message) {
		super(message);
	}

	public TimeFrameMismatchException(String message, Throwable cause) {
		super(message, cause);
	}
}
