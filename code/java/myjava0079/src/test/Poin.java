package test;

public class Poin {
    int x, y;

    public Poin(final int x, final int y) {
        this.x = x;
        this.y = y;
    }

    public Poin(final int x) {
        this.x = x;
    }

    public int getX() {
        return x;
    }

    public void setX(final int x) {
        this.x = x;
    }

    public double distance() {
        return Math.sqrt(x * x + y * y);
    }

    public double distance(final int x, final int y) {
        return Math.sqrt((this.x - x) * (this.x - x) + (this.y - y) * (this.y - y));
    }

    public double distance(final Poin p) {
        return distance(this.x, this.y);
    }
}
