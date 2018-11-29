/*
 * ex 15-2 Read a file to determine the number of bytes it contains and 
 * then overwrite those bytes with 0's.
 */
package com.java21days;

import java.io.*;

public class ReadWriteEx {
    public static void main(String[] arguments){
         int [] data = new int[200];
          try(FileInputStream file = new FileInputStream("testfile.txt"))
            {
             boolean eof = false;
             int count = 0;
             while (!eof) {
                 int input = file.read();
                 data[count] = input;
                 System.out.print(data[count] + " ");
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
            // Write output to disk
           try (FileOutputStream file = new FileOutputStream("testfile.txt");
            BufferedOutputStream buff = new BufferedOutputStream(file);
            DataOutputStream content = new DataOutputStream(buff);
            ){

            for (int i = 0; i < data.length; i++)
                content.writeInt(0);
            
            content.close();
            }catch (IOException e){
                System.out.println("Error --" + e.toString());
            }
          /*
          try (FileOutputStream file = new FileOutputStream("testfile.txt"))
            {
            for (int i = 0; i < data.length; i++){
                file.write();
            }
            file.close();                
        } catch (IOException e) {
            System.out.println("Error --" + e.toString());
          }
          */
    }
}
