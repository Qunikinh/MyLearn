package oop.day02.extcar;

public class QQ extends Car {
    public String getType() {
        String type = "A";
        return type;
    }

    @Override
    public void run() {
        System.out.println("颠颠地跑");
    }
}
