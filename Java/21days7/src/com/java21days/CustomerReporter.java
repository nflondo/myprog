/**
 * Reading records from a database. DB username: "app" and password "APP" but 
 * due to bug in netbeans the password has to be in lowercase.
 */
package com.java21days;

import java.sql.*;

public class CustomerReporter {
    public static void main(String[] arguments){
        String data = "jdbc:derby://localhost:1527/sample";
        try (
            Connection conn = DriverManager.getConnection(data, "app", "app");
            Statement st = conn.createStatement()) 
            {
            
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            
            ResultSet rec = st.executeQuery(
                   "select CUSTOMER_ID, NAME, CITY, STATE from APP.CUSTOMER " +
                   "order by CUSTOMER_ID");
            while (rec.next()) {                
                System.out.println("CUSTOMER_ID:\t" + rec.getString(1));
                System.out.println("NAME:\t" + rec.getString(2));
                System.out.println("CITY:\t" + rec.getString(3));
                System.out.println("STATE:\t" + rec.getString(4));
                System.out.println();                        
            }
            st.close();
        } catch (SQLException s) {
               System.out.println("SQL Error: " + s.toString() + " " + 
                       s.getErrorCode() + " " + s.getSQLState());                
        } catch (Exception e) {
            System.out.println("Error: " + e.toString() + e.getMessage());
        }
    }
}
