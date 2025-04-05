package oop.day02.extcar;

public class Demo {
    public static void main(String[] args) {
        Car car = new Car();
        car.run();
        car.stop();

        QQ qq = new QQ();
        System.out.println(qq.getType());
        qq.run();
        qq.stop();

        car = qq;
        car.run();
        car.stop();
        System.out.println(car);
        System.out.println(qq);

        System.out.println("------------2-----------");
        Car car2 = new Car();
        // qq = (QQ) car2;
        // qq.run();

        Car car3 = new QQ();
        qq = (QQ) car3;
        qq.run();
        qq.stop();
        System.out.println(qq);
        System.out.println(car3);

        if (car3 instanceof QQ) {
            qq = (QQ) car3;
            qq.run();
            System.out.println("ok!");
        }

        System.out.println("------------3-----------");
        if (car2 instanceof QQ) {
            qq = (QQ) car2;
            qq.run();
            System.out.println("no!");
        }
    }
}
