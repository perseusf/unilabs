package com.example;
import java.io.*;

//class StudentTask13

public class task13 {
    public static void main(String[] args) {
        try (StudentTask13 st1 = new StudentTask13("Ivan", "Petrov", 5)) {
            System.out.println(st1.getScholarship());
        }
    }

}
