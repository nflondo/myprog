import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class NamePass extends JFrame {
	
	// Helper method to set up all constraints
	void buildConstraints(GridBagConstraints gbc, int gx, int gy, int gw, int gh,
			int wx, int wy){
		
		gbc.gridx = gx;
		gbc.gridy = gy;
		gbc.gridwidth = gw;
		gbc.gridheight = gh;
		gbc.weightx = wx;
		gbc.weighty = wy;
		
	} // buildConstrains
	
	public NamePass(){
		super("Username and Password");
		setSize(290, 110);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		GridBagLayout gridbag = new GridBagLayout();
		GridBagConstraints constraints = new GridBagConstraints();
		JPanel pane = new JPanel();
		pane.setLayout(gridbag);
		
		// Name label
		// setting column width to 10
		buildConstraints(constraints, 0, 0, 1, 1, 10, 40);
		constraints.fill = GridBagConstraints.NONE;
		constraints.anchor = GridBagConstraints.EAST;
		//JLabel label1 = new JLabel("Name:", JLabel.LEFT);
		JLabel label1 = new JLabel("Name:");
		gridbag.setConstraints(label1, constraints);
		pane.add(label1);
		
		// Name text field
		// rest of column to 90, row (y) was already set Name label
		buildConstraints(constraints, 1, 0, 1, 1, 90, 0);
		constraints.fill = GridBagConstraints.HORIZONTAL;
		JTextField tfname = new JTextField();
		gridbag.setConstraints(tfname, constraints);
		pane.add(tfname);
		
		// password label
		buildConstraints(constraints, 0, 1, 1, 1, 0, 40);
		//constraints.fill = GridBagConstraints.HORIZONTAL;
		constraints.fill = GridBagConstraints.NONE;
		constraints.anchor = GridBagConstraints.EAST;
		//JLabel label2 = new JLabel("Password:", JLabel.LEFT);
		JLabel label2 = new JLabel("Password:");
		gridbag.setConstraints(label2, constraints);
		pane.add(label2);
		
		// password text field
		buildConstraints(constraints, 1, 1, 1, 1, 0, 0);
		constraints.fill = GridBagConstraints.HORIZONTAL;
		JPasswordField tfpass = new JPasswordField();
		tfpass.setEchoChar('*');
		gridbag.setConstraints(tfpass, constraints);
		pane.add(tfpass);
		
		// OK Button
		buildConstraints(constraints, 0, 2, 2, 1, 0, 20);
		constraints.fill = GridBagConstraints.NONE;
		constraints.anchor = GridBagConstraints.CENTER;
		JButton okb = new JButton("OK");
		gridbag.setConstraints(okb, constraints);
		pane.add(okb);
		
		// Content Pane
		setContentPane(pane);
		setVisible(true);	
		
		
	}
	public static void main(String[]args){
		NamePass frame = new NamePass();
	}

} // public class NamePass
