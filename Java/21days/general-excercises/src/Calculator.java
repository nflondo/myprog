import java.awt.event.*;
import javax.swing.*;

import java.awt.*;

public class Calculator extends JFrame implements FocusListener {
	JTextField value1, value2, sum;
	JLabel plus, equals;
	
	public Calculator(){
		super("Add Two Numbers");
		setSize(350, 90);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		FlowLayout flow = new FlowLayout(FlowLayout.CENTER);
		setLayout(flow);
		// Create Components
		value1 = new JTextField("0", 5);
		plus = new JLabel("+");
		value2 = new JTextField("0",5);
		equals = new JLabel("=");
		sum = new JTextField("0", 5);
		// Add Listeners
		value1.addFocusListener(this);
		value2.addFocusListener(this);
		// set up sum field
		sum.setEditable(false);
		// Add Components
		add(value1);
		add(plus);
		add(value2);
		add(equals);
		add(sum);
		setVisible(true);
	}
	
	public void focusGained(FocusEvent event){
		try{
			float total = Float.parseFloat(value1.getText()) +
					Float.parseFloat(value2.getText());
			sum.setText("" + total);
		} catch (NumberFormatException nfe){
			value1.setText("0");
			value2.setText("0");
			sum.setText("0");
		}		
	}
	
	public void focusLost(FocusEvent event){
		focusGained(event);
	}
	
	private void setLookAndFeel() {
        try {
            for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println("Couldn't use the system look and feel: " + e);
        }
    }
	
	public static void main(String[] args){
		Calculator frame = new Calculator();
	}
}
