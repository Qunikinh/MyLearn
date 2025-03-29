package oop.day02.abs;

public class Demo {
    public static void main(String[] args) {
        QQ qq = new QQ();
        qq.run();
        qq.stop();

        Car car = qq;
        car.run();
        car.stop();

        System.out.println("--------------2--------------");
        Benz benz = new Benz();
        benz.run();
        benz.stop();

        car = benz;
        car.run();
        car.stop();

        System.out.println("--------------3--------------");
        Car car1 = new Car() {
            public void run() {
                System.out.println("跑");
            }
        };
        car1.run();
        car1.stop();

        System.out.println("--------------4--------------");
        Car car2 = new Car() {
            @Override
            public void run() {
                System.out.println("fuck");
            }

            public void stop() {
                System.out.println("wdf");
            }

        };
        car2.run();
        car2.stop();
        // car2.wwz();

        System.out.println("--------------5--------------");
        Car car3 = (QQ) qq;
        car3.run();
        car3.stop();
        car3 = new Car() {
            public void run() {
                System.out.println("I love Java");
                System.out.println("hhhhhhhhhhh");
            }

            public void stop() {
                System.out.println("but qwq");
            }
        };
        car3.run();
        car3.stop();
    }
}
