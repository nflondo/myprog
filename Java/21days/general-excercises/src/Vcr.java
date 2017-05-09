import javax.swing.*;

public class Vcr extends JFrame{
	
	public Vcr(){
		super("VCR");
		setSize(400, 100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JButton play = new JButton("Play");
		JButton stop = new JButton("Stop/Eject");
		JButton rew = new JButton("Rwd");
		JButton ff = new JButton("FF");
		JButton pause = new JButton("Pause");
		
		JPanel pane = new JPanel();
		pane.add(play);
		pane.add(stop);
		pane.add(rew);
		pane.add(ff);
		pane.add(pause);
		setContentPane(pane);
		//pack();
		setVisible(true);
		
	}
	

	
	public static void main(String[] args) {
		Vcr vcr = new Vcr();

	}

}
