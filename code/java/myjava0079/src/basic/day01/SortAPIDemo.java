package basic.day01;

import java.util.Arrays;

public class SortAPIDemo {
    public static void main(String[] args) {
        int[] arr = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };

        System.out.println(Arrays.toString(arr));

        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));

        int index = Arrays.binarySearch(arr, 5);
        System.out.println("index5=" + index);
        System.out.println(index);

        System.out.println("index6=" + Arrays.binarySearch(arr, 6));
    }
}
