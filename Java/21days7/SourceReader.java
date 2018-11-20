/*
 * Sams TeachYourself Java in 21 days all rights reserved.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Read own source file through a buffered character stream
 */
package com.java21days;

import java.io.*;

public class SourceReader {
    public static void main(String[] args){
        try (FileReader file = new 
        FileReader("/home/nmunoz/myprog/Java/21days7/src/com/java21days/SourceReader.java");
                BufferedReader buff = new BufferedReader(file)
                ){
                 
                boolean eof = false;
                while (!eof){
                    String line = buff.readLine();
                    if (line == null){
                        eof = true;
                    } else {
                        System.out.println(line);
                    }
                }
                buff.close();            
        } catch (IOException e) {
            System.out.println("Error -- " + e.toString());
        }
    }
}
