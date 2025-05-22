package PD.regexstring;

public class StringRegexDemo {
    public static void main(String[] args) {
        String str = "jerry56";
        String regex = "^\\w{6,10}$";
        boolean pass = str.matches(regex);
        System.out.println(pass);

        String str2 = "Tom|Jerry|Spike|Snoopy";
        String[] regex2 = str2.split("\\|");
        for (String s : regex2) {
            System.out.println(s);
        }

        str2 = str2.replaceAll("\\|", "\\,");
        System.out.println(str2);

        String name = " Tom ";
        name = name.trim().toLowerCase();
        System.out.println(name);

        String s = "GET /index.html HTTP/1.1";
        String[] arr = s.split(" ");
        for (String s1 : arr) {
            System.out.println(s1);
        }

        String z = "a0b1c2d3e4f5g6h7i8j9";
        String[] arr2 = z.split("\\d");
        for (String z1 : arr2) {
            System.out.println(z1);
        }

        System.out.println();
        String m = "a0b1c2d3e4f5g6h7i8j9";
        String[] arr3 = m.split("\\d", 3);
        for (String m1 : arr3) {
            System.out.println(m1);
        }
    }
}
