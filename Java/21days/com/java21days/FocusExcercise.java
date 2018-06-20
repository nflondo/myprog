/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

/**
 *
 * @author nmunoz
 */
public class FocusExcercise extends JFrame implements FocusListener {
    JTextField value;
    
    public FocusExcercise(){
        super("Multiply by -1");
        setSize(300, 90);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setLookAndFeel();
        FlowLayout flow = new FlowLayout(FlowLayout.CENTER);
        setLayout(flow);
        // create components
        value = new JTextField("0", 5);
        
        // add listeners
        value.addFocusListener(this);
        
        // add components
        add(value);
        setVisible(true);
    }
    
    public void focusGained(FocusEvent event){
        float negative_number = Float.parseFloat(value.getText()) * -1;
        value.setText("" + negative_number);
    }
    
    public void focusLost(FocusEvent event){
        focusGained(event);
    }
    
    public static void main(String[] args){
        FocusExcercise frame = new FocusExcercise();
    }
}
