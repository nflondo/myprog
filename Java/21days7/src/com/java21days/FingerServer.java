/*
 * This web application uses a non-blocking socket channel to handle Finger 
 * requests.
 */
package com.java21days;

import java.io.*;
import java.net.*;
import java.nio.channels.*;
import java.util.*;

public class FingerServer {
    
    public FingerServer(){
        try {
            // Create a non-blocking server socket channel
            ServerSocketChannel sock = ServerSocketChannel.open();
            sock.configureBlocking(false);
            
            // Set the host and port to monitor
            InetSocketAddress server = new InetSocketAddress("localhost", 79);
            ServerSocket socket = sock.socket();
            socket.bind(server);
            
            // Create the selector and register it on the channel
            Selector selector = Selector.open();
            sock.register(selector, SelectionKey.OP_ACCEPT);
            
            // Loop forever, looking for client connections
            while (true) {
                // Wait for a connection
                selector.select();
                
                // Get list of selection keys with pending events
                Set keys = selector.selectedKeys();
                Iterator it = keys.iterator();
                
                // Handle each key
                while (it.hasNext()){
                    
                    // Get the key and remove it from the iteration
                    SelectionKey sKey = (SelectionKey) it.next();
                    
                    it.remove();
                    if (sKey.isAcceptable()){
                        
                        // Create a socket connection with client
                        ServerSocketChannel selChannel = 
                                (ServerSocketChannel) sKey.channel();
                        ServerSocket sSock = selChannel.socket();
                        Socket connection = sSock.accept();
                        
                        // Handle the Finger request
                        handleRequest(connection);
                        connection.close();
                    } // if                                     
                } // while
            } // while
        } catch (IOException ioe){
            System.out.println(ioe.getMessage());
        }
    } // FingerServer const
    
    private void handleRequest(Socket connection) throws IOException{
        
        // Set up input and output
        InputStreamReader isr = new InputStreamReader(connection.getInputStream());
        BufferedReader is = new BufferedReader(isr);
        PrintWriter pw = new PrintWriter(
                new BufferedOutputStream(connection.getOutputStream()),false);
        
        // Output server greeting
        pw.println("Nio Finger Server");
        pw.flush();
        
        // Handle user input
        String outLine = null;
        String inLine = is.readLine();
        
        if (inLine.length() > 0) {
            outLine = inLine;
        }
        readPlan(outLine, pw);
        
        // Clean up
        pw.flush();
        pw.close();
        is.close();
    }
    
    private void readPlan(String userName, PrintWriter pw){
        try {
            FileReader file = new FileReader(userName + ".plan");
            BufferedReader buff = new BufferedReader(file);
            boolean eof = false;
            
            pw.println("\nUser name: " + userName + "\n");
            
            while (!eof){
                String line = buff.readLine();
                
                if (line == null){
                    eof = true;
                } else {
                    pw.println(line);
                }
            }
            
            buff.close();
        } catch (IOException e){
            pw.println("User " + userName + " not found.");
        }
    }
    
    public static void main(String[] arguments){
        FingerServer nio = new FingerServer();
    }
} // FingerServer class
