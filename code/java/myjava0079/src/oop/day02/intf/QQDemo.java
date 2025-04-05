package oop.day02.intf;

public class QQDemo {
    public static void main(String[] args) {
        QQ qq = new QQ();
        Car car = qq;
        car.run();
        car.stop();
        Product p = qq;
        System.out.println(qq.getPrice());
        System.out.println(p.getPrice());

        System.out.println(qq.getType());
        System.out.println(car.getType());
        Car car2 = new Car() {
            @Override
            public void stop() {
                //
            }

            @Override
            public void run() {
                //
            }

            @Override
            public String getType() {
                return null;
            }
        };
        System.out.println(car2.getType());
    }
}