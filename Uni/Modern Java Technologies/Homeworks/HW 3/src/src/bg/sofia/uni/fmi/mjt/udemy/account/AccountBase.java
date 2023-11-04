package bg.sofia.uni.fmi.mjt.udemy.account;

import bg.sofia.uni.fmi.mjt.udemy.course.Course;
import bg.sofia.uni.fmi.mjt.udemy.course.Resource;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseAlreadyPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotCompletedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.InsufficientBalanceException;
import bg.sofia.uni.fmi.mjt.udemy.exception.MaxCourseCapacityReachedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.ResourceNotFoundException;

public abstract class AccountBase implements Account
{
	private static final int MAX_COURSES = 100;
	public String username;
	private double balance;
	protected Course[] purchasedCourses;


	public AccountBase(String username, double balance){
		this.username = username;
		this.balance = balance;
		purchasedCourses = new Course[MAX_COURSES];
	}

	@Override public String getUsername()
	{
		return username;
	}

	protected void removeFromBalance(double ammount){
		balance -= ammount;
	}
	@Override public void addToBalance(double amount)
	{
		if(amount < 0){
			throw new IllegalArgumentException("Amount cannot be negative");
		}
		balance += amount;
	}
	@Override public double getBalance()
	{
		return balance;
	}

	@Override public Course getLeastCompletedCourse()
	{
		int minCompleted = Integer.MAX_VALUE;
		Course leastCompleted = null;
		for(Course c : purchasedCourses){
			if(c != null){
				int completed = c.getCompletionPercentage();
				if(completed < minCompleted){
					minCompleted = completed;
					leastCompleted = c;
				}
			}
		}
		return leastCompleted;
	}

	@Override public abstract void completeCourse(Course course, double grade) throws CourseNotPurchasedException, CourseNotCompletedException;

	@Override public abstract void completeResourcesFromCourse(Course course, Resource[] resourcesToComplete) throws CourseNotPurchasedException, ResourceNotFoundException;

	@Override public abstract void buyCourse(Course course) throws InsufficientBalanceException, CourseAlreadyPurchasedException, MaxCourseCapacityReachedException;



	protected Course getCourse(Course course){
		if(course == null){
			throw new IllegalArgumentException("Course cannot be null");
		}

		for(Course c : purchasedCourses){
			if(c == null){
				continue;
			}
			if(c.equals(course)){
				return c;
			}
		}
		return null;
	}
}
