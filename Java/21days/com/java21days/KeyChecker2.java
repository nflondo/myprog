/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class KeyChecker2 extends JFrame {
    JLabel keyLabel = new JLabel("Hit and key");
    
    public KeyChecker2() {
        super("Hit a key");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout(FlowLayout.CENTER));
        KeyAdapter monitor = new KeyAdapter(){
            public void keyTyped(KeyEvent event){
                keyLabel.setText("" + event.getKeyChar());
                repaint();
            }
        }; // semicolon here? end of class??
        setFocusable(true);
        addKeyListener(monitor);
        add(keyLabel);
        setVisible(true);
    }
    
    private static void setLookAndFeel(){
        try{
            UIManager.setLookAndFeel(
                "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
        } catch (Exception exc){
            System.err.println("Couldn't use the system look " + 
                    "and feel: " + exc);
        }
    }
    
    public static void main(String[] args){
        KeyChecker2.setLookAndFeel();
        new KeyChecker2();
    }
}
