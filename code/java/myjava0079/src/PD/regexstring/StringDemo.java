package PD.regexstring;

public class StringDemo {
    public static void main(String[] args) {
        String str1 = "ABC";
        String str2 = new String("ABC");
        System.out.println(str1 == str2); // false
        System.out.println(str1.equals(str2)); // true

        char[] chs = str1.toCharArray();
        System.out.println(chs);
        System.out.println(str1);
        chs[1] = 'D';
        System.out.println(chs);
        System.out.println(str1); // 不可变

        String str3 = new String(chs);
        System.out.println(str3);

    }
}
