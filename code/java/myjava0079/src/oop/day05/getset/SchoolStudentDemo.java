package oop.day05.getset;

import java.util.Scanner;

public class SchoolStudentDemo {
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
        Studentt stu = new Studentt(name, 12, 1001);
        School school = new School("清华大学", 1001);
    }
}
