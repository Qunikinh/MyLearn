package oop.day03.stat;

public class StaticMethodDemo {
    public static void main(String[] args) {
        int x = Goo.add(2, 3);
        System.out.println(x);
        Goo goo = new Goo();
        int y = goo.add(5);
        System.out.println(y);
    }
}

class Goo {
    int a = 1;
    static int b = 1;

    public static int add(int a, int b) {
        return a + b + Goo.b;
    }

    public int add(int a) {
        return this.a + a + Goo.b;
    }
}