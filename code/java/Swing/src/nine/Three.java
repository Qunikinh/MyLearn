package nine;

import java.awt.*;
import javax.swing.*;

public class Three {
    static JFrame mainJFrame = new JFrame("流式管理器FlowLayout类的应用示例!");

    public static void main(String[] args) {
        FlowLayout flow = new FlowLayout(FlowLayout.CENTER, 5, 10);
        mainJFrame.setSize(300, 200);

        Container container = mainJFrame.getContentPane();
        container.setLayout(flow);

        container.add(new JButton("JButton 1"));
        container.add(new JButton("JButton 2"));
        container.add(new JButton("JButton 3"));
        container.add(new JButton("Long-Named JButton 4"));
        container.add(new JButton("5"));

        container.add(new JLabel("流式布局策略FlowLayout"));
        container.add(new JTextField("流式布局策略FlowLayout", 18));

        mainJFrame.setVisible(true);
    }
}