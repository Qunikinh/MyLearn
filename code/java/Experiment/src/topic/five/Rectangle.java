package topic.five;

public class Rectangle extends Shape {
    private int length;
    private int height;

    public Rectangle(int length, int height) {
        this.length = length;
        this.height = height;
    }

    @Override
    public double area() {
        return length * height;
    }
}