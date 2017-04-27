import javax.swing.JFrame;

public class SimpleFrame extends JFrame {
	
	public SimpleFrame(){
		super("Frame Title");
		setSize(300, 100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// debug: this shows folders in java libray path
		String path = System.getProperty("java.library.path");  
		System.out.println("Lib path: " + path);
		
		setVisible(true);
	}

	public static void main(String[] args) {
		SimpleFrame sf = new SimpleFrame();
		
	}

}
