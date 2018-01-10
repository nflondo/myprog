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
		JLabel monthLabel = new JLabel("February");
		monthPane.add(monthLabel);
//		setContentPane(monthPane);
//		masterPanel.add(monthPane);
	
		// Weekdays Title Panel
		JPanel daysPanel = new JPanel();
		GridLayout days_week = new GridLayout(1, 7, 5, 5);
		daysPanel.setLayout(days_week);
		String[] dayNames = {"S", "M", "T", "W", "T", "F", "S"};
		JLabel[] dayCal = new JLabel[7];
		for (int i=0; i < 7; i++){
			dayCal[i] = new JLabel(dayNames[i]);
			daysPanel.add(dayCal[i]);
		}
		//setContentPane(pane2);
//		masterPanel.add(daysPanel);
		
		// Weekdays Numbers
		JPanel dayNumberPanel = new JPanel();
		GridLayout dayNumberLayout = new GridLayout(4, 7, 5, 5);
		dayNumberPanel.setLayout(dayNumberLayout);
		
		// create labels for each day of July 1 -31
//		String daysNumber[] = {"1","2","3","4","5","6","7"};
		JLabel[] labels = new JLabel[29];
		for (int i=0; i < labels.length; i++)
			labels[i]= new JLabel(""+i);

		
		for (int i=1; i < labels.length; i ++)
			dayNumberPanel.add(labels[i]);
		

		// Master Panel (set user interface)
		// I want to change to border layout and use pack, see page 299 or feedbar2 program
//		JPanel masterPanel = new JPanel();
//		GridLayout masterGrid = new GridLayout(2,1);
//		masterPanel.setLayout(masterGrid);
//		setLayout(masterGrid);
		
		BorderLayout bord = new BorderLayout();
		setLayout(bord);
		add("North", monthPane);
		add("Center", daysPanel);
		add("South", dayNumberPanel);
//		add(monthPane);
//		add(daysPanel);
//		add(dayNumberPanel);
//		setSize(300, 300);
		pack();
		setVisible(true);
//		setContentPane(masterPanel);
		
		
	}
	public static void main(String[] args) {
		Calendar july = new Calendar();
		

	}
}
