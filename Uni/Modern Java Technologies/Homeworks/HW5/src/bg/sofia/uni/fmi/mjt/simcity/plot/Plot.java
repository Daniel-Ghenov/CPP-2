package bg.sofia.uni.fmi.mjt.simcity.plot;

import bg.sofia.uni.fmi.mjt.simcity.exception.BuildableAlreadyExistsException;
import bg.sofia.uni.fmi.mjt.simcity.exception.BuildableNotFoundException;
import bg.sofia.uni.fmi.mjt.simcity.exception.InsufficientPlotAreaException;
import bg.sofia.uni.fmi.mjt.simcity.property.buildable.Buildable;

import java.util.HashMap;
import java.util.Map;

public class Plot<T extends Buildable> implements PlotAPI<T> {

    private int buildableArea;

    private Map<String, T> buildables;

    public Plot(int buildableArea) {
        this.buildableArea = buildableArea;
        buildables = new HashMap<>();
    }

    @Override
    public void construct(String address, T buildable) {
        if (address == null || buildable == null || address.isBlank()) {
            throw new IllegalArgumentException();
        }
        if (buildables.get(address) != null) {
            throw new BuildableAlreadyExistsException();
        }
        if (buildable.getArea() > buildableArea) {
            throw new InsufficientPlotAreaException();
        }

        buildableArea -= buildable.getArea();
        buildables.put(address, buildable);
    }

    @Override
    public void demolish(String address) {
        if (address == null || address.isBlank()) {
            throw new IllegalArgumentException();
        }
        if (buildables.get(address) == null) {
            throw new BuildableNotFoundException();
        }
        buildableArea += buildables.get(address).getArea();
        buildables.remove(address);
    }

    @Override
    public void demolishAll() {
        int maxBuild = 0;
        for (T buildable : buildables.values()) {
            maxBuild += buildable.getArea();
        }
        buildables.clear();
        buildableArea += maxBuild;
    }

    @Override
    public Map<String, T> getAllBuildables() {
        return Map.copyOf(buildables);
    }

    @Override
    public int getRemainingBuildableArea() {
        return buildableArea;
    }

    @Override
    public void constructAll(Map<String, T> buildables) {
        if (buildables == null || buildables.isEmpty()) {
            throw new IllegalArgumentException();
        }

        for (Map.Entry<String, T> entry : buildables.entrySet()) {
            construct(entry.getKey(), entry.getValue());
        }
    }
}
