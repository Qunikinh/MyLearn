package oop.day03.access;

import oop.day03.access.sub.Koo;

public class AccessDemo {
    public static void main(String[] args) {
        Foo foo = new Foo();
        System.out.println(foo.a);
        System.out.println(foo.b);
        System.out.println(foo.c);
        // System.out.println(foo.d);
        System.out.println(foo.getD());

        Koo koo = new Koo();
        System.out.println(koo.a);
        // System.out.println(koo.b);
        // System.out.println(koo.c);
        System.out.println(koo.getD());
        Goo goo = new Goo();
        goo.test();
    }
}

class Goo extends Foo {
    public void test() {
        System.out.println(this.a);
        System.out.println(this.b);
        // System.out.println(this.c);
        System.out.println(this.getD() + this.b);
    }
}

class Foo {
    public int a = 1;
    protected int b = 2;
    int c = 3;
    private int d = 4;

    public int getD() {
        return d;
    }
}