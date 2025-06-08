package topic.nine;

public class VIPCust extends Cust {
    VIPCust(String name, int ID, int money, String PWD) {
        super(name, ID, money, PWD);
    }

    void getMoney() {
        System.out.println("请输入取款金额：");
        int m = Integer.parseInt(KB.scan());
        if (m - 3000 > money) {
            System.out.println("不能透支超过3000元！");
        } else {
            money -= m;
        }
    }

    boolean getMoney(int m) {
        if (m - 3000 > money) {
            System.out.println("不能透支超过3000元！");
            return false;
        } else {
            money -= m;
            return true;
        }
    }
}