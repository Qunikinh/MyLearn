package oop.day02.Constructor;

public class Demo {
    public static void main(String[] args) {
        new Goo();
        System.out.println("--------");
        new Yoo();
        System.out.println("--------");
        new Yoo(1);
        System.out.println("--------");
        new B();
        new Noo();
        new Noo(6);
    }

}

class A {
    public A() {
        System.out.println("A");
    }
}

class B extends A {
}

class Moo {
    public Moo(int a) {
        System.out.println(a);
    }

    public Moo() {
        System.out.println("Moo");
    }
}

class Noo extends Moo {
    public Noo() {
        super(5);
    }

    public Noo(int x) {
        this();
    }
}

class Xoo {
    public Xoo() {
        System.out.println("Xoo()---");
    }

    public Xoo(int x) {
        System.out.println("Xoo(int x)---");
    }
}

class Yoo extends Xoo {
    public Yoo() {
        // super(5);
        System.out.println("Yoo()---");
    }

    public Yoo(int x) {
        super();
        System.out.println(x);
    }
}

class Foo {
    int a;

    public Foo() {
        System.out.println("Foo()");
    }

    public Foo(int a) {
        this.a = a;
    }
}

class Goo extends Foo {
}