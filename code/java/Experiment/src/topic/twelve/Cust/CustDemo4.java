package topic.twelve.Cust;

import topic.twelve.KB.KB;
import topic.twelve.Cust.Cust;
import topic.twelve.Cust.VIPCust;

public class CustDemo4 {
    public static void main(String[] args) {
        Cust st[] = new Cust[8];
        st[0] = new Cust("Tom", 111, 1000, "1111");
        st[1] = new Cust("Jerry", 222, 2000, "2222");
        st[2] = new Cust("Mary", 333, 3000, "3333");
        st[3] = new Cust("Linda", 444, 4000, "4444");
        st[4] = new VIPCust("Tom", 1111, 1000, "1111");
        st[5] = new VIPCust("Jerry", 2222, 2000, "2222");
        st[6] = new VIPCust("Mary", 3333, 3000, "3333");
        st[7] = new VIPCust("Linda", 4444, 4000, "4444");
        while (true) {
            System.out.println("请输入账号：");
            int id = Integer.parseInt(KB.scan());
            for (int i = 0; i < st.length; i++) {
                if (id == st[i].getID()) {
                    st[i].run(st);
                    break;
                }
            }
            System.out.println("是否还有用户，N:退出系统？");
            String str = KB.scan();
            if (str.equals("N") || str.equals("n")) {
                break;
            }
        }
    }
}