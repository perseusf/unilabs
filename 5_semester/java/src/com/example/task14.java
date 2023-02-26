package com.example;
import java.util.*;
import java.util.Scanner;

public class task14 {

    public static void main(String[] args) {

        ArrayList<String> list = new ArrayList<String>();
        ArrayList<String> minLengthList = new ArrayList<String>();

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter five strings: \n");

        //вносим все строки в список list
        for(int i = 0; i < 5; i++) {
            list.add(scan.nextLine());
        }

        //поиск минимальной длины
        int shortestLen = list.get(1).length();;
        for(int i = 0; i < 5; i++) {
//            System.out.println(list.get(i) + "  (" + list.get(i).length() + ")");
            if (list.get(i).length() < shortestLen) {
                shortestLen = list.get(i).length();
                minLengthList.clear();
                minLengthList.add(list.get(i));
            } else if (list.get(i).length() == shortestLen) {
                minLengthList.add(list.get(i));
            }
        }

        //напечатать найденные строки
        for (String s : minLengthList) {
            System.out.println(s);
        }

    }
}
