package com.example;
//task 13
public class StudentTask13 implements AutoCloseable{

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

    StudentTask13(String firstName, String lastName, double gpa) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.gpa = gpa;
    }
    double getScholarship() {
        if(gpa == 5) {
            return 80;
        } else {
            return 40;
        }
    }

    @Override
    public void close() {
        System.out.println("Closing.");
    }

}
