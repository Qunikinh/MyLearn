package oop.day03.fnl2;

public class FinalFielDemo {
    public static void main(String[] args) {
        Goo g1 = new Goo();
        Goo g2 = new Goo();
        System.out.println(g1.id + "," + g2.id + "," + Goo.index);
    }
}

class Goo {
    static int index = 1;
    final int id;

    public Goo() {
        id = index++;
    }

}