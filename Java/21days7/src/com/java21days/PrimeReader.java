/*
 * Sams TeachYourself Java in 21 days all rights reserved.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import java.io.*;

public class PrimeReader {
    public static void main(String[] args){
        try (FileInputStream file = new FileInputStream("400primes.dat");
                BufferedInputStream buff = new BufferedInputStream(file);
                DataInputStream data = new DataInputStream(buff)
                ){
            try {
                while (true) {
                    int in = data.readInt();
                    System.out.print(in + " ");
                }
            } catch (EOFException eof){
                buff.close();
            }
        } catch (IOException e){
            System.out.println("Error -- " + e.toString());
        }
            
    }
}
