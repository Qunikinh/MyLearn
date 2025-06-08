package nine;

import java.awt.*;
import javax.swing.*;

public class Six extends JFrame {
    static JPanel pnl = new JPanel();
    static JTextField text = new JTextField("0");
    static String[] name = {
            "7", "8", "9", "*", "单位",
            "4", "5", "6", "/", "M+",
            "1", "2", "3", "+", "M-",
            "0", "00", ".", "-", "="
    };

    public static void main(String[] args) {
        Six mainJFrame = new Six();
        mainJFrame.setTitle("网格布局管理器的应用示例！");
        mainJFrame.setSize(250, 300);
        mainJFrame.setResizable(false);
        mainJFrame.setLocationRelativeTo(null);

        Container container = mainJFrame.getContentPane();
        container.setLayout(null);

        text.setBounds(20, 10, 200, 30);
        text.setBackground(Color.yellow);
        text.setHorizontalAlignment(JTextField.RIGHT);

        GridLayout grid = new GridLayout(4, 5);
        pnl.setLayout(grid);
        pnl.setBounds(20, 45, 200, 200);

        for (int i = 0; i < name.length; i++) {
            JButton btn = new JButton(name[i]);
            btn.setMargin(new Insets(2, 2, 2, 2));
            pnl.add(btn);
        }

        container.add(text);
        container.add(pnl);
        mainJFrame.setVisible(true);
    }
}