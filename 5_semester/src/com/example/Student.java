package com.example;

public class Student {
    private String firstName;
    private String lastName;
    private double gpa;

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public double getGpa() {
        return gpa;
    }

    public void setGpa(double gpa) {
        this.gpa = gpa;
    }

    Student(String firstName, String lastName, double gpa) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.gpa = gpa;
    }
    double getScholarship() {
        System.out.println(getCallerMethodAndClass()); //для задания 12
        if(gpa == 5) {
            return 80;
        } else {
            return 40;
        }
    }

    //для задания 12
    public static String getCallerMethodAndClass() {
        StackTraceElement[] stack = Thread.currentThread().getStackTrace();
        if (stack.length <= 3) {
            return null;
        }
//        System.out.println(stack[3]);
        return "Класс: " + stack[3].getClassName() + " \nМетод: " + stack[3].getMethodName();
    }

}
