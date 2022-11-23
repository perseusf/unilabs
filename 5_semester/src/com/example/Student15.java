package com.example;
import java.util.*;

public class Student15 {
    private String firstName;
    private String group;
    private int year;
    private double gpa;

    private double[] grades;

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getGroup() {
        return group;
    }

    public void setGroup(String group) {
        this.group = group;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public void setGpa(double gpa) {
        this.gpa = gpa;
    }

    public double[] getGrades() {
        return grades;
    }

    public void setGrades(double[] grades) {
        this.grades = grades;
    }

    Student15(String firstName, String group, int year, double[] grade) {
        this.firstName = firstName;
        this.group = group;
        this.year = year;
        this.grades = grade;

        //count gpa
        double avg = 0;
        for (Double gr : grades) {
            avg += gr / grades.length;
        }
        this.gpa = avg;
    }

    double getGpa() {
        return this.gpa;
    }

    String getFirstName() {
        return this.firstName;
    }

    int getYear() {
        return this.year;
    }


}
