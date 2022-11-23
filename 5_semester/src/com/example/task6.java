package com.example;
import java.util.Scanner;

public class task6 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
//      str = "asdf asdf xvb34 t4, 5fаыйф 234 fff";

        String[] splitString = str.split("\\s+");

        int counter = 0;
        for (String s : splitString) {
            if (s.matches("^[a-zA-Z]+$")) {
                System.out.println(s);
                counter++;
            }
        }
        System.out.println(counter);

    }
}
