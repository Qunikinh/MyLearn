package nine;

import java.awt.*;
import javax.swing.*;

public class Two {
    public static void main(String[] args) {
        JFrame mainJFrame = new JFrame("框架+面板示例!");
        mainJFrame.setSize(240, 240);
        mainJFrame.setLocation(200, 200);

        Container container = mainJFrame.getContentPane();
        container.setBackground(Color.lightGray);
        container.setLayout(null);

        JPanel pn1 = new JPanel();
        pn1.setSize(190, 180);
        pn1.setBackground(Color.green);
        pn1.setLocation(20, 20);
        pn1.setLayout(null);

        JButton btn = new JButton("我是一个按钮，单击我");
        btn.setSize(170, 40);
        btn.setBackground(Color.yellow);
        btn.setLocation(10, 50);

        pn1.add(btn);
        container.add(pn1);
        mainJFrame.setVisible(true);
    }
}