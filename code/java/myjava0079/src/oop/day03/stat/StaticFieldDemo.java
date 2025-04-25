package oop.day03.stat;

public class StaticFieldDemo {
    public static void main(String[] args) {
        Foo f1 = new Foo();
        Foo f2 = new Foo();
        System.out.println(f1.id + "," + f2.id + "," + Foo.index);
    }
}

class Foo {
    static int index = 1;
    int id;

    public Foo() {
        this.id = index++;
    }
}
