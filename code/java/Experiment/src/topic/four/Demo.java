package topic.four;

import java.util.Scanner;

public class Demo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入学校信息
        System.out.print("请输入学校名称: ");
        String schoolName = scanner.nextLine();
        System.out.print("请输入学校代码: ");
        int schoolCode = scanner.nextInt();
        scanner.nextLine(); // 消耗换行符

        // 创建并设置School对象
        School school = new School();
        school.setSchoolName(schoolName);
        school.setSchoolNum(schoolCode);

        // 输入学生信息
        System.out.print("请输入学生姓名: ");
        String studentName = scanner.nextLine();
        System.out.print("请输入学生学号: ");
        int studentId = scanner.nextInt();
        System.out.print("请输入学生所在学校代码: ");
        int studentSchoolCode = scanner.nextInt();

        // 创建并设置Student对象
        Student student = new Student();
        student.setStudentName(studentName);
        student.setStudentNum(studentId);
        student.setSchoolNum(studentSchoolCode);

        // 比较学校代码并输出结果
        if (student.getSchoolNum() == school.getSchoolNum()) {
            System.out.println(student.getStudentName() + "所在学校：" + school.getSchoolName());
        } else {
            System.out.println(student.getStudentName() + "学校名称未知");
        }

        scanner.close();
    }
}