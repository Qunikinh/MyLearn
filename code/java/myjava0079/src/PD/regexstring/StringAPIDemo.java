package PD.regexstring;

public class StringAPIDemo {
    public static void main(String[] args) {
        String s1 = "abc";
        String s2 = s1;
        s1 = s1 + s2;
        System.out.println(s1);
        String s3 = s1.toUpperCase();
        System.out.println(s3 == s1);
        String s4 = s1.toUpperCase();
        System.out.println(s4 == s1);

        String name = "tom";
        String login = name.trim();
        System.out.println(name);
        ;
        name = "\t \r \n Jerry \n \t";
        login = name.trim();
        System.out.println(login);
        name = "\t \r \n \n \t";
        login = name.trim();
        System.out.println(login);

        String email = "aling@gmail.com";
        name = email.substring(0, email.indexOf("@"));
        String host = email.substring(email.indexOf("@") + 1);
        System.out.println(name);
        System.out.println(host);

        String filename = "tom.png";
        if (filename.endsWith(".png")) {
            System.out.println("tests endWith()");
        }
    }
}
