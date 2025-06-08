package nine;

import java.awt.*;
import javax.swing.*;

public class Four {
    static JFrame mainJFrame = new JFrame("边界布局管理器的应用示例");

    public static void main(String[] args) {
        BorderLayout border = new BorderLayout(2, 4);
        mainJFrame.setSize(250, 250);
        mainJFrame.setLocation(150, 150);

        Container container = mainJFrame.getContentPane();
        container.setLayout(border);
        container.setBackground(Color.green);

        container.add(new JButton("北"), BorderLayout.NORTH);
        container.add(new JButton("南"), BorderLayout.SOUTH);
        container.add(new JButton("东"), BorderLayout.EAST);
        container.add(new JButton("西"), BorderLayout.WEST);
        container.add(new JButton("中央"), BorderLayout.CENTER);

        mainJFrame.setVisible(true);
    }
}