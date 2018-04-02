package com.java21days;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MousePrank extends JFrame implements ActionListener{
    public MousePrank(){
        super("Message");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(420,220);
        BorderLayout border = new BorderLayout();
        setLayout(border);
        JLabel msg = new JLabel("Click OK to close program.");
        add(BorderLayout.NORTH, msg);
        PrankPanel prank = new PrankPanel();
        prank.ok.addActionListener(this);
        add(BorderLayout.CENTER, prank);
        setVisible(true);
    }// constructor
    
    public void actionPerformed(ActionEvent event){
        System.exit(0);
    }
    
    public Insets getInsets(){
        return new Insets(40, 10, 10, 10);
    }
    
    private static void setLookAndFeel(){
    
        try {
            for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Metal".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println("Couldn't use the system look and feel: " + e);
        }

    }
    
    public static void main(String[] args){
        MousePrank.setLookAndFeel();
        new MousePrank();
    }
}// class

class PrankPanel extends JPanel implements MouseMotionListener{
    JButton ok = new JButton("OK");
    int buttonX, buttonY, mouseX, mouseY;
    int width, height;
    
    PrankPanel(){
        super();
        setLayout(null);
        addMouseMotionListener(this);
        buttonX = 110;
        buttonY = 110;
        ok.setBounds(new Rectangle(buttonX, buttonY, 70, 20));
        add(ok);
    }
    
    public void mouseMoved(MouseEvent event){
        mouseX = event.getX();
        mouseY = event.getY();
        width = (int) getSize().getWidth();
        height = (int) getSize().getHeight();
        if (Math.abs ((mouseX + 35) - buttonX) < 50){
            buttonX = moveButton(mouseX, buttonX, width);
            repaint();
        }
        if (Math.abs((mouseY + 10) - buttonY) < 50){
            buttonY = moveButton(mouseY, buttonY, height);
            repaint();
        }
    }
    
    public void mouseDragged(MouseEvent event){
        // ignore this event
    }
    
    private int moveButton(int mouseAt, int buttonAt, int bord){
        if (buttonAt < mouseAt){
            buttonAt--;
        } else {
            buttonAt++;
        }
        if (buttonAt > (bord - 20)){
            buttonAt = 10;
        }
        if (buttonAt < 0){
            buttonAt = bord - 80;
        }
        return buttonAt;
    }
    
    public void paintComponent(Graphics comp){
        super.paintComponent(comp);
        ok.setBounds(buttonX, buttonY, 70, 20);
    }
}