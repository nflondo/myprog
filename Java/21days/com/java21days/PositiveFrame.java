/* Solution to Chapter 12, Exercise 1 in Teach Yourself Java in 21 Days (Covering Java 8
   and Android by Rogers Cadenhead. */

package com.java21days;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.UIManager.*;

public class PositiveFrame extends JFrame implements FocusListener {
    JTextField[] value = new JTextField[3];

    public PositiveFrame() {
        super("Enter Numbers");
        setSize(300, 120);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        FlowLayout flow = new FlowLayout();
        setLayout(flow);
        for (int i = 0; i < 3; i++) {
            value[i] = new JTextField("0", 5);
            value[i].addFocusListener(this);
            add(value[i]);
        }
        setVisible(true);
    }
    
    private static void setLookAndFeel() {
        try {
            for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println("Couldn't use the system look and feel: " + e);
        }
    }

    public static void main(String[] arguments) {
        PositiveFrame.setLookAndFeel();
        JFrame frame = new PositiveFrame();
    }

    public void focusGained(FocusEvent evt) {
        checkValue(evt.getSource());
    }

    public void focusLost(FocusEvent evt) {
        checkValue(evt.getSource());
    }

    void checkValue(Object source) {
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
}

