package bg.sofia.uni.fmi.mjt.order.server.repository;

import bg.sofia.uni.fmi.mjt.order.server.Response;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class MJTOrderRepository implements OrderRepository
{

	private final Map<Integer, Response> orders;

	public MJTOrderRepository(Map<Integer, Response> orders)
	{
		this.orders = orders;
	}

	public MJTOrderRepository()
	{
		this(new ConcurrentHashMap<>());
	}

	@Override public Response request(String size, String color, String destination)
	{
		Response response = validateRequest(size, color, destination);
		if (response != null) {
			return response;
		}

		int orderId = orders.size() + 1;

	}

	private Response validateRequest(String size, String color, String destination)
	{
		if (size == null || color == null || destination == null)
		{
			return Response.decline("Invalid request arguments cannot be null");
		}

		size = validateSize(size);
		color = validateColor(color);
		destination = validateDestination(destination);

		if (size.equals("INVALID_SIZE") || color.equals("INVALID_COLOR") || destination.equals("INVALID_DESTINATION"))
		{
			return Response.decline("Invalid request arguments");
		}

		return null;
	}

	@Override public Response getOrderById(int id)
	{
		return null;
	}

	@Override public Response getAllOrders()
	{
		return null;
	}

	@Override public Response getAllSuccessfulOrders()
	{
		return null;
	}

	String validateSize(String size)
	{
		return switch (size)
		{
			case "S", "M", "L", "XL", "XXL" -> size;
			default -> "INVALID_SIZE";
		};
	}

	String validateColor(String color)
	{
		return switch (color)
		{
			case "RED", "GREEN", "BLUE", "BLACK", "WHITE" -> color;
			default -> "INVALID_COLOR";
		};
	}

	String validateDestination(String destination)
	{
		return switch (destination)
		{
			case "EUROPE", "NORTH_AMERICA", "SOUTH_AMERICA", "ASIA", "AUSTRALIA" -> destination;
			default -> "INVALID_DESTINATION";
		};
	}
}
