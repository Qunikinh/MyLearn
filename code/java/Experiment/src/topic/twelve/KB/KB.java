package topic.twelve.KB;

import java.io.*;

public class KB {
    public static String scan() {
        String str = "";
        try {
            BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
            str = buf.readLine();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return str;
    }
}