package com.example;
import java.util.*;

public class task18 {

    public static void compare2Lists() {
        ArrayList<Integer> arrlist = new ArrayList<>();
        LinkedList<Integer> linklist = new LinkedList<>();

        Random ran = new Random();

        int numOfElements = 500000;
        int numOfChosen = 100000;

        //добавление элементов в коллекции
        for (int i = 0; i < numOfElements; i++) {
            arrlist.add(ran.nextInt());
            linklist.add(ran.nextInt());
        }

        long startTime = System.currentTimeMillis();
        for (int i = 0; i < numOfChosen; i++) {
            arrlist.get(ran.nextInt(numOfElements));
        }
        System.out.println("ArrayList time = " + (System.currentTimeMillis() - startTime) + " milliseconds");

        startTime = System.currentTimeMillis();
        for (int i = 0; i < numOfChosen; i++) {
            linklist.get(ran.nextInt(numOfElements));
        }
        System.out.println("LinkedList time = " + (System.currentTimeMillis() - startTime) + " milliseconds");
    }

    public static void main(String[] args) {
        compare2Lists();
    }

}
