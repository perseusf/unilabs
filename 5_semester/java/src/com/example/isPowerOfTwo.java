package com.example;

import java.util.Scanner;

public class isPowerOfTwo {
    public static boolean check(double value) {
        value = Math.abs(value);
        double x = (double)(Math.log(value) / Math.log(2));
        return x == (int) x;
    }

    public static void main(String[] args) {
        do {
            double value;
            Scanner scan = new Scanner(System.in);
            System.out.print("Enter the numeric value : ");
            value = scan.nextDouble();
            System.out.println(check(value));
        } while (true);
    }
}
