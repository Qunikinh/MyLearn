package oop.day01;

public class Point {
    int x,y;
    public Point(int x,int y){
        this.x=x;
        this.y=y;
    }
    public Point(int x){
        this(x,x);
    }
    public double distance(){
        return Math.sqrt(x*x+y*y);
    }
    public double distance(int x,int y){
        return Math.sqrt((this.x-x)*(this.x-x)+(this.y-y)*(this.y-y));
    }
    public double distance(Point other){
        return this.distance(other.x,other.y);
    }
}
