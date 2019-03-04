/*
 * Display the current time, then close connection.  On port 4415
 */
package com.java21days;

import java.io.*;
import java.net.*;
import java.util.*;

public class TimeServer extends Thread {
    private ServerSocket sock;
    
    public TimeServer() {
        super();
        try {
            sock = new ServerSocket(4415);
            System.out.println("TimeServer running ...");
        } catch (IOException e) {
            System.out.println("Error: couldn't create socket.");
            System.exit(1);
        }
    }
    
    public void run() {
        Socket client = null;
        
        while (true) {
            if (sock == null)
                return;
            try {
                client = sock.accept();
                BufferedOutputStream bb = new BufferedOutputStream(
                    );
            }
        }
    
    }
}
