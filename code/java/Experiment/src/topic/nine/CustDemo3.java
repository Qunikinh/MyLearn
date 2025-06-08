package topic.nine;

public class CustDemo3 {
    public static void main(String[] args) {
        Cust c = new Cust("Tom", 111, 1000, "111");
        VIPCust v = new VIPCust("Jerry", 1111, 1000, "1111");
        while (true) {
            System.out.println("请输入账号：");
            int id = Integer.parseInt(KB.scan());
            if (id == c.ID) {
                c.run();
            } else if (id == v.ID) {
                v.run();
            }
            System.out.println("是否退出系统(Y/N)？");
            String str = KB.scan();
            if (str.equals("Y") || str.equals("y")) {
                break;
            }
        }
    }
}