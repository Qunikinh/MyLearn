package topic.five;

public class Circle extends Shape {
    public static final double PI = 3.14;
    private int r;

    public Circle(int r) {
        this.r = r;
    }

    @Override
    public double area() {
        return PI * r * r;
    }
}