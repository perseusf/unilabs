package com.example;

import java.util.Scanner;

public class task7 {

    public static boolean isGoodNumber (int number) {
        if(number >= 0 && number <= 255) {
            return true;
        } else {
            return false;
        }
    }

    public static boolean isInt (String s) {
        if (s.matches("^[0-9]+$")) {
//            System.out.println(s);
            return true;
        } else {
            return false;
        }
    }
    public static boolean isIP (String ip) {
        String[] splitString = ip.split("[.]");
        boolean result = false;
        if (splitString.length == 4) {
            int counter = 0;
            for (String s : splitString) {
                if (isInt(s)) {
                    int currentStr = Integer.parseInt(s);
                    if(isGoodNumber(currentStr)) {
                        counter++;
                    }
                }
            }
            if (counter == splitString.length) {
                result = true;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String ip = scan.nextLine();

        System.out.println(isIP(ip));

    }
}
