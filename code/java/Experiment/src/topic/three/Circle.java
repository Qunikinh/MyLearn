package topic.three;

public class Circle {
    Point cPoint;
    int r;

    public Circle(Point cPoint, int r) {
        this.cPoint = cPoint;
        this.r = r;
    }

    public static boolean isInner(Circle circle, Point point) {
        double distance = Math.sqrt(
                Math.pow(point.x - circle.cPoint.x, 2) +
                        Math.pow(point.y - circle.cPoint.y, 2)
        );
        return distance < circle.r;
    }
}