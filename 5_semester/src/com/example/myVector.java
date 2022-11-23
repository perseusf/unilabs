package com.example;

public class myVector {
    double x;
    double y;
    double z;

    myVector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    double length() {
        return Math.sqrt(x*x + y*y + z*z);
    }
    static double scalarMultiplication(myVector v1, myVector v2) {
        return v1.x*v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    static myVector vectorMultiplication (myVector v1, myVector v2) {
        double x0 = v1.y * v2.z - v2.y * v1.z;
        double y0 =  -1 * v1.x * v2.z + v2.x * v1.z;
        double z0 = v1.x * v2.y - v2.x * v1.y;
        return new myVector(x0, y0, z0);
    }

    static myVector sum(myVector v1, myVector v2) {
        return new myVector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    static myVector difference (myVector v1, myVector v2) {
        return new myVector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }
}
