package basic.day01;

import java.util.Arrays;

public class SortAPIDemo {
    public static void main(String[] args) {
        int[] arr = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
        System.out.println(Arrays.toString(arr));
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.binarySearch(arr, 6));
    }
}
