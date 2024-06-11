import java.awt.*;
import javax.swing.*;

class E1 extends JFrame {

    JPanel panel = new JPanel();
    JButton btn1 = new JButton("Abrir");
    JButton btn2 = new JButton("Salvar");
    JButton btn3 = new JButton("Salvar Como");
    JButton btn4 = new JButton("Fechar");
    JTextArea textArea = new JTextArea(10, 30);

    E1() {
        super("Editor de Texto");
        setSize(500,400);
        setLayout(new BorderLayout());

        panel.setLayout(new GridLayout(10,1));        panel.add(btn1);
        panel.add(btn2);
        panel.add(btn3);
        panel.add(btn4);

        add(panel, BorderLayout.WEST);
        add(textArea);
        
        setVisible(true);
    }
    static public void main(String[] args) {
        new E1( );
    }
}