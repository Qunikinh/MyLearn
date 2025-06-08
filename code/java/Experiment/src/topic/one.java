package topic;

import java.util.Scanner;

public class one {
    public int[] searchIn(String str, char key) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == key) {
                count++;
            }
        }

        if (count == 0) {
            return null;
        }

        int[] result = new int[count];
        int index = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == key) {
                result[index++] = i;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入一个字符串: ");
        String str = scanner.nextLine();
        System.out.print("请输入一个字符: ");
        String keyInput = scanner.nextLine();

        if (keyInput.length() != 1) {
            System.out.println("输入错误，请输入单个字符！");
            return;
        }

        char key = keyInput.charAt(0);
        one searcher = new one();
        int[] indices = searcher.searchIn(str, key);

        if (indices != null) {
            System.out.print("字符 " + key + " 在字符串中的下标是: ");
            for (int i = 0; i < indices.length; i++) {
                System.out.print(indices[i]);
                if (i < indices.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println();
        } else {
            System.out.println("字符 " + key + " 不在字符串中");
        }
    }
}