package bg.sofia.uni.fmi.mjt.cooking.client;

import bg.sofia.uni.fmi.mjt.cooking.client.model.RecipeClientResponse;
import bg.sofia.uni.fmi.mjt.cooking.models.MealType;

import java.util.List;

public interface RecipeClient {

	RecipeClientResponse getRecipes(List<String> keywords, List<MealType> mealType, List<String> healthRequest);

	RecipeClientResponse getRecipes(String nextPageToken);

}
