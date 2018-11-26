/*
 * ex 15.2
 * reads two digit hexadecimal sequences from a text file and displays their
 * decimal equivalents
 */
package com.java21days;
import java.io.*;

public class HexReader2 {
    //String[] input = { "000A110D1D260219 ", "78700F1318141E0C", 
    //                    "6A197D45B0FFFFFF" };
    
    public static void main(String[] arguments) {
        
        try(FileReader file = new FileReader("hexnumbers.txt");
                BufferedReader buff = new BufferedReader(file)){
        
            boolean eof = false;
            while (!eof){
                String line = buff.readLine();
                if (line == null){
                    eof = true;
                } else {
                    hexToInt(line);
                }
            }
            buff.close();            
        } catch (IOException e){
            System.out.println("Error -- " + e.toString());
        }
        //HexReader2 hex = new HexReader2();
        //for (int i =0; i < hex.input.length; i++)
        //    hex.readLine(hex.input[i]);
    }
    
    static void hexToInt(String code){
        try {
            for (int j = 0; j + 1 < code.length(); j += 2){
                String sub = code.substring(j, j + 2);
                int num = Integer.parseInt(sub, 16);
                if (num == 255) {
                    return;
                }
                System.out.print(num + " ");
            }
        } finally {
            System.out.println("**");
        }
        return;
    }
}
