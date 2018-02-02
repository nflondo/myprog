import java.awt.event.*;
import javax.swing.*;

import java.awt.*;

public class TitleBar extends JFrame implements ActionListener {
	JButton b1;
	JButton b2;
	
	public TitleBar(){
		super("Title Bar");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		b1 = new JButton("Rosencrantz");
		b2 = new JButton("Guildenstern");
		b1.addActionListener(this);
		b2.addActionListener(this);
		FlowLayout flow = new FlowLayout();
		setLayout(flow);
		add(b1);
		add(b2);
		pack();
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent evt){
		Object source = evt.getSource();
		if (source == b1){
			setTitle("Rosencrantz");
		}else if (source == b2){
			setTitle("Guildenstern");		
		}
		repaint();
	}
	
	private static void setLookAndFeel() {
        try {
            for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println("Couldn't use the system look and feel: " + e);
        }
    }
	public static void main(String[] args){
		TitleBar frame = new TitleBar();
	}
}
