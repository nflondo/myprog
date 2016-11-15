import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Bunch extends JFrame {

    JButton marcia = new JButton("Marcia");
    JButton carol = new JButton("Carol");
    JButton greg = new JButton("Greg");    
    JButton jan = new JButton("Jan");    
    JButton alice = new JButton("Alice");    
    JButton peter = new JButton("Peter");

    Bunch(){
        super("Bunch");
        setSize(260, 260);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel pane = new JPanel();
        GridLayout family = new GridLayout(3, 3, 10, 10);
        pane.setLayout(family);
        pane.add(marcia);
        pane.add(carol);
        pane.add(greg);
        pane.add(jan);
        pane.add(alice);                            
        pane.add(peter);    
        
        setContentPane(pane);
    } // Bunch constructor
    
    public static void main(String[] arguments){
        JFrame frame = new Bunch();
        frame.show();
    
    } // main

} // Class Bunch
