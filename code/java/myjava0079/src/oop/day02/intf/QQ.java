package oop.day02.intf;

public class QQ implements Car, Product {
    private double price = 9.9;

    public double getPrice() {
        return price;
    }

    public String getType() {
        return TYPE_A;
    }

    public void run() {
        System.out.println("颠颠跑跑");
    }

    public void stop() {
        System.out.println("磕磕地停下");
    }
}
