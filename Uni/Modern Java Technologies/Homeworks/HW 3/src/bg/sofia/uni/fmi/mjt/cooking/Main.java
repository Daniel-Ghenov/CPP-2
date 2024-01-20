package bg.sofia.uni.fmi.mjt.cooking;

import bg.sofia.uni.fmi.mjt.cooking.client.EdamamClient;
import bg.sofia.uni.fmi.mjt.cooking.models.Recipe;
import bg.sofia.uni.fmi.mjt.cooking.service.RecipeService;
import com.google.gson.Gson;

import java.util.List;

public class Main {

	public static void main(String[] args) {
		RecipeService service = new RecipeService(new EdamamClient());
		List<String> keywords = List.of("pizza", "pesto");
		List<Recipe> recipes = service.getRecipes(keywords, List.of("Dinner"), List.of("vegan"), 2);

		recipes.stream()
				.forEach(recipe -> System.out.println(new Gson().toJson(recipe)));
	}

}
