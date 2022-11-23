package com.example;
//task 11
public class Computer {
    private int battery;

    Computer(int battery) {
        this.battery = battery;
    }

    public void turnOn() throws ComputerWontTurnOnException {
        if (battery > 5) {
            System.out.println("Компьютер включен! Текущий заряд " + this.battery);
        } else {
            throw new ComputerWontTurnOnException("Компьютер разряжен! Подключите к сети. Текущий заряд " + this.battery);
        }
    }
}
