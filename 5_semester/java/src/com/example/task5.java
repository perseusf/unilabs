package com.example;

import java.util.Scanner;

public class task5 {

    public static void main(String[] args) {
        //enter number of strings to scan
        int n;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter n :");
        n = scan.nextInt();
        scan.nextLine(); //дочитать конец строки

        //variables
        String maxstr = null;
        String minstr = null;
        String input;

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the string:");
            input = scan.nextLine();

            if (maxstr == null || maxstr.length() < input.length()) {
                maxstr = input;
            }
            if (minstr == null || minstr.length() > input.length()) {
                minstr = input;
            }
        }

        System.out.println("The longest string is (" + maxstr.length() + " symbols): " + maxstr);
        System.out.println("The shortest string is (" + minstr.length() + " symbols): " + minstr);

    }
}
