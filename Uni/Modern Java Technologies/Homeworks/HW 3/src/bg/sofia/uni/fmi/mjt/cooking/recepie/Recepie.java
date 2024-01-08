package bg.sofia.uni.fmi.mjt.cooking.recepie;

import bg.sofia.uni.fmi.mjt.cooking.meal.MealType;

import java.util.List;

public record Recepie(
	String label,

	List<String> dietLabels,
	List<String> healthLabels,
	Integer totalWeight,
	List<String> cuisineType,
	List<MealType> mealType,
	List<String> dishType,
	List<String> ingredientLines
){

}
