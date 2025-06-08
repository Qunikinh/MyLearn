package topic.five;

public class area {
    public static void main(String[] args) {
        Shape circle = new Circle(5);
        System.out.println("圆形面积: " + circle.area()); // 输出 78.5

        Shape rectangle = new Rectangle(4, 6);
        System.out.println("矩形面积: " + rectangle.area()); // 输出 24.0
    }
}
