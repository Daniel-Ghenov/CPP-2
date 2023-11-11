package bg.sofia.uni.fmi.mjt.simcity.utility;

import bg.sofia.uni.fmi.mjt.simcity.property.billable.Billable;

import java.util.Map;

public class UtilityService implements UtilityServiceAPI {

    private Map<UtilityType, Double> taxRates;

    public UtilityService(Map<UtilityType, Double> taxRates) {
        this.taxRates = taxRates;
    }

    @Override
    public <T extends Billable> double getUtilityCosts(UtilityType utilityType, T billable) {
        if (utilityType == null || billable == null) {
            throw new IllegalArgumentException();
        }

        return switch (utilityType) {
            case WATER -> billable.getWaterConsumption() * taxRates.get(UtilityType.WATER);
            case ELECTRICITY -> billable.getElectricityConsumption() * taxRates.get(UtilityType.ELECTRICITY);
            case NATURAL_GAS -> billable.getNaturalGasConsumption() * taxRates.get(UtilityType.NATURAL_GAS);
        };
    }

    @Override
    public <T extends Billable> double getTotalUtilityCosts(T billable) {
        if (billable == null) {
            throw new IllegalArgumentException();
        }

        double totalUtilityCosts = 0;
        for (UtilityType utilityType : UtilityType.values()) {
            totalUtilityCosts += getUtilityCosts(utilityType, billable);
        }
        return totalUtilityCosts;
    }

    @Override
    public <T extends Billable> Map<UtilityType, Double> computeCostsDifference(T firstBillable, T secondBillable) {
        if (firstBillable == null || secondBillable == null) {
            throw new IllegalArgumentException();
        }

        return Map.of(
                UtilityType.WATER, getUtilityCosts(UtilityType.WATER, secondBillable) -
                        getUtilityCosts(UtilityType.WATER, firstBillable),
                UtilityType.ELECTRICITY, getUtilityCosts(UtilityType.ELECTRICITY, firstBillable) -
                        getUtilityCosts(UtilityType.ELECTRICITY, secondBillable),
                UtilityType.NATURAL_GAS, getUtilityCosts(UtilityType.NATURAL_GAS, firstBillable) -
                        getUtilityCosts(UtilityType.NATURAL_GAS, secondBillable)
        );
    }
}


