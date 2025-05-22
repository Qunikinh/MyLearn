package PD.regexstring;

public class StringBuilderAPIDemo {
    public static void main(String[] args) {
        StringBuilder buf = new StringBuilder();
        System.out.println(buf);
        System.out.println(buf.length());
        buf.append("大家说").append("Java好难").append("好累累累");
        System.out.println(buf);
        buf = buf.replace(2, 4, "啊").delete(0, 1);
        System.out.println(buf);
        String str = buf.toString();
        System.out.println(str);

        String s = "a";
        String ss = s + "1" + 2 + 3 + 4;
        s += "1";
        System.out.println(s);
        System.out.println(ss);

        buf = new StringBuilder("a");
        buf.append("1").append(2).append(3).append(4);
        s = buf.toString();
        System.out.println(s);
    }
}
