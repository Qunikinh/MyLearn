package oop.day03.fnl2;

public class FinalMethodDemo {
    public static void main(String[] args) {
        Koo koo = new Koo();
        System.out.println(koo.add());
    }
}

class Foo {
    private final int add(int a, int b, int c) {
        return a + b + c;
    }

    private final int add(int a, int b) {
        return a + b;
    }

    private int add(int b) {
        return b + b;
    }

    private int add() {
        return 0;
    }
}

class Koo extends Foo {
    public int add(int a, int b, int c) {
        return a + b + c + 1;
    }

    private int add(int b) {
        return b + 1;
    }

    public int add() {
        return 1;
    }
}