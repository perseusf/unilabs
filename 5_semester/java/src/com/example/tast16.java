package com.example;
import java.util.*;

public class tast16 {

    public static <T> Collection<T> deleteDuplicates(Collection<T> collection) {
        return new LinkedHashSet<>(collection);
    }

    public static void main(String[] args) {
        Collection<Integer> collection = new ArrayList<>();

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter ten integers with duplicates: \n");

        for(int i = 0; i < 10; i++) {
            collection.add(scan.nextInt());
        }

        Collection<Integer> collection_no_duplicates = deleteDuplicates(collection);

        System.out.println("Collection without duplicates: \n");
        for (Integer s : collection_no_duplicates) {
            System.out.println(s);
        }

    }
}
