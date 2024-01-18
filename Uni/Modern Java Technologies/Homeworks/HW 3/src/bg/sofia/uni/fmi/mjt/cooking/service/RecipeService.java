package bg.sofia.uni.fmi.mjt.cooking.service;

import bg.sofia.uni.fmi.mjt.cooking.client.EdamamClient;
import bg.sofia.uni.fmi.mjt.cooking.client.RecipeClient;
import bg.sofia.uni.fmi.mjt.cooking.client.model.ClientException;
import bg.sofia.uni.fmi.mjt.cooking.client.model.RecipeClientResponse;
import bg.sofia.uni.fmi.mjt.cooking.models.MealType;
import bg.sofia.uni.fmi.mjt.cooking.models.Recipe;
import com.google.gson.Gson;

import java.util.ArrayList;
import java.util.List;

public class RecipeService {

	private final RecipeClient recipeClient;

	public RecipeService() {
		this(new EdamamClient());
	}

	public RecipeService(RecipeClient recipeClient) {
		this.recipeClient = recipeClient;
	}

	public List<Recipe> getRecipes(List<String> keywords,
								   List<MealType> mealType,
								   List<String> healthRequest,
								   Integer pageCount) {
		try {
			RecipeClientResponse response = recipeClient.getRecipes(keywords, mealType, healthRequest);
			List<Recipe> recipes = new ArrayList<>(response.recipes());
			String nextPageToken = response.nextPageToken();
			for (int i = 1; i < pageCount; i++) {
				if (nextPageToken == null) {
					break;
				}
				response = recipeClient.getRecipes(nextPageToken);
				recipes.addAll(response.recipes());
				nextPageToken = response.nextPageToken();
			}
			return recipes;
		} catch (ClientException e) {
			Gson gson = new Gson();
			System.out.println(e.getMessage());
			System.out.println(e.getErrorCode());
			System.out.println(e.getParams());
			throw new RuntimeException(e);
		}
	}

}
