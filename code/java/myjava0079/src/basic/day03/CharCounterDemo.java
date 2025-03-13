package basic.day03;

import java.util.Arrays;

public class CharCounterDemo {
    public static void main(String[] args) {
        String str = "abcbabcbacbabcb";
        int[] ary =count(str,'b');
        System.out.println(Arrays.toString(ary));
    }
    public static int[] count(String str,char key){
        int[] ary = {};
        System.out.println(Arrays.toString(ary));
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)==key){
                ary = Arrays.copyOf(ary, ary.length+1);
                ary[ary.length-1] = i;
            }
        }
        return ary;
    }
}
