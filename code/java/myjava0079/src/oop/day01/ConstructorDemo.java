package oop.day01;

public class ConstructorDemo {
    public static void main(String[] args) {
        //Foo foo = new Foo();
        Koo koo = new Koo(1);
        System.out.println(koo.a);
        //Koo koo2 = new Koo();
    }
}
class Foo {
    //public Foo() {}
}
class Koo {
    int a;
    public Koo(int a) {
        this.a = a;
    }
}
