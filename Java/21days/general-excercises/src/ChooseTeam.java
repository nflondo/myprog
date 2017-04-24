import javax.swing.*;

public class ChooseTeam extends JFrame {
	JRadioButton[] teams = new JRadioButton[4];
	
	public ChooseTeam(){
		super("Choose Team");
		setSize(140, 190);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		teams[0] = new JRadioButton("Colorado");
		teams[1] = new JRadioButton("Dallas", true);
		teams[2] = new JRadioButton("New Jersey");
		teams[3] = new JRadioButton("Philadelphia");
		
		JPanel pane = new JPanel();
		
		ButtonGroup group = new ButtonGroup();
		for (int i = 0; i < teams.length; i++){
			group.add(teams[i]);
			pane.add(teams[i]);						
		}
		setContentPane(pane);
		setVisible(true);		
		
	}
	
	public static void main(String[] args) {
		ChooseTeam ct = new ChooseTeam();
	}

}
