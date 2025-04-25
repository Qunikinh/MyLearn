package oop.day03.stat;

public class StaticStatementDemo {
    public static void main(String[] args) {
        Xoo x1 = new Xoo();
        Xoo x2 = new Xoo();
    }
}

class Xoo {
    static {
        System.out.println("静态代码块,类加载期间只执行一次");
    }
    {
        System.out.println("构造代码块(非静态),每次创建对象时执行");
    }

    public Xoo() {
        System.out.println("执行构造器");
    }
}