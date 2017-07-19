import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calendar extends JFrame{
	JLabel monthLabel = new JLabel("JULY");
	
	public Calendar(){
		super("Calendar");
		setSize(360, 100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		
		JPanel pane = new JPanel();
		FlowLayout flowlm = new FlowLayout(FlowLayout.CENTER);
		pane.setLayout(flowlm);
		pane.add(monthLabel);
		setContentPane(pane);	
		
	}
	public static void main(String[] args) {
		Calendar july = new Calendar();

	}
}
