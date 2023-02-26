package com.example;

import java.util.Scanner;

public class task4 {

    public static void main(String[] args) {
        String str = "Do  geese   ..  see God?";

        String newstr = str.replaceAll("\\s","");
        newstr = newstr.replaceAll("\\pP", "");
        newstr = newstr.toLowerCase();

//        System.out.println(newstr);

        StringBuilder result = new StringBuilder(newstr);
        String invertedResult = result.reverse().toString();

        if (newstr.equals(invertedResult)) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }
    }

}
