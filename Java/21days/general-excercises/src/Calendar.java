import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calendar extends JFrame{
		
	
	public Calendar(){

		super("Calendar");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// Month Title Panel
		JPanel monthPane = new JPanel();
		FlowLayout monthTitle = new FlowLayout();
		monthPane.setLayout(monthTitle);
		JLabel monthLabel = new JLabel("JULY");
		monthPane.add(monthLabel);
//		setContentPane(monthPane);
//		masterPanel.add(monthPane);
	
		// Weekdays Title Panel
		JPanel daysPanel = new JPanel();
		GridLayout days_week = new GridLayout(1, 7, 5, 5);
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
//		masterPanel.add(daysPanel);
		
		// Weekdays Numbers
		JPanel dayNumberPanel = new JPanel();
		GridLayout dayNumberLayout = new GridLayout(6, 7, 5, 5);
		dayNumberPanel.setLayout(dayNumberLayout);
		
		// create labels for each day of July 1 -31
		String daysNumber[] = {"1","2","3","4","5","6","7", "8", "9","10"};
		JLabel[] labels = new JLabel[daysNumber.length]; 
		

		// Master Panel (set user interface)
		// I want to change to border layout and use pack, see page 299 or feedbar2 program
//		JPanel masterPanel = new JPanel();
		GridLayout masterGrid = new GridLayout(2,1);
//		masterPanel.setLayout(masterGrid);
		setLayout(masterGrid);
		add(monthPane);
		add(daysPanel);
//		add(dayNumberPanel);
		setSize(600, 600);
		setVisible(true);
//		setContentPane(masterPanel);
		
		
	}
	public static void main(String[] args) {
		Calendar july = new Calendar();
		

	}
}
