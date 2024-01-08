package bg.sofia.uni.fmi.mjt.cooking.client;

import bg.sofia.uni.fmi.mjt.cooking.meal.MealType;
import bg.sofia.uni.fmi.mjt.cooking.response.Response;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.List;

public class EdamamClient implements RecepieClient {

	private final HttpClient httpClient;

	private static final String APP_ID = "app_id=" + System.getenv("APP_ID");

	private static final String APP_KEY = "app_key=" + System.getenv("APP_KEY");

	private static final String BASE_URL = "https://api.edamam.com/api/recipes/v2?type=public&"
										   + APP_ID + "&" + APP_KEY;

	public EdamamClient() {
		this(HttpClient.newHttpClient());
	}

	public EdamamClient(HttpClient httpClient) {
		this.httpClient = httpClient;
	}

	@Override public List<Response> getRecepies(List<String> keywords, MealType mealType, String healthRequest) {
		HttpRequest request = HttpRequest.newBuilder()
				.GET()
				.build();
		return null;
	}

	@Override public List<Response> getRecepies(String nextPageToken) {
		HttpRequest request = HttpRequest.newBuilder()
				.uri(URI.create(nextPageToken))
				.GET()
				.build();

		try {
			HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());
		} catch (IOException | InterruptedException e) {
			throw new RuntimeException(e);
		}
		return null;
	}
}
