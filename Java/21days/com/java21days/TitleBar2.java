/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import java.awt.event.*;
import javax.swing.*;

import java.awt.*;

public class TitleBar2 extends JFrame implements ActionListener {
    JButton b1;
    JButton b2;
    public TitleBar2(){
            super("Title Bar");
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setLookAndFeel();
            b1 = new JButton("Rosencrantz");
            b2 = new JButton("Guildenstern");
            b1.addActionListener(this);
            b2.addActionListener(this);
            FlowLayout flow = new FlowLayout();
            setLayout(flow);
            add(b1);
            add(b2);
            pack();
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
    
}
