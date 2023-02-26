package com.example;
import java.util.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class task17 {

    public static void main(String[] args) throws IOException {
        Path path = Paths.get("task17.txt");

        ArrayList<ArrayList<Integer>> matrix = new ArrayList<ArrayList<Integer>>();
        Stream<String> stream = Files.lines(path);


        int stringNum = 0;
        int size = stream.findFirst().get().split(" ").length;
        stream = Files.lines(path);
        System.out.println("The size of the matrix is: " + size + "\n");
        System.out.println("Initial matrix:\n");
        int row = 0;
        for (String s : stream.toArray(String[]::new)) {
            String[] currentStr = s.split(" ");
            ArrayList<Integer> rowList = new ArrayList<>();
            for (int column = 0; column < size; column++) {
                int integertoadd = Integer.parseInt(currentStr[column]);
                rowList.add(integertoadd);
                System.out.print(integertoadd+ " ");
            }
            System.out.println("");
            matrix.add(rowList);
            rowList.clear();
        }

    }

}
