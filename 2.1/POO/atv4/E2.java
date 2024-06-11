import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class E2 extends JFrame implements ActionListener{
    JButton somaButton = new JButton("Soma");
    JButton subtraiButton = new JButton("Subtração");
    JButton multiButton = new JButton("Multiplicação");
    JButton divButton = new JButton("Divisão");
    JTextField numero1 = new JTextField(10);
    JTextField numero2 = new JTextField(10);
    JLabel label = new JLabel("= 0");

    E2(){
        super("calculadora");
        setSize(400,150);
        setLayout(new BorderLayout());

        JPanel panel = new JPanel(new GridLayout(4,1));
        JPanel n1panel = new JPanel();
        JPanel n2panel = new JPanel();

        panel.add(somaButton);
        panel.add(subtraiButton);
        panel.add(multiButton);
        panel.add(divButton);
        n1panel.add(numero1);
        n2panel.add(numero2);

        somaButton.addActionListener(this);
        subtraiButton.addActionListener(this);
        multiButton.addActionListener(this);
        divButton.addActionListener(this);

        n2panel.add(label);

        add(n1panel,BorderLayout.WEST);
        add(panel,BorderLayout.CENTER);
        add(n2panel,BorderLayout.EAST);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        float n1 = Float.parseFloat(numero1.getText());
        float n2 = Float.parseFloat(numero2.getText());
        float resultado = 0;
        if(e.getSource() == somaButton)
            resultado = n1 + n2;
        else if(e.getSource() == subtraiButton)
            resultado = n1 - n2;
        else if(e.getSource() == multiButton)
            resultado = n1 * n2;
        else if(e.getSource() == divButton)
            resultado = n1 / n2;
        label.setText("= " + resultado);
        
    }

    public static void main(String[] args) {
        new E2();
    } 
}
