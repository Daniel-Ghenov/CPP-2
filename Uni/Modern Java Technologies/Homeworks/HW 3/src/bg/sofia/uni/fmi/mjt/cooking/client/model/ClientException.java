package bg.sofia.uni.fmi.mjt.cooking.client.model;

import java.util.List;

public class ClientException extends RuntimeException {

	private String errorCode;

	private List<String> params;

	public ClientException( String errorCode, List<String> params) {
		this.errorCode = errorCode;
		this.params = params;
	}

	public ClientException( ClientExceptionParams params) {
		super(params.message());
		this.errorCode = params.errorCode();
		this.params = params.params();
	}

	public String getErrorCode() {
		return errorCode;
	}

	public List<String> getParams() {
		return params;
	}
}
