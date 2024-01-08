package bg.sofia.uni.fmi.mjt.cooking.response;

import bg.sofia.uni.fmi.mjt.cooking.recepie.Recepie;

import java.util.List;

public record Response(List<Recepie> recepies, String nextPageToken) {

}
