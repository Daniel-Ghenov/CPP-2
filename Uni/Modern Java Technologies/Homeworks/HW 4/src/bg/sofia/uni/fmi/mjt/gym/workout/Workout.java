package bg.sofia.uni.fmi.mjt.gym.workout;

import java.util.List;
import java.util.SequencedCollection;

public record Workout(SequencedCollection<Exercise> exercises) {

    public void addExercise(Exercise exercise) {
        exercises.add(exercise);
    }

    public void addExercises(List<Exercise> exercises) {
        this.exercises.addAll(exercises);
    }
}
