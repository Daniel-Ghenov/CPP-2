package bg.sofia.uni.fmi.mjt.cooking.client;

import bg.sofia.uni.fmi.mjt.cooking.client.model.ClientException;
import bg.sofia.uni.fmi.mjt.cooking.client.model.ClientExceptionParams;
import bg.sofia.uni.fmi.mjt.cooking.client.model.EdamamClientResponseDTO;
import bg.sofia.uni.fmi.mjt.cooking.client.model.RecipeClientResponse;
import bg.sofia.uni.fmi.mjt.cooking.models.MealType;
import com.google.gson.Gson;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.List;


public class EdamamClient implements RecipeClient {

	private final HttpClient httpClient;

	private static final String APP_ID = "app_id=" + System.getenv("APP_ID");

	private static final String APP_KEY = "app_key=" + System.getenv("APP_KEY");

	private static final String BASE_URL = "https://api.edamam.com/api/recipes/v2?type=public&"
										   + APP_ID + "&" + APP_KEY;

	private static final int MIN_SUCCESFUL_STATUS_CODE = 200;

	private static final int MAX_SUCCESFUL_STATUS_CODE = 299;

	public EdamamClient() {
		this(HttpClient.newHttpClient());
	}

	public EdamamClient(HttpClient httpClient) {
		this.httpClient = httpClient;
	}

	@Override public RecipeClientResponse getRecipes(List<String> keywords, List<MealType> mealType, List<String> healthRequest) {
		URI uri = getUri(keywords, mealType, healthRequest);

		HttpRequest request = HttpRequest.newBuilder()
				.uri(uri)
				.GET()
				.build();

		return getRecipeClientResponse(request);
	}

	private static URI getUri(List<String> keywords, List<MealType> mealType, List<String> healthRequest) {

		if (keywords == null || keywords.isEmpty()) {
			throw new IllegalArgumentException("Keywords cannot be empty");
		}

		StringBuilder uriStringBuilder = new StringBuilder(BASE_URL)
				.append("&q=")
				.append(String.join(",", keywords));
		if (!mealType.isEmpty()) {
			uriStringBuilder
				.append("&mealType=")
				.append(String.join("&mealType=", mealType.stream().map(Enum::name).toList()));
		}
		if (!healthRequest.isEmpty()) {
			uriStringBuilder
				.append("&health=")
				.append(String.join("&health=", healthRequest));
		}

		return URI.create(uriStringBuilder.toString());
	}

	@Override public RecipeClientResponse getRecipes(String nextPageToken) {
		HttpRequest request = HttpRequest.newBuilder()
				.uri(URI.create(nextPageToken))
				.GET()
				.build();

		return getRecipeClientResponse(request);
	}

	private RecipeClientResponse getRecipeClientResponse(HttpRequest request) {
		try {
			HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());
			if (!isSuccessful(response.statusCode())) {
				throw new ClientException(parseError(response.body()));
			}
			return parseResponse(response.body());
		} catch (IOException | InterruptedException e) {
			throw new RuntimeException(e);
		}
	}

	private ClientExceptionParams parseError(String body) {
		Gson gson = new Gson();
		return gson.fromJson(body, ClientExceptionParams.class);
	}

	private static boolean isSuccessful(int statusCode) {
		return statusCode >= MIN_SUCCESFUL_STATUS_CODE && statusCode <= MAX_SUCCESFUL_STATUS_CODE;
	}

	private RecipeClientResponse parseResponse(String response) {
		Gson gson = new Gson();
		EdamamClientResponseDTO dto = gson.fromJson(response, EdamamClientResponseDTO.class);
		return dto.toRecipeClientResponse();
	}
}
