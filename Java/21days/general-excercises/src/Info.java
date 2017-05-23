import java.awt.GridLayout;
import java.awt.event.*;
import javax.swing.*;
/* 
 * Uses dialogs to get information from the user; that info is placed
 * into textfields in the application main window
 */
public class Info extends JFrame {
	private JLabel titleLabel = new JLabel("Title: ",
			SwingConstants.RIGHT);
	private JTextField title;
	private JLabel addressLabel = new JLabel("Address: ",
			SwingConstants.RIGHT);
	private JTextField address;
	private JLabel typeLabel = new JLabel("Type: ",
			SwingConstants.RIGHT);
	private JTextField type;
	
	public Info(){
		super("Site Information");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		//site name
		String response1 = JOptionPane.showInputDialog(null,
				"Enter the site title:");
		title = new JTextField(response1, 20);
		
		//site address
		String response2 = JOptionPane.showInputDialog(null,
				"Enter the site address:");
		address = new JTextField(response2, 20);
		
		//site type
		String [] choices = { "Personal", "Commercial", "Unknown" };
		int response3 = JOptionPane.showOptionDialog(null,
				"What type of site is it?",
				"Site Type",
				0,
				JOptionPane.QUESTION_MESSAGE,
				null,
				choices,
				choices[0]);
		type = new JTextField(choices[response3], 20);
		
		JPanel pane = new JPanel();
				
				
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
