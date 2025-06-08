package topic.ten;

class A {
    void aMethod() {
        System.out.println("A method");
    }
}

class B extends A {
    void bMethod1() {
        System.out.println("B method1");
    }

    void bMethod2() {
        System.out.println("B method2");
    }
}

public class Demo3 {
    public static void main(String[] args) {
        A a1 = new B(); // 向上转型
        a1.aMethod(); // 调用父类 A 方法

        B b1 = (B) a1; // 向下转型，编译无错误，运行时无错误
        b1.aMethod(); // 调用父类 A 方法
        b1.bMethod1(); // 调用 B 类方法
        b1.bMethod2(); // 调用 B 类方法

        A a2 = new A();
        B b2 = (B) a2; // 向下转型，编译无错误，运行时将出错
        b2.aMethod();
        b2.bMethod1();
        b2.bMethod2();
    }
}