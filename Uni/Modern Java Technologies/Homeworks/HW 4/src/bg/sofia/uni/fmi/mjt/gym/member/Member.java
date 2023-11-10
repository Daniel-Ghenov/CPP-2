package bg.sofia.uni.fmi.mjt.gym.member;

import bg.sofia.uni.fmi.mjt.gym.workout.Exercise;
import bg.sofia.uni.fmi.mjt.gym.workout.Workout;

import java.time.DayOfWeek;
import java.util.ArrayList;
import java.util.Collection;
import java.util.EnumMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;

public class Member implements GymMember {

    private Address address;

    private String name;

    private int age;

    private String personalIdNumber;

    private Gender gender;

    private Map<DayOfWeek, Workout> trainingProgram;

    public Member(Address address, String name, int age, String personalIdNumber, Gender gender) {
        this.address = address;
        this.name = name;
        this.age = age;
        this.personalIdNumber = personalIdNumber;
        this.gender = gender;
        trainingProgram = new EnumMap<>(DayOfWeek.class);
    }

    @Override
    public Map<DayOfWeek, Workout> getTrainingProgram() {
        return trainingProgram;
    }

    @Override
    public void setWorkout(DayOfWeek day, Workout workout) {
        if (day == null) {
            throw new IllegalArgumentException("Day cannot be null");
        }
        if (workout == null) {
            throw new IllegalArgumentException("Workout cannot be null");
        }
        
        trainingProgram.put(day, workout);
    }

    @Override
    public Collection<DayOfWeek> getDaysFinishingWith(String exerciseName) {
        if (exerciseName == null) {
            throw new IllegalArgumentException("Exercise name cannot be null");
        }
        if (exerciseName.isEmpty()) {
            throw new IllegalArgumentException("Exercise name cannot be empty");
        }

        Collection<DayOfWeek> days = new ArrayList<>();
        Set<DayOfWeek> allDays = trainingProgram.keySet();
        for (DayOfWeek day : allDays) {
            Workout workout = trainingProgram.get(day);
            if (workout.exercises().getLast().name().equals(exerciseName)) {
                days.add(day);
            }
        }
        return days;
    }

    @Override
    public void addExercise(DayOfWeek day, Exercise exercise) {
        if (day == null) {
            throw new IllegalArgumentException("Day cannot be null");
        }
        if (exercise == null) {
            throw new IllegalArgumentException("Exercise cannot be null");
        }
        if (trainingProgram.get(day) == null) {
            throw new DayOffException();
        }

        trainingProgram.get(day).addExercise(exercise);
    }

    @Override
    public void addExercises(DayOfWeek day, List<Exercise> exercises) {
        if (day == null) {
            throw new IllegalArgumentException("Day cannot be null");
        }
        if (exercises == null) {
            throw new IllegalArgumentException("Exercises cannot be null");
        }
        if (exercises.isEmpty()) {
            throw new IllegalArgumentException("Exercises cannot be empty");
        }
        if (trainingProgram.get(day) == null) {
            throw new DayOffException();
        }

        trainingProgram.get(day).addExercises(exercises);
    }

    @Override
    public Address getAddress() {
        return address;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public int getAge() {
        return age;
    }

    @Override
    public String getPersonalIdNumber() {
        return personalIdNumber;
    }

    @Override
    public Gender getGender() {
        return gender;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Member member = (Member) o;
        return Objects.equals(personalIdNumber, member.personalIdNumber);
    }

    @Override
    public int hashCode() {
        return Objects.hash(personalIdNumber);
    }
}
