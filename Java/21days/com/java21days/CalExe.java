/*
 * To change this license header, choose License Headers in Project Properties.
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
        //setSize(300, 180);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Create Components
        value1 = new JTextField("0", 5);
        value2 = new JTextField("0", 5);
        result = new JLabel("0");
        add = new JButton("Add");
        substract = new JButton("Substract");
        // Add Components
        add(value1);
        add(value2);
        add(result);
        add(add);
        add(substract);
        pack();
        setVisible(true);
    }
    public void actionPerformed(ActionEvent evt){

    }
    public static void main(String[] args){
	CalExe frame = new CalExe();
    }
    
}
