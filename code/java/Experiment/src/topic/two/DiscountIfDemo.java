package topic.two;

public class DiscountIfDemo {
    public static double pay(int qty, double price) {
        double total = qty * price;
        double discount;

        if (qty >= 5) {
            discount = 0.15;
        } else if (qty >= 3) {
            discount = 0.10;
        } else {
            discount = 0.0;
        }

        return total * (1 - discount);
    }
}
