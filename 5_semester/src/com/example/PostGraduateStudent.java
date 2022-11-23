package com.example;

public class PostGraduateStudent extends Student {

    PostGraduateStudent(String firstName, String lastName, double gpa) {
        super(firstName, lastName, gpa);
    }

//    @Override
//    double getScholarship() {
//        return super.getScholarship();
//    }

        double getScholarship() {
        if (super.getGpa() == 5) {
            return 150;
        } else {
            return 100;
        }
    }
}
