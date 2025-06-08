package topic.three;
import java.util.Random;

public class IsInnerDemo {
    public static void main(String[] args) {
        Random random = new Random();

        // 生成圆的圆心坐标（0-98之间的整数）
        int circleX = random.nextInt(99);
        int circleY = random.nextInt(99);
        Point center = new Point(circleX, circleY);

        // 生成圆的半径（1-98之间的整数，确保圆在[0,99)范围内）
        int radius = random.nextInt(98) + 1;

        // 生成测试点的坐标
        int pointX = random.nextInt(99);
        int pointY = random.nextInt(99);
        Point testPoint = new Point(pointX, pointY);

        // 创建圆对象
        Circle circle = new Circle(center, radius);

        // 判断点是否在圆内
        boolean result = Circle.isInner(circle, testPoint);

        // 输出结果
        System.out.printf("圆心坐标: (%d, %d), 半径: %d%n", circleX, circleY, radius);
        System.out.printf("测试点坐标: (%d, %d)%n", pointX, pointY);
        System.out.println("点" + (result ? "在" : "不在") + "圆内");
    }
}