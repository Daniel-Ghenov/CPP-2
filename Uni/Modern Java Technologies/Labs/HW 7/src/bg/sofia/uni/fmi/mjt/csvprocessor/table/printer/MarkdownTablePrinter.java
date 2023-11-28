package bg.sofia.uni.fmi.mjt.csvprocessor.table.printer;

import bg.sofia.uni.fmi.mjt.csvprocessor.table.Table;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.column.Column;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.SequencedMap;

public class MarkdownTablePrinter implements TablePrinter{
    @Override
    public Collection<String> printTable(Table table, ColumnAlignment... alignments) {
        Collection<String> result = new ArrayList<>();

        List<Integer> maxSizes = new ArrayList<>();
        List<String> names = new ArrayList<>(table.getColumnNames());

        for(String column : names){
            maxSizes.add(column.length());
            int currSize = maxSizes.size();

            for(String data : table.getColumnData(column)){
                maxSizes.add(currSize, Math.max(maxSizes.get(currSize), data.length()));
            }

        }
        String namesRow = getRow(names, maxSizes);
        String alignmentsRow = getAlignmentsRow(maxSizes, alignments);
        result.add(namesRow);
        result.add(alignmentsRow);

        for(int i = 0; i < table.getRowsCount() ; i++){
            List<String> currRow = new ArrayList<>();
            for(String column : names){
                currRow.add(table.getColumnData(column).toArray()[i].toString());
            }
            result.add(getRow(currRow, maxSizes));
        }

        return result;
    }

    private String getRow( List<String> columns,  List<Integer> maxSizes){

        StringBuilder result = new StringBuilder("| ");

        for (int i = 0; i < columns.size(); i++) {
            result.append(getFormatted(columns.get(i), maxSizes.get(i))).append(" | ");
        }
        result.delete(result.length() - 1, result.length());
        result.append(System.lineSeparator());

        return result.toString();
    }

    private String getAlignmentsRow(List<Integer> maxSizes, ColumnAlignment... alignments){
        StringBuilder result = new StringBuilder("| ");

        for(int i = 0; i < maxSizes.size(); i++){
            result.append(getFormattedAlignment(alignments[i], maxSizes.get(i))).append(" | ");
        }
        result.delete(result.length() - 1, result.length());
        result.append(System.lineSeparator());

        return result.toString();
    }
    private String getFormattedAlignment(ColumnAlignment data, int size){
        return switch (data) {
            case LEFT -> ":" + "-".repeat(size - 1);
            case RIGHT -> "-".repeat(size - 1) + ":";
            case CENTER -> ":" + "-".repeat(size - 2) + ":";
            case NOALIGNMENT -> "-".repeat(size);
        };
    }

    private String getFormatted(String data, int size){
        return data + " ".repeat(size - data.length());
    }
}

