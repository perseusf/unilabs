package com.example;

import java.util.Scanner;

public class fibonacci12 {

    public static void main(String[] args) {

        int first = 0;
        int second = 1;
        System.out.println(first);
        System.out.println(second);
        int value;

        for (int i = 0; i < 10; i++) {
            value = first + second;
            System.out.println(value);
            first = second;
            second = value;
        }
    }
}


