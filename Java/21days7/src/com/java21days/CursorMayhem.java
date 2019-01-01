package com.java21days;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/**
 * Monitoring action events with an anonymous inner class
 * @author nmunoz
 */
public class CursorMayhem extends JFrame {
    JButton harry, wade, hansel;
    
    public CursorMayhem() {
        super("Choose a Cursor");
        setLookAndFeel();
        setSize(400, 80);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        harry = new JButton("Crosshair");
        add(harry);
        wade = new JButton("Wait");
        add(wade);
        hansel = new JButton("Hand");
        add(hansel);
        // begin anonymous inner class
        ActionListener act = new ActionListener() {
            public void actionPerformed(ActionEvent event){
                if (event.getSource() == harry){
                    setCursor(new Cursor(Cursor.CROSSHAIR_CURSOR));
                }
                if (event.getSource() == wade) {
                    setCursor(new Cursor(Cursor.WAIT_CURSOR));
                }
                if (event.getSource() == hansel){
                    setCursor(new Cursor(Cursor.HAND_CURSOR));
                }
            }
        };
        // end anonymous inner class
        harry.addActionListener(act);
        wade.addActionListener(act);
        hansel.addActionListener(act);
        setVisible(true);
    }
    
    private void setLookAndFeel(){
        try {
            UIManager.setLookAndFeel(
                    "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc){
            System.err.println("Look and feel error: " + exc);
        }
    }
    
    public static void main(String[] arguments){
        new CursorMayhem();
    }
}
