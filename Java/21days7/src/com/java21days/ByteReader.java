/*
 * Sams TeachYourself Java in 21 days all rights reserved.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import java.io.*;

/**
 *
 * @author nmunoz
 */
public class ByteReader {
    public static void main(String[] args){
        try(FileInputStream file = new FileInputStream("save.gif"))
            {
             boolean eof = false;
             int count = 0;
             while (!eof) {
                 int input = file.read();
                 System.out.print(input + " ");
                 if (input == -1)
                     eof = true;
                 else
                     count++;
             }
             file.close();
             System.out.println("\nBytes read: " + count);
            } catch (IOException e) {
                System.out.println("Error -- " + e.toString());
            }                   
    }    
}
