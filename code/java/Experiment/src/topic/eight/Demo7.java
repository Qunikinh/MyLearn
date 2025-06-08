package topic.eight;

// 文件名: Demo7.java
interface IMotocar {
    void method1();
}

interface ICar extends IMotocar {
    void method2();
}

interface ITruck extends IMotocar {
    void method3();
}

interface IStation_waggon extends ICar, ITruck { // 继承多个接口
    void method4();
}

class Mycar implements IStation_waggon {
    public void method1() {
        System.out.println("实现method1()");
    }

    public void method2() {
        System.out.println("实现method2()");
    }

    public void method3() {
        System.out.println("实现method3()");
    }

    public void method4() {
        System.out.println("实现method4()");
    }
}

public class Demo7 {
    public static void main(String[] args) {
        Mycar m = new Mycar();
        m.method1();
        m.method2();
        m.method3();
        m.method4();
    }
}