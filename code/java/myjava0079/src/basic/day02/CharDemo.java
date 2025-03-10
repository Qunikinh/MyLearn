package basic.day02;

import java.util.Random;

public class CharDemo {
    public static void main(String[] args) {
        char c = 0x4e2d;// 字面量，直接量

        System.out.println(c);
        char c1 = 20013;// =0x4e2d

        System.out.println(c1);
        // 0x4e2dSystem.out.println(Integer.toHexstring(c1));
        char c2 = '中';
        // char c3='中';
        char c3 = 0x4e2d;
        char c4 = 'z';
        int a = 20013;
        // c=a; //反方向，强制类型转换，必须明确处理
        c = (char) a;
        System.out.println(c);
        a = c3;
        a = c3; // 正方向，自动类型转换

        // c=65536 //编译错误，超范围!

        // "0""5""A"字符字面里就是一个整数字面里
        System.out.println("------2--------");
        c3 = '5';
        System.out.println(c3);
        System.out.println(Integer.toBinaryString(c3)); // 110101

        c4 = 'A';
        System.out.println(c4);
        int n = c3 - 5;
        System.out.println("n=" + n);

        // 字符c 的编码就是(int)c 所对应的整数值 n
        System.out.println("------3-------");
        System.out.println((int) c3);
        System.out.println((int) c4);
        System.out.println(c);
        System.out.println((int) c);

        System.out.println("c3+1=" + (c3 + 1));// 54
        System.out.println("n+1=" + (n + 1));// 49

        Random random = new Random();
        int index = random.nextInt(26);// 生成随机整数[0,26)
        c = (char) ('A' + index);
        System.out.println(c);// 随机字符:'A'~'Z'

        System.out.println("------4-------");
        System.out.println('\"');

        int index2 = random.nextInt(26);
        int index3 = random.nextInt(26);
        System.out.print(index);
        System.out.print('\t');
        System.out.print(index2);
        System.out.print('\t');
        System.out.println(index3);

        System.out.println(index + '\t' + index2 + '\t' + index3);
        System.out.println("a\tb\tc\nd");
        int i5 = '\t';
        System.out.println(i5);
        System.out.println(Integer.toBinaryString(i5));

        // char c3='';
        c3 = ' ';
        System.out.println(c3);
        System.out.println((int) c3);
        c3 = 0x0000;
        System.out.println(c3);
        System.out.println((int) c3);
        System.out.println("------5-------");
        char c9 = '\0';
        System.out.println(c9);
        char c10 = '\u0000';
        System.out.println(c10);
    }
}
