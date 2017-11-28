import javax.swing.JFrame;

public class ExitFrame extends JFrame {
	
	public ExitFrame(){
		super("Exit Frame Title");
		setSize(300,100);
		ExitWindow exit = new ExitWindow();
		addWindowListener(exit);
		setVisible(true);
	}

	public static void main(String[] args) {
		
		ExitFrame sf = new ExitFrame();

	}

}
