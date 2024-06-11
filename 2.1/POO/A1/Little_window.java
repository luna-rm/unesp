package A1;
import java.awt.*;
import javax.swing.*;

public class Little_window extends JFrame {
    public void paint(Graphics g){
        g.drawString("muaaaaaa", 40, 100);
    }

    public static void main(String args[]){
        Little_window win = new Little_window();
        win.setSize(155, 150);
        win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        win.setVisible(true);
    }
}
