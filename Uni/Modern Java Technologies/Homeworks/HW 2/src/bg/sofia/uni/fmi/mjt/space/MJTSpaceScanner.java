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
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

public class MJTSpaceScanner implements SpaceScannerAPI
{

	private List<Mission> missions;


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
				.collect(Collectors.groupingBy(Mission::location))
	}

	@Override public List<Mission> getTopNLeastExpensiveMissions(int n, MissionStatus missionStatus, RocketStatus rocketStatus)
	{
		return null;
	}

	@Override public Map<String, String> getMostDesiredLocationForMissionsPerCompany()
	{
		return null;
	}

	@Override public Map<String, String> getLocationWithMostSuccessfulMissionsPerCompany(LocalDate from, LocalDate to)
	{
		return null;
	}

	@Override public Collection<Rocket> getAllRockets()
	{
		return null;
	}

	@Override public List<Rocket> getTopNTallestRockets(int n)
	{
		return null;
	}

	@Override public Map<String, Optional<String>> getWikiPageForRocket()
	{
		return null;
	}

	@Override public List<String> getWikiPagesForRocketsUsedInMostExpensiveMissions(int n, MissionStatus missionStatus, RocketStatus rocketStatus)
	{
		return null;
	}

	@Override public void saveMostReliableRocket(OutputStream outputStream, LocalDate from, LocalDate to) throws CipherException
	{

	}
}
