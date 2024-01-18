package bg.sofia.uni.fmi.mjt.cooking.client.model;

import java.util.List;

public record ClientExceptionParams(

		String message,
		String errorCode,

		List<String> params
)
{

}
