/*
 *
 */
package com.java21days;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/**
 *
 * @author nmunoz
 */
public class TextFrame extends JFrame {
    public TextFrame(String text, String fontName){
        super("Show Font");
        setSize(425, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        TextFramePanel sf = new TextFramePanel(text, fontName);
        add(sf);
        setVisible(true);
    }
    
    public static void main(String[]args){
        if (args.length < 1){
            System.out.println("Usage: java TextFrame msg font");
            System.exit(-1);
        }
        TextFrame tf = new TextFrame(args[0], args[1]);
    }
}

class TextFramePanel extends JPanel{
    String text;
    String fontName;
    
    public TextFramePanel(String text, String fontName){
        super();
        this.text = text;
        this.fontName = fontName;
    }
    
    public void paintComponent(Graphics comp){
        super.paintComponent(comp);
        Graphics2D comp2D = (Graphics2D) comp;
        comp2D.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        Font font = new Font(fontName, Font.BOLD, 18);
        FontMetrics metrics = getFontMetrics(font);
        comp2D.setFont(font);
        int x = (getSize().width - metrics.stringWidth(text)) /2;
        int y = getSize().height / 2;
        comp2D.drawString(text, x, y);
    }
}
