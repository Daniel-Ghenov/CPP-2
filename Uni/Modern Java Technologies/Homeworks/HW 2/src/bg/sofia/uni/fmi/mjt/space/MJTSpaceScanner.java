package bg.sofia.uni.fmi.mjt.space;

import bg.sofia.uni.fmi.mjt.space.algorithm.Rijndael;
import bg.sofia.uni.fmi.mjt.space.algorithm.SymmetricBlockCipher;
import bg.sofia.uni.fmi.mjt.space.exception.CipherException;
import bg.sofia.uni.fmi.mjt.space.exception.TimeFrameMismatchException;
import bg.sofia.uni.fmi.mjt.space.mission.Mission;
import bg.sofia.uni.fmi.mjt.space.mission.MissionStatus;
import bg.sofia.uni.fmi.mjt.space.rocket.Rocket;
import bg.sofia.uni.fmi.mjt.space.rocket.RocketStatus;

import javax.crypto.SecretKey;
import java.io.OutputStream;
import java.io.Reader;
import java.time.LocalDate;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;

public class MJTSpaceScanner implements SpaceScannerAPI
{

	private List<Mission> missions;

	private List<Rocket> rockets;

	public MJTSpaceScanner(Reader missionsReader, Reader rocketsReader, SecretKey secretKey) {


	}

	@Override public Collection<Mission> getAllMissions()
	{
		return List.copyOf(missions);
	}

	@Override public Collection<Mission> getAllMissions(MissionStatus missionStatus)
	{
		if (missionStatus == null)
			throw new IllegalArgumentException("missionStatus cannot be null");

		return missions.stream()
				.filter(mission -> mission.missionStatus().equals(missionStatus))
				.toList();
	}

	@Override public String getCompanyWithMostSuccessfulMissions(LocalDate from, LocalDate to)
	{
		if (from == null || to == null)
			throw new IllegalArgumentException("from and to cannot be null");
		if (to.isBefore(from))
			throw new TimeFrameMismatchException("to cannot be before from");

		return missions.stream()
				.filter(mission -> mission.date().isAfter(from) && mission.date().isBefore(to))
				.collect(Collectors.groupingBy(Mission::company, Collectors.counting()))
				.entrySet()
				.stream()
				.max(Map.Entry.comparingByValue())
				.map(Map.Entry::getKey)
				.orElse("");
	}

	@Override public Map<String, Collection<Mission>> getMissionsPerCountry()
	{
		return missions.stream()
				.collect(Collectors.groupingBy(Mission::getCountry, Collectors.toCollection(List::of)));
	}

	@Override public List<Mission> getTopNLeastExpensiveMissions(int n, MissionStatus missionStatus, RocketStatus rocketStatus)
	{
		if(missionStatus == null || rocketStatus == null) {
			throw new IllegalArgumentException("Mission and rocket statuses cannot be null");
		}

		return missions.stream()
				.filter(mission -> mission.missionStatus().equals(missionStatus)
								&& mission.rocketStatus().equals(rocketStatus)
				).sorted(costComparator)
				.limit(n)
				.toList();

	}

	@Override public Map<String, String> getMostDesiredLocationForMissionsPerCompany()
	{
		return missions.stream()
				.collect(Collectors.groupingBy(
						Mission::company,
						Collectors.collectingAndThen(
						Collectors.groupingBy(Mission::location, Collectors.counting()),
								missions -> missions.entrySet()
										.stream()
										.max(Map.Entry.comparingByValue())
										.map(Map.Entry::getKey)
										.get())
				));
	}

	@Override public Map<String, String> getLocationWithMostSuccessfulMissionsPerCompany(LocalDate from, LocalDate to)
	{
		if(from == null || to == null) {
			throw new IllegalArgumentException("From and to cannot be null");
		}

		return missions.stream()
				.filter(mission -> mission.date().isAfter(from) && mission.date().isBefore(to)
									&& mission.missionStatus().equals(MissionStatus.SUCCESS)
				)
				.collect(Collectors.groupingBy(
						Mission::company,
						Collectors.collectingAndThen(
								Collectors.groupingBy(Mission::location, Collectors.counting()),
								missions -> missions.entrySet()
										.stream()
										.max(Map.Entry.comparingByValue())
										.map(Map.Entry::getKey)
										.get())
				));
	}

	@Override public Collection<Rocket> getAllRockets()
	{
		return Collections.unmodifiableCollection(rockets);
	}

	@Override public List<Rocket> getTopNTallestRockets(int n)
	{
		if (n <= 0) {
			throw new IllegalArgumentException("N cannot be <= 0");
		}

		return rockets.stream()
				.sorted(heightComparator)
				.limit(n)
				.toList();
	}

	@Override public Map<String, Optional<String>> getWikiPageForRocket()
	{
		return rockets.stream()
				.collect(Collectors.toMap(Rocket::name, Rocket::wiki));
	}

	@Override public List<String> getWikiPagesForRocketsUsedInMostExpensiveMissions(int n, MissionStatus missionStatus, RocketStatus rocketStatus)
	{
		if (n <= 0) {
			throw new IllegalArgumentException("N cannot be <= 0");
		}
		if (missionStatus == null || rocketStatus == null) {
			throw new IllegalArgumentException("Mission and rocket statuses cannot be null");
		}

		Map<Mission, String> rocketsByMission = missions.stream()
				.collect(Collectors.toMap(Function.identity(), mission -> mission.detail().rocketName()));

		Map<String, Rocket> rocketsByName = rockets.stream()
				.collect(Collectors.toMap(Rocket::name, Function.identity()));

		return missions.stream()
				.filter(mission -> mission.missionStatus().equals(missionStatus) &&
									mission.rocketStatus().equals(rocketStatus))
				.sorted(costComparator.reversed())
				.limit(n)




	}

	@Override public void saveMostReliableRocket(OutputStream outputStream, LocalDate from, LocalDate to) throws CipherException
	{

	}

	private static Comparator<Mission> costComparator = new Comparator<Mission>() {
		@Override
		public int compare(Mission o1, Mission o2) {
			if(o2.cost().isEmpty()) {
				return -1;
			}
			else if (o1.cost().isEmpty()) {
				return  1;
			}
			return o1.cost().get().compareTo(o2.cost().get());
		}
	};

	private static Comparator<Rocket> heightComparator = new Comparator<Rocket>() {
		@Override
		public int compare(Rocket o1, Rocket o2) {
			if(o2.height().isEmpty()) {
				return -1;
			}
			else if (o1.height().isEmpty()) {
				return  1;
			}
			return o1.height().get().compareTo(o2.height().get());
		}
	};
}
