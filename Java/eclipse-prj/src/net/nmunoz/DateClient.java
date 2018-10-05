package net.nmunoz;

import java.net.*;
import java.io.*;

public class DateClient {
	public static void main(String[] args) {
		try {
			// make connection to server socket 
			Socket mysock = new Socket("127.0.0.1", 6013);
			
			InputStream in = mysock.getInputStream();
			BufferedReader buffin = new BufferedReader(new InputStreamReader(in));
			
			// read the date from the socket
			String line;
			while ( (line = buffin.readLine()) != null)
				System.out.println(line);
			
			// close the socket connection
			mysock.close();
		}
		catch (IOException ioe) {
			System.err.println(ioe);
		}
	}
}
