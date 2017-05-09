import javax.swing.*;

public class FrameOfFrame extends JFrame{
	
	LoginFrame pass = new LoginFrame();
	
	public FrameOfFrame(){
		super("Login Frame");
		setSize(360, 100);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
		pass.setVisible(true);
		
	}
	public static void main(String[] args) {
		FrameOfFrame login = new FrameOfFrame();

	}

}

class LoginFrame extends JFrame{
	
	public LoginFrame(){
		super("Password Required");
		setSize(210, 130);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JPanel pane = new JPanel();
		JLabel usernameLabel = new JLabel("Username: ");
		JLabel passwordLabel = new JLabel("Password: ");
		
		JTextField username = new JTextField(8);
		JPasswordField password = new JPasswordField(8);
		
		pane.add(usernameLabel);
		pane.add(username);
		pane.add(passwordLabel);
		pane.add(password);
		setContentPane(pane);
		//pack();
		setVisible(false);
		
	}
	
	
}
