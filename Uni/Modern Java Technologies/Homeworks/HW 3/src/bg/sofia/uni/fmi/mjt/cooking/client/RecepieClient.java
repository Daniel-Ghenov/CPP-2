package bg.sofia.uni.fmi.mjt.cooking.client;

import bg.sofia.uni.fmi.mjt.cooking.meal.MealType;
import bg.sofia.uni.fmi.mjt.cooking.response.Response;

import java.util.List;

public interface RecepieClient {
	List<Response> getRecepies(List<String> keywords, MealType mealType, String healthRequest);

	List<Response> getRecepies(String nextPageToken);

}
