package oop.day05.getset;

public class PersonStudentDemo {
    public static void main(String[] args) {
        Student zhang = new Student();
        Person person = zhang;
        System.out.println(zhang.age + "," + zhang.getAge());
        System.out.println(person.age + "," + person.getAge());
    }

}

class Person {
    int age = 18;

    public int getAge() {
        return age;
    }
}

class Student extends Person {
    int age = 20;

    public int getAge() {
        return age;
    }
}