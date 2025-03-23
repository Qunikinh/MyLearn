package test;

public class Point {
    double x,y;
    public Point(double x) {
        this.x=x;
        this.y=x;
    }
    public Point(double x, double y) {
        this.x = x;
        this.y = y;        
    }
    public double distance() {
        return Math.sqrt(x*x + y*y);
    }
    public double distance(int x, int y) {
        return Math.sqrt((this.x-x)*(this.x-x) + (this.y-y)*(this.y-y));
    }
    public double distance(Point p) {
        return Math.sqrt((this.x-p.x)*(this.x-p.x) + (this.y-p.y)*(this.y-p.y));
    }
}
