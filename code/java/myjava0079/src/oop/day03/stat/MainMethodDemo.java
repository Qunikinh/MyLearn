package oop.day03.stat;

public class MainMethodDemo {
    int a = 1;
    static int b = 5;

    public int add(int a) {
        return a + this.a;
    }

    public static int f(int x) {
        System.out.println("f" + 1);
        return x + 1;
    }

    public static void main(String[] args) {
        System.out.println("main");
        System.out.println(b);
        int y = f(5);
        System.out.println(y);
        MainMethodDemo obj = new MainMethodDemo();
        System.out.println(obj.a);
        System.out.println(obj.add(5));
    }
}
