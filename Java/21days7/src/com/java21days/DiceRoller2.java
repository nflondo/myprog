/*
 * Rolls three six-sided dice a user-selected number of times and tabulates the
 * results. 
 */
package com.java21days;

import java.awt.*;
import java.awt.event.*;
import java.beans.*;
import javax.swing.*;
/**
 * Presents a graphical user interface that can display dice-roll results and 
 * begin a set of rolls.  This one uses inner class DiceWorker
 * @author nmunoz
 */
public class DiceRoller2 extends JFrame implements ActionListener, 
        PropertyChangeListener {     
    // Inner Class
    class DiceWorker2 extends SwingWorker {  
       int timesToRoll;

       // set up the Swing worker
       DiceWorker2(int timesToRoll){
           super();
           this.timesToRoll = timesToRoll;
       }

       // define the task the worker performs
       protected int [] doInBackground(){
           int[] result = new int[16];
           for (int i = 0; i < this.timesToRoll; i++){
               int sum = 0;
               for (int j = 0; j < 3; j++){
                   sum += Math.floor(Math.random() * 6);
               }
               result[sum] = result[sum] + 1;    
           }
           // transmit the result
           return result;       
       }        
    } // end inner class
    
    // the table for dice-roll results
    JTextField[] total = new JTextField[16];
    // the "Roll' button
    JButton roll;
    // the number of times to roll
    JTextField quantity;
    // the swing worker
    DiceWorker2 worker;   

    public DiceRoller2(){
        super("Dice Roller2");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setSize(850, 145);
        
        // set up top row
        JPanel topPane = new JPanel();
        GridLayout paneGrid = new GridLayout(1, 16);
        topPane.setLayout(paneGrid);
        for (int i = 0; i < 16; i++){
            // create a textfield and label
            total[i] = new JTextField("0", 4);
            JLabel label = new JLabel((i + 3) + ": ");
            // create this cell in the grid
            JPanel cell = new JPanel();
            cell.add(label);
            cell.add(total[i]);
            // add the cell to the top row
            topPane.add(cell);
        }
        
        // set up bottom row
        JPanel bottomPane = new JPanel();
        JLabel quantityLabel = new JLabel("Times to Roll: ");
        quantity = new JTextField("0", 5);
        roll = new JButton("Roll");
        roll.addActionListener(this);
        bottomPane.add(quantityLabel);
        bottomPane.add(quantity);
        bottomPane.add(roll);
        
        // set up frame
        GridLayout frameGrid = new GridLayout(2, 1);
        setLayout(frameGrid);
        add(topPane);
        add(bottomPane);
        
        setVisible(true);
    }
    
    // respond when the "Roll" button is clicked
    public void actionPerformed(ActionEvent event){
        int timesToRoll;
        try {
            // turn off the button
            timesToRoll = Integer.parseInt(quantity.getText());
            roll.setEnabled(false);
            // set up the worker that will roll the dice
            worker = new DiceWorker2(timesToRoll);
            // add a listener that monitors the worker
            worker.addPropertyChangeListener(this);
            // start the worker
            worker.execute();
        } catch (Exception exc){
            System.out.println(exc.getMessage());
            exc.printStackTrace();
        }
    }
    
    // respond when the worker's task is complete
    public void propertyChange(PropertyChangeEvent event){
        try {
            // get the worker's dice-roll results
            int[] result = (int[]) worker.get();
            // store the results in text fields
            for (int i =0; i < result.length; i++){
                total[i].setText("" + result[i]);
            } 
        } catch (Exception exc){
            System.out.println(exc.getMessage());
            exc.printStackTrace();
        }
    }
    
    private static void setLookAndFeel(){
        try{
            UIManager.setLookAndFeel(
                    "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc){
            // ignore error
        }
    }
    
    public static void main(String[] args){
        new DiceRoller2();
    }
    
}
