package PD.exp5;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class AccountMgr {
    private static long index = 1;
    private HashMap<String, User> users = new HashMap<>();

    public User reg(String email, String pwd) throws EmailExitsException {
        if (users.containsKey(email)) {
            throw new EmailExitsException("该邮箱已被注册");
        }
        User user = new User(index++, email, pwd);
        users.put(email, user);
        return user;
    }

    public User login(String email, String pwd) throws EmailOrPwdException {
        if (!users.containsKey(email)) {
            throw new EmailOrPwdException("该邮箱未注册");
        } else if (!users.get(email).getPwd().equals(pwd)) {
            throw new EmailOrPwdException("密码错误");
        }
        return users.get(email);
    }

    public List<User> findAll() {
        return new ArrayList<>(users.values());
    }
}