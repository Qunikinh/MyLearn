package basic.day02;

import java.util.Scanner;

public class LogicDemo {
    public static void main(String[] args) {
        int age = 18;

        // 输入
        System.out.println("年龄：");
        Scanner sc = new Scanner(System.in);
        age = sc.nextInt();

        char sex = '男';
        String name = "张三";

        System.out.println("姓名：");
        name = sc.next();

        System.out.println("性别：");
        String s = sc.next();
        char[] c = s.toCharArray();
        sex = c[0];
        System.out.println(name);
        System.out.println(sex);
        System.out.println(age);

        // 判断
        boolean isMan = sex == '男';
        boolean isChild = age < 18;
        boolean isBoy = isMan && isChild;
        boolean isGirl = !isMan && isChild;

        boolean isKid = isBoy || isGirl;
        System.out.println(isKid);
        isBoy = true;
        sex = isBoy ? '男' : '女';
        System.out.println(sex);
        System.out.println(Boolean.toString(isKid));
    }
}
