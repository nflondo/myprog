/*
 * Add or substract the content of two fields whenever the appropriate button
 * is clicked, displaying the result as a label.
 */
package com.java21days;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
/**
 *
 * @author nmunoz
 */
public class CalExe extends JFrame implements ActionListener{
    JTextField value1, value2;
    JLabel result;
    JButton add;
    JButton substract;
    
    public CalExe(){
        super("Calculator Exercise");
        setSize(350, 90);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // set up layout to populate pane
        FlowLayout flow = new FlowLayout();
        setLayout(flow);
        // Create Components
        value1 = new JTextField("0", 5);
        value2 = new JTextField("0", 5);
        result = new JLabel("0");
        add = new JButton("Add");
        substract = new JButton("Substract");
        // add action listeners
        add.addActionListener(this);
        substract.addActionListener(this);
        // Add Components
        add(value1);
        add(value2);
        add(result);
        add(add);
        add(substract);
        //pack();
        setVisible(true);
    }
    public void actionPerformed(ActionEvent evt){
        Object source = evt.getSource();
        if (source == add){
            try{
                float addition = Float.parseFloat(value1.getText()) +
                                    Float.parseFloat(value2.getText());
                    result.setText("" + addition);
            } catch (NumberFormatException nfe){
                    value1.setText("0");
                    value2.setText("0");
                    result.setText("0");
            }
        }else if (source == substract){
            try{
                float substraction = Float.parseFloat(value1.getText()) -
                                    Float.parseFloat(value2.getText());
                    result.setText("" + substraction);
            } catch (NumberFormatException nfe){
                    value1.setText("0");
                    value2.setText("0");
                    result.setText("0");
            }		
        }
        //repaint();
    }
    public static void main(String[] args){
	CalExe frame = new CalExe();
    }
    
}
