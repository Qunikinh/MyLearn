package test;

public class PointDemo {
    public static void main(String[] args) {
        Point p1 = new Point(1,2);
        Point p2 = new Point(3,4);
        Point p3 = new Point(3);

        System.out.println(p1.distance());
        System.out.println(p2.distance());
        System.out.println(p3.distance());

        System.out.println(p1.distance(p2));
        System.out.println(p2.distance(1, 2));
    }
}
