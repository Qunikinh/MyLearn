package basic.day02;

public class CastDemo {
    public static void main(String[] args) {
        int a = 100;
        System.out.println(a);
        byte b = (byte) a;
        System.out.println(b);
        System.out.println(Integer.MAX_VALUE);

        a = -100;
        System.out.println(Integer.toBinaryString(a));
        b = (byte) a;
        System.out.println(b);
        System.out.println(Integer.toBinaryString(b));

        System.out.println("------2------");
        a = 255;
        System.out.println(Integer.toBinaryString(a));
        b = (byte) a;
        System.out.println(b);

        a = 129;
        System.out.println(Integer.toBinaryString(a));
        // byte b = a;
        b = (byte) a;
        System.out.println(b);
        System.out.println(Integer.toBinaryString(b));

        a = 128;
        System.out.println(Integer.toBinaryString(a));
        b = (byte) a;
        System.out.println(b);
        System.out.println(Integer.toBinaryString(b));

        System.out.println("------3------");
        b = 0xffffff80;
        System.out.println(b);// -128
        System.out.println(Integer.toBinaryString(b)); // 11111111 11111111 11111111 10000000
        b = (byte) 0x00000080;
        System.out.println(b);// -128
        System.out.println(Integer.toBinaryString(b)); // 11111111 11111111 11111111 10000000

        System.out.println("-------4--------");
        char c = 'A' + 1;// ('A'+1)是一个字面量，相当于 int 66
        System.out.println(c);

        int i = 1;
        // C='A'+i;//编译错，'A'+i结果是int，不能自动给char变量赋值!
        c = (char) ('A' + i);
        System.out.println(c);
        // C='A'+ 65535;//编译错，字面量超范围!

        System.out.println("------5-----");
        // int k=3-2.6;
        int k = (int) (3 + 2.6);
        System.out.println(k);// 5
        k = (int) (-3 - 2.6);
        System.out.println(k);// -5

        // p39 例2-13
        i = 257;
        b = (byte) i;
        System.out.println(b);
    }
}
