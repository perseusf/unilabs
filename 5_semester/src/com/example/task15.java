package com.example;
import java.util.*;

//class Student15

public class task15 {

    static Collection<Student15> exams(Collection<Student15> collection) {
        collection.removeIf(st -> st.getGpa() <= 3);
        return collection;
    }

    static void printStudents(Collection<Student15> students, int year) {
        Iterator<Student15> i = students.iterator();
        while (i.hasNext()) {
            Student15 currStudent = i.next();
            if (currStudent.getYear() == year) {
                System.out.println(currStudent.getFirstName() + " is at " + currStudent.getYear() + " year.");
            }
        }
    }

    public static void main(String[] args) {
        double[] grades1 = new double[] {5.0,5.0};
        Student15 st1 = new Student15("A", "1", 2, grades1);

        double[] grades2 = new double[] {2.0,4.0};
        Student15 st2 = new Student15("B", "2", 1, grades2);

        double[] grades3 = new double[] {5.0,3.0};
        Student15 st3 = new Student15("C", "2", 4, grades3);

        double[] grades4 = new double[] {2.0,3.0};
        Student15 st4 = new Student15("D", "1", 3, grades4);

        System.out.println(st1.getFirstName() + "'s GPA is " + st1.getGpa());
        System.out.println(st2.getFirstName() + "'s GPA is " + st2.getGpa());
        System.out.println(st3.getFirstName() + "'s GPA is " + st3.getGpa());
        System.out.println(st4.getFirstName() + "'s GPA is " + st4.getGpa() + "\n\nAfter exams: \n");



        Collection<Student15> collection = new ArrayList<>();

        collection.add(st1);
        collection.add(st2);
        collection.add(st3);
        collection.add(st4);

        Collection<Student15> result = new ArrayList<>();
        result = exams(collection);

        Iterator<Student15> i = result.iterator();
        while (i.hasNext()) {
            Student15 e = i.next();
            System.out.println(e.getFirstName() + "'s GPA: " + e.getGpa() + "  Year: " + e.getYear());
        }

        System.out.println('\n');

        printStudents(collection, 2);
    }


}
