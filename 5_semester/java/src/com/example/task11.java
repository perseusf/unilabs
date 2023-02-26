package com.example;
//class ComputerWontTurnOnException
//class Computer
public class task11 {
    public static void main(String[] args) throws ComputerWontTurnOnException {
        //не включится, если заряд <= 5
        //включится, если заряд > 5
        Computer comp1 = new Computer(4);

        comp1.turnOn();
    }

}
