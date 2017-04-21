import javax.swing.*;

public class Icons extends JFrame {
	JButton[] buttons = new JButton[24];
	
	public Icons(){
		super("Icons");
		setSize(335, 318);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel pane = new JPanel();
		//ImageIcon icon = new ImageIcon("/opt/suse/testKits/system/misc/printer.gif");
		ImageIcon icon = new ImageIcon("printer.gif");
		for (int i = 0; i < 24; i++){
			buttons[i] = new JButton(icon);
			pane.add(buttons[i]);			
		}
		setContentPane(pane);
		setVisible(true);
	}

	public static void main(String[] args) {
		Icons ike = new Icons();

	}

}
