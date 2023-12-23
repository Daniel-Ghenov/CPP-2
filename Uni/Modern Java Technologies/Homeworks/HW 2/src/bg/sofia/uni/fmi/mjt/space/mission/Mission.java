package bg.sofia.uni.fmi.mjt.space.mission;

import bg.sofia.uni.fmi.mjt.space.rocket.RocketStatus;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Optional;

public record Mission(String id, String company, String location, LocalDate date, Detail detail, RocketStatus rocketStatus, Optional<Double> cost, MissionStatus missionStatus) {

	public static Mission fromString(String str) {
		String[] parts = str.split(",");

		String id = parts[0];
		String company = parts[1];
		String location = parts[2].substring(1, parts[2].length() - 1);
		LocalDate date = LocalDate.parse(parts[3].substring(1, parts[3].length() - 1), DateTimeFormatter.ofPattern("EEE MMM dd, yyyy"));
		Detail detail = Detail.fromString(parts[4]);
		RocketStatus rocketStatus = RocketStatus.valueOf(parts[5].substring(1, parts[5].length() - 1));
		String costStr = parts[6].substring(1, parts[6].length() - 2);
		Optional<Double> cost = costStr.equals("null") ? Optional.empty() : Optional.of(Double.parseDouble(costStr));
		MissionStatus missionStatus = MissionStatus.valueOf(parts[7]);

		return new Mission(id, company, location, date, detail, rocketStatus, cost, missionStatus);
	}

	public String getCountry() {
		String[] parts = location.split(",");
		return parts[parts.length - 1].trim();
	}

}
