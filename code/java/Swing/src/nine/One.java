package nine;

import java.awt.*;
import javax.swing.*;

public class One extends JFrame {
    public static void main(String args[]) {
        One mainJFrame = new One();
        mainJFrame.setTitle("JFrame框架示例!");
        mainJFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainJFrame.setSize(300, 300);
        mainJFrame.setLocationRelativeTo(null);
        mainJFrame.getContentPane().setLayout(new FlowLayout());
        mainJFrame.getContentPane().setBackground(Color.green);

        JLabel lbl = new JLabel("大家好！我是一个标签");
        JButton btn = new JButton("按钮");
        mainJFrame.getContentPane().add(lbl);
        mainJFrame.getContentPane().add(btn);
        mainJFrame.setVisible(true);
    }
}