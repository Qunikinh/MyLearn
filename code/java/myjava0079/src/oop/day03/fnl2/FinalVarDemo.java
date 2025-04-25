package oop.day03.fnl2;

import java.util.Arrays;

public class FinalVarDemo {
    public static void main(String[] args) {
        final int a = 1;
        System.out.println("a=" + a);
        int b = FinalVarDemo.add(a, a);
        System.out.println("b=" + b);
        final int[] ary = { 3, 4, 5 };
        ary[0] = 8;
        System.out.println(Arrays.toString(ary));
    }

    public static int add(final int a, int b) {
        b++;
        return a + b;
    }
}