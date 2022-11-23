package com.example;

//task 10

public class Tram extends PublicTransport{
    @Override
    String route() {
        return "Маяковская -- Динамо";
    }

    @Override
    public double calculateTime() {
        return 50;
    }
}

