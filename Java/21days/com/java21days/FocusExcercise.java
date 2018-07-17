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
    JTextField [] value = new JTextField[2];
    private Object Int;
    
    public FocusExcercise(){
        super("Multiply by -1");
        setSize(300, 90);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setLookAndFeel();
        FlowLayout flow = new FlowLayout(FlowLayout.CENTER);
        setLayout(flow);
        // create components
        for (int i=0; i <2; i++){
            value[i]= new JTextField("0", 5);
            value[i].addFocusListener(this);
            add(value[i]);
        }
//        value = new JTextField("0", 5);
//        value2 = new JTextField("0", 5);
        
        // add listeners
//        value.addFocusListener(this);
//        value2.addFocusListener(this);
        
        // add components
//        add(value);
//        add(value2);
        setVisible(true);
    }
    
    public void focusGained(FocusEvent event){
        checkValue(event.getSource());
 //       int number_entered = Integer.parseInt(value.getText());
 //       if ( number_entered < 0)
 //           number_entered = number_entered * -1;                    
        
 //       value.setText("" + number_entered);
    }
    
    public void focusLost(FocusEvent event){
        focusGained(event);
    }
    
    public void checkValue(Object source){
        JTextField field = (JTextField) source;
         try {
            int val = Integer.parseInt(field.getText());
            if (val < 0) {
                val = val * -1;
                field.setText("" + val);
            }
        } catch (NumberFormatException exc) {
            field.setText("0");
        }
    
    }
    public static void main(String[] args){
        FocusExcercise frame = new FocusExcercise();
    }
}
