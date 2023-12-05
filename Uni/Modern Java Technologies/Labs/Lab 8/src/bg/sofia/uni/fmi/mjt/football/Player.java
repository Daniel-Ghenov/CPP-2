package bg.sofia.uni.fmi.mjt.football;

import java.time.LocalDate;
import java.util.Arrays;
import java.util.List;

public record Player(String name, String fullName, LocalDate birthDate, int age, double heightCm, double weightKg, List<Position> positions, String nationality, int overallRating, int potential, long valueEuro, long wageEuro, Foot preferredFoot) {

    static Player of(String line) {
        String[] arguments = line.split(";");
        String name = arguments[0];
        String fullName = arguments[1];
        LocalDate birthDate = LocalDate.parse(arguments[2]);
        int age = Integer.parseInt(arguments[3]);
        double heightCm = Double.parseDouble(arguments[4]);
        double weightKg = Double.parseDouble(arguments[5]);
        List<Position> positions = Arrays.stream(arguments[6].split(",")).map(Position::valueOf).toList();
        String nationality = arguments[7];
        int overallRating = Integer.parseInt(arguments[8]);
        int potential = Integer.parseInt(arguments[9]);
        long valueEuro = Long.parseLong(arguments[10]);
        long wageEuro = Long.parseLong(arguments[11]);
        Foot preferredFoot = Foot.valueOf(arguments[12]);

        return new Player(
                name,
                fullName,
                birthDate,
                age,
                heightCm,
                weightKg,
                positions,
                nationality,
                overallRating,
                potential,
                valueEuro,
                wageEuro,
                preferredFoot
        );
    }

}
