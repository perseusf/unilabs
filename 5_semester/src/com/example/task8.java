package com.example;

public class task8 {
    public static void main(String[] args) {

        myVector vector0 = new myVector(1, 0, 0);
        myVector vector1 = new myVector(1, 2, 3);

        System.out.println("Length of vector0 = " + vector0.length());
        System.out.println("Length of vector1 = " + vector1.length());

        double scalarMult = myVector.scalarMultiplication(vector0,vector1);
        System.out.println("(" + vector0.x + ", " + vector0.y + ", " + vector0.z + ") " +
                "scalar multiplied with (" + vector1.x + ", " + vector1.y + ", " + vector1.z + ") = " + scalarMult);

        myVector vectorMult = myVector.vectorMultiplication(vector0,vector1);
        System.out.println("(" + vector0.x + ", " + vector0.y + ", " + vector0.z + ") " +
                "vector multiplied with (" + vector1.x + ", " + vector1.y + ", " + vector1.z + ") = " +
                "(" + vectorMult.x + ", " + vectorMult.y + ", " + vectorMult.z + ")");

        myVector sum = myVector.sum(vector0,vector1);
        System.out.println("(" + vector0.x + ", " + vector0.y + ", " + vector0.z + ") " +
                "+ (" + vector1.x + ", " + vector1.y + ", " + vector1.z + ") = " +
                "(" + sum.x + ", " + sum.y + ", " + sum.z + ")");

        myVector difference = myVector.difference(vector0,vector1);
        System.out.println("(" + vector0.x + ", " + vector0.y + ", " + vector0.z + ") " +
                "- (" + vector1.x + ", " + vector1.y + ", " + vector1.z + ") = " +
                "(" + difference.x + ", " + difference.y + ", " + difference.z + ")");
    }

}
