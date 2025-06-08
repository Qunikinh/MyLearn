package topic.six;

import java.util.Scanner;

class QuestionDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 创建单选题
        String[] singleOptions = {"北京", "上海", "广州", "深圳"};
        SingleQuestion2 singleQ = new SingleQuestion2(
                "中国首都",
                singleOptions,
                'A'
        );

        // 创建多选题
        String[] multiOptions = {"Java", "Python", "C++", "Go"};
        MultiQuestion multiQ = new MultiQuestion(
                "常用编程语言",
                multiOptions,
                new char[]{'A', 'B', 'C'}
        );

        // 测试单选题
        System.out.println("===== 单选题 =====");
        singleQ.print();
        System.out.print("请输入答案（单个字母）：");
        char singleInput = scanner.next().toUpperCase().charAt(0);
        boolean singleResult = singleQ.check(new char[]{singleInput});
        System.out.println("答案是否正确：" + singleResult);
        System.out.println("用户选择：" + singleQ.answer);

        // 测试多选题
        System.out.println("\n===== 多选题 =====");
        multiQ.print();
        System.out.print("请输入答案（多个字母，如ABC）：");
        String multiInput = scanner.next().toUpperCase();
        char[] multiChars = multiInput.toCharArray();
        boolean multiResult = multiQ.check(multiChars);
        System.out.println("答案是否正确：" + multiResult);
        System.out.print("用户选择：");
        for (char c : multiQ.answers) System.out.print(c + " ");
    }
}