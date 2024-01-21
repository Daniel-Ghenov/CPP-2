package bg.sofia.uni.fmi.mjt.cooking.client;

import bg.sofia.uni.fmi.mjt.cooking.client.model.RecipeClientResponse;
import bg.sofia.uni.fmi.mjt.cooking.client.util.HttpResponseStub;
import com.google.gson.Gson;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrowsExactly;
import static org.junit.jupiter.api.Assertions.fail;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class EdamamClientTest
{

	private static final String BASE_URL = "https://api.edamam.com/api/recipes/v2?type=public&app_id=&app_key=";
	@Test
	void testGetRecipesWithoutKeywords()
	{
		RecipeClient client = new EdamamClient();
		assertThrowsExactly(IllegalArgumentException.class, () -> client.getRecipes(null, List.of(), List.of()));

	}

	@Test
	void testGetRecepiesWithOnlyKeywords()
	{
		URI uri = URI.create(BASE_URL + "&q=chicken");
		HttpRequest request = HttpRequest.newBuilder()
				.uri(uri)
				.GET()
				.build();
		HttpClient client = mock(HttpClient.class);

		RecipeClientResponse response = new RecipeClientResponse(List.of(), null);

		Gson gson = new Gson();
		String responseString = gson.toJson(response);

		try
		{
			when(client.send(request, HttpResponse.BodyHandlers.ofString())).thenReturn(new HttpResponseStub<>(200, responseString));
			assertEquals(response, new EdamamClient(client).getRecipes(List.of("chicken"), List.of(), List.of()));
		}
		catch (IOException | InterruptedException e)
		{
			fail("Unexpected exception occured" + e.getMessage());
		}
	}

}
