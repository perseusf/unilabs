package com.example;


import javax.swing.*;

public class isOdd {

    public static boolean isOdd(int number) {
        return number % 2 != 0;
    }

    public static void main(String[] args) {

        int[] array = {0, -1, 5, 4, 188, 13, -9};

        for (int i = 0; i < array.length; i++) {
            if (isOdd(array[i])) {
                System.out.println(array[i]);
            }
        }

    }

}
