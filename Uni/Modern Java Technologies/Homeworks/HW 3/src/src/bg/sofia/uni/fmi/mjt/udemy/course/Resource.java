package bg.sofia.uni.fmi.mjt.udemy.course;

import bg.sofia.uni.fmi.mjt.udemy.course.duration.ResourceDuration;

public class Resource implements Completable
{

	private String name;
	private ResourceDuration duration;

	private int completionPercentage = 0;
	public Resource(String name, ResourceDuration duration){
		this.name = name;
		this.duration = duration;
	}
	/**
	 * Returns the resource name.
	 */
	public String getName() {
		return name;
	}

	/**
	 * Returns the total duration of the resource.
	 */
	public ResourceDuration getDuration() {
		return duration;
	}

	/**
	 * Marks the resource as completed.
	 */
	public void complete() {
		completionPercentage = 100;
	}

	@Override public boolean isCompleted()
	{
		return completionPercentage == 100;
	}

	@Override public int getCompletionPercentage()
	{
		return completionPercentage;
	}
}
