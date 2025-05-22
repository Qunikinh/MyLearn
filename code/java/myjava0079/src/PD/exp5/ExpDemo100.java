package PD.exp5;

import java.util.List;
import java.util.Scanner;

public class ExpDemo100 {
    public static void main(String[] args) {
        try (Scanner c = new Scanner(System.in)) {
            AccountMgr accountMgr = new AccountMgr();
            while (true) {
                System.out.println("input your command: 1 register 2 login 3 allusers 4 exit");
                String cmd = c.nextLine();
                if (cmd.equals("1")) {
                    System.out.println("请输入邮箱密码：");
                    String s = c.nextLine();
                    String[] ss = s.split("\\s+");
                    String email = ss[0];
                    String pwd = ss[1];
                    try {
                        User user = accountMgr.reg(email, pwd);
                        System.out.println("注册成功，用户名是：" + user);
                    } catch (EmailExitsException e) {
                        e.printStackTrace();
                        System.out.println("注册失败，邮箱已存在");
                    }
                } else if (cmd.equals("2")) {
                    System.out.println("请输入邮箱密码：");
                    String s = c.nextLine();
                    String[] ss = s.split("\\s+");
                    String email = ss[0];
                    String pwd = ss[1];
                    try {
                        User user = accountMgr.login(email, pwd);
                        System.out.println("登录成功，用户名是：" + user);
                    } catch (EmailOrPwdException e) {
                        e.printStackTrace();
                        System.out.println("登录失败，邮箱或密码错误");
                    }
                } else if (cmd.equals("3")) {
                    try {
                        System.out.println("正在查找：");
                        List<User> users = accountMgr.findAll();
                        System.out.println(users);
                    } catch (Exception e) {
                    }
                } else if (cmd.equals("4")) {
                    System.out.println("已退出");
                    break;
                }
            }
        }
    }
}
