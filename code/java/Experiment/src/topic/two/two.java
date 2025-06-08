package topic.two;

import java.util.Scanner;


public class two {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("请输入购买数量（输入100结束）：");
            int qty = scanner.nextInt();

            if (qty == 100) {
                System.out.println("程序结束");
                break;
            }

            if (qty >= 1 && qty <= 8) {
                System.out.println("购买数量：" + qty);
                double pay = DiscountIfDemo.pay(qty, 5);
                System.out.printf("应付金额：%.2f%n", pay);
            } else {
                System.out.println("数量不合规，请重新输入数量");
            }
        }

        scanner.close();
    }
}