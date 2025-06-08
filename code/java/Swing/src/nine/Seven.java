package nine;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Seven extends JFrame implements ActionListener {
    static Seven mainJFrame = new Seven();
    static JLabel labl1, labl2;
    static JLabel showlbl = new JLabel("0");
    static JLabel showlbl2 = new JLabel("0.0");
    static JTextField text1, text2;

    public static void main(String[] args) {
        mainJFrame.setTitle("操作事件示例!");
        mainJFrame.setSize(200, 160);
        Container container = mainJFrame.getContentPane();
        container.setLayout(new FlowLayout());

        labl1 = new JLabel("输入整型数:");
        container.add(labl1);
        text1 = new JTextField("0", 10);
        text1.addActionListener(mainJFrame);
        container.add(text1);

        labl2 = new JLabel("输入浮点数:");
        container.add(labl2);
        text2 = new JTextField("0.0", 10);
        text2.addActionListener(mainJFrame);
        container.add(text2);

        showlbl.setForeground(Color.blue);
        showlbl.setHorizontalTextPosition(SwingConstants.LEFT);
        showlbl2.setForeground(Color.green);
        showlbl2.setHorizontalTextPosition(SwingConstants.LEFT);
        container.add(showlbl);
        container.add(showlbl2);

        mainJFrame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        showlbl.setText("整数为: " + text1.getText());
        showlbl2.setText("浮点数为: " + text2.getText());
    }
}