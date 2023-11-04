package bg.sofia.uni.fmi.mjt.udemy.course;

import bg.sofia.uni.fmi.mjt.udemy.course.duration.CourseDuration;
import bg.sofia.uni.fmi.mjt.udemy.exception.ResourceNotFoundException;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.Objects;

public class Course implements Completable,	 Purchasable
{

	private String name;
	private String description;
	private double price;
	private Resource[] content;
	private Category category;
	private CourseDuration totalTime;
	private boolean purchased = false;

	private double grade;

	public Course(String name, String description, double price, Resource[] content, Category category)
	{
		this.name = name;
		this.description = description;
		this.price = price;
		this.content = content;
		this.category = category;
		totalTime = CourseDuration.of(content);

	}

	public boolean containsResource(Resource resource)
	{
		for (Resource r : content)
		{
			if(r == null){
				continue;
			}
			if (r.equals(resource))
			{
				return true;
			}
		}
		return false;
	}

	/**
	 * Completes a resource from the course.
	 *
	 * @param resourceToComplete the resource which will be completed.
	 * @throws IllegalArgumentException if resourceToComplete is null.
	 * @throws ResourceNotFoundException if the resource could not be found in the course.
	 */
	public void completeResource(Resource resourceToComplete) throws ResourceNotFoundException
	{
		if(resourceToComplete == null){
			throw new IllegalArgumentException();
		}

		boolean found = false;
		for(Resource r : content){
			if(r == null){
				continue;
			}
			if(r.equals(resourceToComplete)){
				found = true;
				r.complete();
				break;
			}
		}

		if(!found){
			throw new ResourceNotFoundException("Resource not found");
		}
	}

	@Override public boolean isCompleted()
	{
		return getCompletionPercentage() == 100;
	}

	@Override public int getCompletionPercentage()
	{
		if(content.length == 0){
			return 100;
		}

		int complete = 0;
		for (Resource r: content)
		{
			if(r.isCompleted()){
				complete++;
			}
		}
		return BigDecimal.valueOf(complete * 100.0 / content.length).setScale(1, RoundingMode.CEILING).intValue();
	}

	@Override public void purchase()
	{
		purchased = true;
	}

	@Override public boolean isPurchased()
	{
		return purchased;
	}

	/**
	 * Returns the name of the course.
	 */
	public String getName() {
		return name;
	}

	/**
	 * Returns the description of the course.
	 */
	public String getDescription() {
		return description;
	}

	/**
	 * Returns the price of the course.
	 */
	public double getPrice() {
		return price;
	}

	/**
	 * Returns the category of the course.
	 */
	public Category getCategory() {
		return category;
	}

	/**
	 * Returns the content of the course.
	 */
	public Resource[] getContent() {
		return content;
	}

	/**
	 * Returns the total duration of the course.
	 */
	public CourseDuration getTotalTime() {
		return totalTime;
	}


	@Override public boolean equals(Object o)
	{
		if (this == o)
		{
			return true;
		}
		if (o == null || getClass() != o.getClass())
		{
			return false;
		}
		Course course = (Course) o;
		return Double.compare(price, course.price) == 0 && purchased == course.purchased && Objects.equals(name, course.name) && Objects.equals(description, course.description) && Arrays.equals(content, course.content) && category == course.category && Objects.equals(totalTime, course.totalTime);
	}

	@Override public int hashCode()
	{
		int result = Objects.hash(name, description, price, category, totalTime, purchased);
		result = 31 * result + Arrays.hashCode(content);
		return result;
	}

	public double getGrade()
	{
		return grade;
	}

	public void setGrade(double grade)
	{
		this.grade = grade;
	}
}
