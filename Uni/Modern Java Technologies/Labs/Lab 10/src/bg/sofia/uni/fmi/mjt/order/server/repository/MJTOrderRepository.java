package bg.sofia.uni.fmi.mjt.order.server.repository;

import bg.sofia.uni.fmi.mjt.order.server.Response;
import bg.sofia.uni.fmi.mjt.order.server.destination.Destination;
import bg.sofia.uni.fmi.mjt.order.server.tshirt.Color;
import bg.sofia.uni.fmi.mjt.order.server.tshirt.Size;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
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
		List<String> invalidArguments = new ArrayList<>();

		size = validateEnum(size, Size.class);
		if (size.startsWith("INVALID")) {
			invalidArguments.add("size");
		}

		color = validateEnum(color, Color.class);
		if (color.startsWith("INVALID")) {
			invalidArguments.add("color");
		}

		destination = validateEnum(destination, Destination.class);
		if (destination.startsWith("INVALID")) {
			invalidArguments.add("destination");
		}

		if(!invalidArguments.isEmpty()) {
			return Response.decline("invalid:" + String.join(",", invalidArguments));
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

	String validateEnum(String enumName, Class<? extends Enum> enumClass)
	{
		if (enumName == null) {
			return "INVALID";
		}
		boolean isCorrect = Arrays.stream(enumClass.getEnumConstants())
				.map(Enum::name)
				.anyMatch(enumName::equals);

		if(isCorrect) {
			return enumName;
		}
		else {
			return "INVALID";
		}
	}
}
