package bg.sofia.uni.fmi.mjt.gym;

import bg.sofia.uni.fmi.mjt.gym.member.Address;
import bg.sofia.uni.fmi.mjt.gym.member.GymMember;
import bg.sofia.uni.fmi.mjt.gym.workout.Exercise;
import bg.sofia.uni.fmi.mjt.gym.workout.Workout;

import java.time.DayOfWeek;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.EnumMap;
import java.util.List;
import java.util.Map;
import java.util.SequencedCollection;
import java.util.SortedSet;
import java.util.TreeSet;

public class Gym implements GymAPI {

    private int capacity;

    private Address address;

    private SortedSet<GymMember> members;

    private Comparator<GymMember> comparator;

    public Gym(int capacity, Address address) {
        this.capacity = capacity;
        this.address = address;
        this.members = new TreeSet<>(new MemberIdComparator());
        this.comparator = new Comparator<GymMember>() {
            @Override
            public int compare(GymMember o1, GymMember o2) {
                return (int) (o1.getAddress().getDistanceTo(address) - o2.getAddress().getDistanceTo(address));
            }
        };
    }

    @Override
    public SortedSet<GymMember> getMembers() {
        return Collections.unmodifiableSortedSet(members);
    }

    @Override
    public SortedSet<GymMember> getMembersSortedByName() {
        SortedSet<GymMember> sortedMembers = new TreeSet<>(new MemberNameComparator());
        sortedMembers.addAll(members);
        return sortedMembers;
    }

    @Override
    public SortedSet<GymMember> getMembersSortedByProximityToGym() {

        SortedSet<GymMember> sortedMembers = new TreeSet<>(comparator);
        sortedMembers.addAll(members);
        return sortedMembers;
    }

    @Override
    public void addMember(GymMember member) throws GymCapacityExceededException {
        if (member == null) {
            throw new IllegalArgumentException();
        }
        if (members.size() == capacity) {
            throw new GymCapacityExceededException();
        }
        members.add(member);
    }

    @Override
    public void addMembers(Collection<GymMember> members) throws GymCapacityExceededException {
        if (members == null || members.isEmpty()) {
            throw new IllegalArgumentException();
        }
        
        if (members.size() + this.members.size() > capacity) {
            throw new GymCapacityExceededException();
        }
        this.members.addAll(members);
    }

    @Override
    public boolean isMember(GymMember member) {
        if (member == null) {
            throw new IllegalArgumentException();
        }
        
        return members.contains(member);
    }

    @Override
    public boolean isExerciseTrainedOnDay(String exerciseName, DayOfWeek day) {
        if (exerciseName == null || day == null || exerciseName.isEmpty()) {
            throw new IllegalArgumentException();
        }
        
        for (GymMember member : members) {
            SequencedCollection<Exercise> exercises = member.getTrainingProgram().get(day).exercises();
            for (Exercise exercise : exercises) {
                if (exercise.name().equals(exerciseName)) {
                    return true;
                }
            }
        }
        return false;
    }

    @Override
    public Map<DayOfWeek, List<String>> getDailyListOfMembersForExercise(String exerciseName) {
        if (exerciseName == null || exerciseName.isEmpty()) {
            throw new IllegalArgumentException("Exercise name cannot be null or empty");
        }
        
        Map<DayOfWeek, List<String>> membersForExercise = new EnumMap<>(DayOfWeek.class);

        for (DayOfWeek day : DayOfWeek.values()) {

            for (GymMember member : members) {

                Workout workout = member.getTrainingProgram().get(day);
                if (workout == null) {
                    continue;
                }
                SequencedCollection<Exercise> exercises = workout.exercises();

                for (Exercise exercise : exercises) {
                    if (exercise.name().equals(exerciseName)) {
                        membersForExercise.putIfAbsent(day, new ArrayList<>());
                        membersForExercise.get(day).add(member.getName());
                    }
                }
            }
        }
        return membersForExercise;
    }

    public static class MemberNameComparator implements Comparator<GymMember> {
        @Override
        public int compare(GymMember o1, GymMember o2) {
            return o1.getName().compareTo(o2.getName());
        }
    }

    public static class MemberIdComparator implements Comparator<GymMember> {
        @Override
        public int compare(GymMember o1, GymMember o2) {
            return o1.getPersonalIdNumber().compareTo(o2.getPersonalIdNumber());
        }
    }

}
