package bg.sofia.uni.fmi.mjt.udemy;

import bg.sofia.uni.fmi.mjt.udemy.account.Account;
import bg.sofia.uni.fmi.mjt.udemy.course.Category;
import bg.sofia.uni.fmi.mjt.udemy.course.Course;
import bg.sofia.uni.fmi.mjt.udemy.exception.AccountNotFoundException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotFoundException;

public class Udemy implements LearningPlatform
{

	private Course[] courses;
	private Account[] accounts;

	public Udemy(Account[] accounts, Course[] courses){
		this.accounts = accounts;
		this.courses = courses;
	}

	@Override public Course findByName(String name) throws CourseNotFoundException
	{
		if(name == null || name.isEmpty()){
			throw new IllegalArgumentException("Name cannot be null or empty");
		}

		for (Course course : courses)
		{
			if (course.getName().equals(name))
			{
				return course;
			}
		}
		throw new CourseNotFoundException("Course not found");
	}

	@Override public Course[] findByKeyword(String keyword)
	{
		if(keyword == null || keyword.isEmpty() || !keyword.matches("[a-zA-Z]+")){
			throw new IllegalArgumentException("Keyword cannot be null or empty");
		}

		int len = 0;
		for(Course course : courses){
			if(course.getName().contains(keyword) || course.getDescription().contains(keyword)){
				len++;
			}
		}
		Course[] result = new Course[len];
		int index = 0;
		for(Course course : courses){
			if(course.getName().contains(keyword) || course.getDescription().contains(keyword)){
				result[index++] = course;
			}
		}
		return result;
	}

	@Override public Course[] getAllCoursesByCategory(Category category)
	{
		if(category == null){
			throw new IllegalArgumentException("Category cannot be null");
		}

		int len = 0;
		for(Course course : courses){
			if(course.getCategory().equals(category)){
				len++;
			}
		}
		Course[] result = new Course[len];
		int index = 0;
		for(Course course : courses){
			if(course.getCategory().equals(category)){
				result[index++] = course;
			}
		}
		return result;
	}

	@Override public Account getAccount(String name) throws AccountNotFoundException
	{
		if (name == null || name.isEmpty())
		{
			throw new IllegalArgumentException("Name cannot be null or empty");
		}

		for (Account account : accounts)
		{
			if (account.getUsername().equals(name))
			{
				return account;
			}
		}
		throw new AccountNotFoundException("Account not found");
	}

	@Override public Course getLongestCourse()
	{
		int minLongDuration = 0;
		Course longestCourse = null;
		for (Course course : courses)
		{
			int length = course.getTotalTime().hours() * 60 + course.getTotalTime().minutes();
			if (length > minLongDuration)
			{
				minLongDuration = length;
				longestCourse = course;
			}
		}
		return longestCourse;
	}

	@Override public Course getCheapestByCategory(Category category)
	{
		double minPrice = Double.MAX_VALUE;
		Course cheapestCourse = null;
		for (Course course : courses)
		{
			if (course.getCategory().equals(category) && course.getPrice() < minPrice)
			{
				minPrice = course.getPrice();
				cheapestCourse = course;
			}
		}
		return cheapestCourse;
	}
}
