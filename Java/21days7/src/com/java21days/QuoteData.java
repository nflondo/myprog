package com.java21days;

import java.io.*;
import java.net.*;
import java.sql.*;
import java.util.*;
/**
 * Writing records to a database (STOCK table in sample database)
 */
public class QuoteData {
    private String ticker;
    
    public QuoteData(String inTicker){
        ticker = inTicker;
    }
    
    private String retrieveQuote(){
        StringBuilder builder = new StringBuilder();
        try {
            URL page = new URL("http://quote.yahoo.com/d/quotes.csv?s=" +
                    ticker + "&f=sl1d1t1c1ohgv&e=.csv");
            String line;
            URLConnection conn = page.openConnection();
            conn.connect();
            InputStreamReader in = new InputStreamReader(conn.getInputStream());
            BufferedReader data = new BufferedReader(in);
            while ((line = data.readLine()) != null){
                builder.append(line);
                builder.append("\n");
            }            
        } catch (MalformedURLException mue){
            System.out.println("Bad URL: " + mue.getMessage());
        } catch (IOException ioe){
            System.out.println("IO Error:" + ioe.getMessage());
        }
        return builder.toString();
    }
}
