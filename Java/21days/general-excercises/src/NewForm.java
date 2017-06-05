import java.awt.*;
import javax.swing.*;

public class NewForm extends JFrame{
		
	public NewForm(){
		setSize(260, 160);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
		
		String titleResponse = JOptionPane.showInputDialog(null,
				"Enter frame title: ");
		
		//JPanel pane = new JPanel();
		setTitle(titleResponse);
		//setContentPane(pane);
		
	}
	
	public static void main(String[] args){
		NewForm myform = new NewForm();
		
	}
}

