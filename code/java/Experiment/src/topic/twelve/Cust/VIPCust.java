package topic.twelve.Cust;

import topic.twelve.KB.KB;

public class VIPCust extends Cust {
    public VIPCust(String name, int ID, int money, String PWD) {
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

    public boolean getMoney(int m) {
        if (m - 3000 > money) {
            System.out.println("不能透支超过3000元！");
            return false;
        } else {
            money -= m;
            return true;
        }
    }

    void zhuanzhang(Cust st[]) {
        System.out.println("请输入要转入的账号：");
        int m = Integer.parseInt(KB.scan());
        for (int i = 0; i < st.length; i++) {
            if (m == st[i].getID()) {
                System.out.println("请输入转账金额：");
                int n = Integer.parseInt(KB.scan());
                if (n >= 0) {
                    if (this.getMoney(n)) {
                        st[i].saveMoney(n);
                    }
                } else {
                    if (st[i].checkPWD() == true) {
                        if (st[i].getMoney(-n)) {
                            this.saveMoney(-n);
                        }
                    } else {
                        System.out.println("密码错误，不能转账！");
                    }
                }
                return;
            }
        }
        System.out.println("没有此顾客！");
    }

    public void run(Cust st[]) {
        if (checkPWD() == false) {
            System.out.println("密码错误三次，欢迎下次光临！");
            return;
        }
        boolean flag = true;
        while (flag) {
            System.out.println("************************");
            System.out.println("取款请按\t1");
            System.out.println("存款请按\t2");
            System.out.println("查询请按\t3");
            System.out.println("改密请按\t4");
            System.out.println("转账请按\t5");
            System.out.println("退出请按\t6");
            System.out.println("************************");
            int cmd = Integer.parseInt(KB.scan());
            switch (cmd) {
                case 1:
                    getMoney();
                    break;
                case 2:
                    saveMoney();
                    break;
                case 3:
                    search();
                    break;
                case 4:
                    changePWD();
                    break;
                case 5:
                    zhuanzhang(st);
                    break;
                case 6:
                    flag = false;
                    break;
            }
        }
    }
}