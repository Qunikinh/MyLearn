package basic.day02;

public class VarDemo {
    public static void main(String[] args) {
        int age = 1;// 强制类型语言
        System.out.println(age);

        // int age = 20;
        age = 20;

        System.out.println("age=" + age);

        // 变量作用域
        {
            int score = 100;
            System.out.println("score=" + score);
            age = age + 1;
        }
        // System.out.println("score="+score);
        System.out.println("age=" + age);

        // java内部编码
        age = 0x00000015;
        System.out.println("age=" + age);
    }
}
