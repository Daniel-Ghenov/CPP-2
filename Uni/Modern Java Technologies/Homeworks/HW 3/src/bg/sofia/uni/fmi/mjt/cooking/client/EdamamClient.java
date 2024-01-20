package bg.sofia.uni.fmi.mjt.cooking.client;

import bg.sofia.uni.fmi.mjt.cooking.client.model.ClientException;
import bg.sofia.uni.fmi.mjt.cooking.client.model.ClientExceptionParams;
import bg.sofia.uni.fmi.mjt.cooking.client.model.RecipeSearchParams;
import bg.sofia.uni.fmi.mjt.cooking.client.model.RecipeClientResponse;
import bg.sofia.uni.fmi.mjt.cooking.models.Recipe;
import com.google.gson.Gson;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

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

	private static final int MIN_SUCCESSFUL_STATUS_CODE = 200;

	private static final int MAX_SUCCESSFUL_STATUS_CODE = 299;

	public EdamamClient() {
		this(HttpClient.newHttpClient());
	}

	public EdamamClient(HttpClient httpClient) {
		this.httpClient = httpClient;
	}

	@Override
	public RecipeClientResponse getRecipes(RecipeSearchParams recepieSearchParams) {
		URI uri = recepieSearchParams.toUri(BASE_URL);

		HttpRequest request = HttpRequest.newBuilder()
				.uri(uri)
				.GET()
				.build();

		return getRecipeClientResponse(request);
	}

	@Override
	public RecipeClientResponse getRecipes(String nextPageToken) {
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
		JsonElement bodyJsonElement = JsonParser.parseString(body);
		JsonObject bodyJson = bodyJsonElement.getAsJsonObject();
		JsonElement error = bodyJson.get("errors").getAsJsonArray().get(0);
		return gson.fromJson(error, ClientExceptionParams.class);
	}

	private static boolean isSuccessful(int statusCode) {
		return statusCode >= MIN_SUCCESSFUL_STATUS_CODE && statusCode <= MAX_SUCCESSFUL_STATUS_CODE;
	}

	private RecipeClientResponse parseResponse(String body) {
		Gson gson = new Gson();
		JsonElement bodyJsonElement = JsonParser.parseString(body);
		JsonObject bodyJson = bodyJsonElement.getAsJsonObject();
		JsonElement nextPageTokenElement = bodyJson.get("_links").getAsJsonObject().get("next");
		String nextPageToken = null;
		if (nextPageTokenElement != null) {
		 	nextPageToken = nextPageTokenElement.getAsJsonObject().get("href").getAsString();
		}
		List<Recipe> recipes = bodyJson.get("hits").getAsJsonArray().asList().stream()
									   .map(JsonElement::getAsJsonObject)
									   .map(jsonObject -> jsonObject.get("recipe").getAsJsonObject())
									   .map(recipeJson -> gson.fromJson(recipeJson, Recipe.class))
									   .toList();
		return new RecipeClientResponse(recipes, nextPageToken);
	}

}
