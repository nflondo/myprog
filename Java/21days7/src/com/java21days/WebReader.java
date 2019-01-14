/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import javax.swing.*;
import java.net.*;
import java.io.*;
/**
 *
 * @author nmunoz
 */
public class WebReader extends JFrame {
    JTextArea box = new JTextArea("Getting data ...");
    
    public WebReader(){
        super("Get File Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 300);
        JScrollPane pane = new JScrollPane(box);
        add(pane);
        setVisible(true);
    }
    
    void getData(String address) throws MalformedURLException {
        setTitle(address);
        URL page = new URL(address);
        StringBuilder text = new StringBuilder();
        try{
            HttpURLConnection conn = (HttpURLConnection)
                    page.openConnection();
            conn.connect();
            InputStreamReader in = new InputStreamReader(
                    (InputStream) conn.getContent());                      
            BufferedReader buff = new BufferedReader(in);
            box.setText("Getting data ...");
            String line;
            do {
                line = buff.readLine();
                text.append(line);
                text.append("\n");
            } while (line != null);            
            box.setText(text.toString());
        } catch (IOException ioe){
            System.out.println("IO Error:" + ioe.getMessage());
        }
    }
    
    public static void main(String[] arguments){
        if(arguments.length < 1){
            System.out.println("Usage: java WebReader url");
            System.exit(1);
        }
        try {
            WebReader app = new WebReader();
            app.getData(arguments[0]);
        } catch (MalformedURLException mue){
            System.out.println("Bad URL: " + arguments[0]);
        }
    }
}
