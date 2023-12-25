package bg.sofia.uni.fmi.mjt.order.server.repository;

import bg.sofia.uni.fmi.mjt.order.server.Response;
import bg.sofia.uni.fmi.mjt.order.server.destination.Destination;
import bg.sofia.uni.fmi.mjt.order.server.order.Order;
import bg.sofia.uni.fmi.mjt.order.server.tshirt.Color;
import bg.sofia.uni.fmi.mjt.order.server.tshirt.Size;
import bg.sofia.uni.fmi.mjt.order.server.tshirt.TShirt;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class MJTOrderRepository implements OrderRepository
{

	private final Map<Integer, Order> orders;

	public MJTOrderRepository(Map<Integer, Order> orders)
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
			createOrder(-1, size, color, destination);
			return response;
		}
		int orderId = orders.size() + 1;
		createOrder(orderId ,size, color, destination);

		return Response.create(orderId);
	}

	private void createOrder(int orderId ,String size, String color, String destination)
	{
		TShirt tShirt = new TShirt(Size.valueOf(size), Color.valueOf(color));
		Order order = new Order(orderId, tShirt, Destination.valueOf(destination));
		orders.put(orderId, order);
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
		Order order = orders.get(id);
		if (order == null) {
			return Response.notFound(id);
		}
		return Response.ok(List.of(order));
	}

	@Override public Response getAllOrders()
	{
		return Response.ok(orders.values());
	}

	@Override public Response getAllSuccessfulOrders()
	{
		List<Order> successfulOrders = orders.values()
				.stream()
				.filter(order -> order.id() >= 0)
				.toList();

		return Response.ok(successfulOrders);
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
