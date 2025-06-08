package topic.seven;

// 文件名: Demo4.java
abstract class Person {
    private int id; // ID号
    private String username; // 用户名
    private String password; // 密码
    abstract void procScore(); // 成绩处理

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}

class Manager extends Person {
    void procScore() {
        System.out.println("添加学生信息、查询所有学生成绩。");
    }
}

class Student extends Person {
    void procScore() {
        System.out.println("查询自己的成绩。");
    }
}

class Teacher extends Person {
    void procScore() {
        System.out.println("输入成绩、打印成绩。");
    }
}

public class Demo4 {
    public static void main(String[] args) {
        Teacher t = new Teacher();
        Student s = new Student();
        Manager m = new Manager();
        t.procScore();
        s.procScore();
        m.procScore();
    }
}