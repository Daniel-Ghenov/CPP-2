package bg.sofia.uni.fmi.mjt.udemy.course.duration;

import bg.sofia.uni.fmi.mjt.udemy.course.Resource;

public record CourseDuration(int hours, int minutes)
{
	public static CourseDuration of(Resource[] content){
		int minutesTotal = 0;
		for(Resource r : content){
			minutesTotal += r.getDuration().minutes();
		}
		return new CourseDuration(minutesTotal / 60, minutesTotal % 60);
	}

	public CourseDuration{
		if(minutes < 0 || hours < 0 || minutes > 60 || hours > 24){
			throw new IllegalArgumentException("Incorrect time formatting");
		}
	}
}
