package bg.sofia.uni.fmi.mjt.space.rocket;

import java.util.Optional;

public record Rocket(String id, String name, Optional<String> wiki, Optional<Double> height) {

	public static Rocket fromString(String rocketString) {
		String[] parts = rocketString.split(",");
		int counter = 0;
		String id = parts[counter++];
		String name = parts[counter++];
		Optional<String> wiki = Optional.ofNullable(parts[counter++].isEmpty() ? null : parts[counter - 1]);
		Optional<Double> height = Optional.ofNullable(parts[counter++].isEmpty() ? null : Double.valueOf(parts[counter - 1].substring(0, parts[counter - 1].length() - 2)));
		return new Rocket(id, name, wiki, height);
	}

}
