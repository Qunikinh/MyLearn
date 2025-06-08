package nine;

import java.awt.*;
import javax.swing.*;

public class Five {
    static JFrame mainJFrame = new JFrame("卡片布局管理器的应用示例!");
    static JPanel pn11 = new JPanel();
    static JPanel pn12 = new JPanel();
    static String[] str = {"第一页", "上一页", "下一页", "最后页"};
    static CardLayout card = new CardLayout(5, 10);

    public static void main(String[] args) {
        mainJFrame.setSize(360, 260);
        mainJFrame.setResizable(false);
        Container container = mainJFrame.getContentPane();
        container.setLayout(null);
        container.setBackground(Color.pink);

        pn11.setLayout(card);
        pn11.setBounds(10, 10, 320, 160);

        pn12.setLayout(new GridLayout(1, 4));
        pn12.setBounds(10, 180, 320, 35);

        for (int i = 1; i <= 3; i++) {
            String textStr = "第" + i + "页";
            JTextField text = new JTextField("卡片布局策略！! " + textStr, 30);
            pn11.add(text, "t" + i);
        }

        card.show(pn11, "t3");

        for (int i = 0; i < str.length; i++) {
            JButton b = new JButton(str[i]);
            pn12.add(b);
        }

        container.add(pn11);
        container.add(pn12);
        mainJFrame.setVisible(true);
    }
}