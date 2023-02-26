package com.example;

//прописано в классе Student
//и в классе PostGraduateStudent

public class task9 {

    public static void main(String[] args) {
        Student st1 = new Student("Ivan", "Sidorov", 5);
        System.out.println("Ivan's scholarship is " + st1.getScholarship());

        Student st2 = new Student("Oleg", "Andreev", 4);
        System.out.println("Oleg's scholarship is " + st2.getScholarship());

        PostGraduateStudent p1 = new PostGraduateStudent("Maria", "Antonova", 5);
        System.out.println("Maria's scholarship is " + p1.getScholarship());

        PostGraduateStudent p2 = new PostGraduateStudent("Irina", "Petrova", 3);
        System.out.println("Maria's scholarship is " + p2.getScholarship());

    }
}
