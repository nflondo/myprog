import javax.swing.*;

public class Expiration extends JFrame {
	JComboBox monthBox = new JComboBox();
	JComboBox yearBox = new JComboBox();
	
	public Expiration(){
		super("Expiration Date");
		setSize(340, 90);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel pane = new JPanel();
		JLabel exp = new JLabel("Expiration Date:");
		pane.add(exp);
		for (int i = 1; i < 13; i++)
			monthBox.addItem("" + i);
		for (int i = 2000; i < 2010; i++)
			yearBox.addItem("" + i);
		monthBox.setEditable(true);  // This makes mothBox a combo box
		pane.add(monthBox);
		pane.add(yearBox);
		setContentPane(pane);
		setVisible(true);
		
	}

	public static void main(String[] args) {
		Expiration ct = new Expiration();

	}

}
