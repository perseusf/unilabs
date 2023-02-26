package com.example;

public class task12 {
    public static String getMethodAndClass() {
        StackTraceElement[] stack = new Exception().getStackTrace();
        if (stack.length <= 2) {
            return null;
        } else {
            return "Текущий метод: " + stack[1].getMethodName() + "\nВызван в методе: " + stack[2].getMethodName() + "\nВызван в классе: " + stack[2].getClassName();
        }
    }

    public static void foo() {
        System.out.println(getMethodAndClass());
    }

    public static void main(String[] args) {
        System.out.println(getMethodAndClass());
        foo();
    }
}
