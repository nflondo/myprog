/**
 * SwingWorker is a class that's designed to run time-consuming tasks in their 
 * own worker thread and report the results. 
 * @author nmunoz
 */
package com.java21days;

import javax.swing.*;

public class DiceWorker extends SwingWorker {
    int timesToRoll;
    
    // set up the Swing worker
    public DiceWorker(int timesToRoll){
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
}