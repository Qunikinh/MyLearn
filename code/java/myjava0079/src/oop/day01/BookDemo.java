package oop.day01;

import java.util.Arrays;

public class BookDemo {
    public static void main(String[] args) {
        //Book book=new Book("Java","1234567890",new String[]{"Tom","Jerry"},99.99);
        Book book1 = new Book();
        System.out.println(book1);
        System.out.println(book1.name);
        System.out.println(book1.isbn);
        System.out.println(Arrays.toString(book1.author));
        System.out.println(book1.price);

        book1.name="Java";
        Book book2 = book1;
        System.out.println(book2.name);
        System.out.println(book1.price);

        System.out.println(book2.name);
        System.out.println(book1==book2);

        System.out.println("2-------------------------");
        book1 =new Book();
        System.out.println(book1.name);

        book1.name="Java";
        System.out.println(book1==book2);

        System.out.println(book1);
        System.out.println(book2);
        System.out.println(book1.name);
        System.out.println(book1.price);

        book1=null;
        //System.out.println(book1.price);
        if (book1!=null) {
            System.out.println("not null");
            System.out.println(book1.name);
        }else {
            System.out.println("null");
        }
        System.out.println(book1=null);
    }
}
