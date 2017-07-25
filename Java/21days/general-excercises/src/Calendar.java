import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calendar extends JFrame{
		
	
	public Calendar(){
		super("Calendar");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// Master Panel
		JPanel masterPanel = new JPanel();
		GridLayout masterGrid = new GridLayout(2,1);
		masterPanel.setLayout(masterGrid);
		
		// Month Panel
		JPanel pane = new JPanel();
		FlowLayout monthTitle = new FlowLayout();
		pane.setLayout(monthTitle);
		JLabel monthLabel = new JLabel("JULY");
		pane.add(monthLabel);
		//setContentPane(pane);
		masterPanel.add(pane);
	
		// Weekdays Panel
		JPanel daysPanel = new JPanel();
		GridLayout days_week = new GridLayout(1, 2, 5, 5);
		daysPanel.setLayout(days_week);
		JLabel SunLabel = new JLabel("Sunday");
		JLabel MonLabel = new JLabel("Monday");
		JLabel TueLabel = new JLabel("Tuesday");
		JLabel WedLabel = new JLabel("Wednesday");
		JLabel ThuLabel = new JLabel("Thursday");
		JLabel FriLabel = new JLabel("Friday");
		JLabel SatLabel = new JLabel("Saturday");
		daysPanel.add(SunLabel);
		daysPanel.add(MonLabel);
		daysPanel.add(TueLabel);
		daysPanel.add(WedLabel);
		daysPanel.add(ThuLabel);
		daysPanel.add(FriLabel);
		daysPanel.add(SatLabel);
		//setContentPane(pane2);
		masterPanel.add(daysPanel);
		
		//masterPanel.add(pane);
		//masterPanel.add(pane2);
		setSize(600, 100);
		setVisible(true);
		setContentPane(masterPanel);
		
		
	}
	public static void main(String[] args) {
		Calendar july = new Calendar();

	}
}
