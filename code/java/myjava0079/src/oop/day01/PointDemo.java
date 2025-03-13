package oop.day01;

public class PointDemo {
    public static void main(String[] args) {
        Point p1 = new Point(3,4);
        Point p2 = new Point(5);
        Point p3 = new Point(5,5);

        System.out.println(p1.distance());
        System.out.println(p2.distance());
        System.out.println(p3.distance());

        System.out.println(p1.distance(6,7));

        System.out.println(p1.distance(p2));
        System.out.println(p1.distance(p3));

    }
    
}
