package bg.sofia.uni.fmi.mjt.udemy.course.duration;

import bg.sofia.uni.fmi.mjt.udemy.course.Resource;

public record ResourceDuration(int minutes)
{

	public ResourceDuration{
		if(minutes < 0 || minutes > 60){
			throw new IllegalArgumentException("Minutes have to be between 0 and 60");
		}
	}
}
