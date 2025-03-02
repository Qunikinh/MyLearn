package basic.day01;

import javax.swing.*;

public class JFrameHalloWorld {
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        JPanel pane = new JPanel();
        JLabel label = new JLabel("Hallo World");
        pane.add(label);
        frame.setContentPane(pane);
        frame.setSize(300, 200);
        frame.setVisible(true);
    }
}
