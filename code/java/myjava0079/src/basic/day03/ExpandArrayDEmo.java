package basic.day03;

import java.util.Arrays;

public class ExpandArrayDEmo {
    public static void main(String[] args) {
        int[] ary1 = {3, 4, 5};
        System.out.println(Arrays.toString(ary1));
        //System.out.println(ary1);
        int[] temp =Arrays.copyOf(ary1, ary1.length + 1);
        System.out.println(Arrays.toString(temp));

        //ary1={6,7,8,9}
        ary1 =temp;
        System.out.println(Arrays.toString(temp));
        ary1[ary1.length - 1] = 9;
        System.out.println(Arrays.toString(ary1));

        ary1 =Arrays.copyOf(ary1, ary1.length + 1);

        ary1[ary1.length - 1] = 10;
        System.out.println(Arrays.toString(ary1));

        int[] temp2=Arrays.copyOfRange(ary1, 1, 3);
        System.out.println(Arrays.toString(temp2));
    }
}
