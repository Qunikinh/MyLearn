package topic.ten;

class Mammal {
    void speak() {
        System.out.println("Mammal speak.");
    }
}

class Dog extends Mammal {
    void speak() {
        System.out.println("wangwang.");
    }
}

class Cat extends Mammal {
    void speak() {
        System.out.println("miaomiao.");
    }
}

public class Demo2 {
    public static void main(String[] args) {
        Mammal m;
        m = new Mammal();
        m.speak();

        m = new Dog();
        m.speak();

        m = new Cat();
        m.speak();
    }
}