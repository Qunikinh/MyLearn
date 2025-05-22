package test;

public class PoinDemo {
  public static void main(String[] args) {
    Poin p1 = new Poin(3, 4);
    Poin p2 = new Poin(5);
    Poin p3 = new Poin(5, 5);
    p1.setX(p1.getX() + 100);

    System.out.println(p1.distance()); // 5.0
    System.out.println(p2.distance()); // 7.0710678118654755
    System.out.println(p3.distance()); // 7.0710678118654755

    System.out.println(p1.distance(6, 7)); // 4.242640687119285

    System.out.println(p1.distance(p2)); // 2.23606797749979
    System.out.println(p1.distance(p3)); // 2.23606797749979

    Poin p4 = new Poin(3, 4);
    System.out.println(p1 == p4); // false
    System.out.println(p1.equals(p4)); // true
    System.out.println(p1); // (3,4)

    System.out.println(p4); // (3,4)
    p4.setX(8);
    System.out.println(p4); // (8,4)
    System.out.println(p1 == p4); // false
    System.out.println(p1.equals(p4)); // false
  }
}
