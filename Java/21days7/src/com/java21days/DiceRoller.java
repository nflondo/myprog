/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import java.awt.*;
import java.awt.event.*;
import java.beans.*;
import javax.swing.*;
/**
 * Presents a graphical user interface that can display dice-roll results and 
 * begin a set of rolls.
 * @author nmunoz
 */
public class DiceRoller extends JFrame implements ActionListener, 
        PropertyChangeListener { 
    
    // the table for dice-roll results
    JTextField[] total = new JTextField[16];
    // the "Roll' button
    JButton roll;
    // the number of times to roll
    JTextField quantity;
    // the swing worker
    DiceWorker worker;
    
    public DiceRoller(){
        super("Dice Roller");
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
            worker = new DiceWorker(timesToRoll);
            // add a listener that monitors the worker
            woker.addPropertyChangeListener(this);
        }
    }
    
}
