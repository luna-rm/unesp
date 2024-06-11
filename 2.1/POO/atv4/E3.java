import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class E3 extends JFrame implements ActionListener{
    Choice metdBox = new Choice();
    JButton btn = new JButton("Calcular");
    JTextField numero1 = new JTextField(10);
    JTextField numero2 = new JTextField(10);
    JLabel label = new JLabel("= 0");

    E3(){
        super("calculadora");
        setSize(400,100);
        setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        JPanel n1panel = new JPanel();
        JPanel n2panel = new JPanel();
        JPanel n3panel = new JPanel();

        metdBox.addItem("Somar");
        metdBox.addItem("Subtrair");
        metdBox.addItem("Multiplicar");
        metdBox.addItem("Dividir");

        panel.add(metdBox);

        btn.addActionListener(this); 

        n1panel.add(numero1);
        n2panel.add(numero2);
        n2panel.add(label);
    
        add(n1panel,BorderLayout.WEST);
        add(panel,BorderLayout.CENTER);
        add(n2panel,BorderLayout.EAST);
        add(btn, BorderLayout.SOUTH);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        String op = (String) metdBox.getSelectedItem();
        float n1 = Float.parseFloat(numero1.getText());
        float n2 = Float.parseFloat(numero2.getText());
        float resultado = 0;
        if(op == "Somar")
            resultado = n1 + n2;
        else if(op == "Subtrair")
            resultado = n1 - n2;
        else if(op == "Multiplicar")
            resultado = n1 * n2;
        else if(op == "Divir")
            resultado = n1 / n2;
        label.setText("= " + resultado);
        
    }

    public static void main(String[] args) {
        new E3();
    } 
}
