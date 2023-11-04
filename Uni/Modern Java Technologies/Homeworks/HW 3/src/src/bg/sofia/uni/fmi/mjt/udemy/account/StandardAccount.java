package bg.sofia.uni.fmi.mjt.udemy.account;

import bg.sofia.uni.fmi.mjt.udemy.course.Category;
import bg.sofia.uni.fmi.mjt.udemy.course.Course;
import bg.sofia.uni.fmi.mjt.udemy.course.Resource;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseAlreadyPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotCompletedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.InsufficientBalanceException;
import bg.sofia.uni.fmi.mjt.udemy.exception.MaxCourseCapacityReachedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.ResourceNotFoundException;

public class StandardAccount extends AccountBase
{

	public StandardAccount(String username, double balance)
	{
		super(username, balance);
	}

	@Override public void completeCourse(Course course, double grade) throws CourseNotPurchasedException, CourseNotCompletedException
	{
		if(course == null ){
			throw new IllegalArgumentException("Course cannot be null");
		}
		if( grade < 2.00 || grade > 6.00){
			throw new IllegalArgumentException("Grade must be in range [2.00, 6.00]");
		}

		Course purchasedCourse = getCourse(course);
		if(purchasedCourse == null){
			throw new CourseNotPurchasedException("Course not purchased");
		}

		for(Resource r : purchasedCourse.getContent()){
			if(!r.isCompleted()){
				throw new CourseNotCompletedException("Course not completed");
			}
		}

		purchasedCourse.setGrade(grade);
	}

	@Override public void completeResourcesFromCourse(Course course, Resource[] resourcesToComplete) throws CourseNotPurchasedException, ResourceNotFoundException
	{
		if(course == null || resourcesToComplete == null){
			throw new IllegalArgumentException("Course and resources cannot be null");
		}

		Course purchasedCourse = getCourse(course);
		if(purchasedCourse == null){
			throw new CourseNotPurchasedException("Course not purchased");
		}

		for(Resource r : resourcesToComplete){
			if(!purchasedCourse.containsResource(r)){
				throw new ResourceNotFoundException("Resource not found");
			}
			r.complete();
		}
	}

	@Override public void buyCourse(Course course) throws InsufficientBalanceException, CourseAlreadyPurchasedException, MaxCourseCapacityReachedException
	{
		if(course == null){
			throw new IllegalArgumentException("Course cannot be null");
		}

		if(course.getPrice() > getBalance()){
			throw new InsufficientBalanceException("Insufficient balance");
		}
		for(Course c : purchasedCourses){
			if(c == null){
				continue;
			}
			if(c.equals(course)){
				throw new CourseAlreadyPurchasedException("Course already purchased");
			}
		}


		removeFromBalance(course.getPrice());
		boolean bought = false;
		for (int i = 0; i < purchasedCourses.length; i++)
		{
			if(purchasedCourses[i] == null){
				purchasedCourses[i] = course;
				bought = true;
				break;
			}
		}
		if(!bought){
			throw new MaxCourseCapacityReachedException("Max course capacity reached");
		}
	}
}
