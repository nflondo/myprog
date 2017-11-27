import java.awt.*;
import javax.swing.*;

public class FeedBar2 extends JFrame {
	
	public FeedBar2(){
		super("FeedBar 2");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//setLookAndFeel();
		// create icons
		ImageIcon loadIcon = new ImageIcon("load.gif");
		ImageIcon saveIcon = new ImageIcon("save.gif");
		ImageIcon subIcon = new ImageIcon("subscribe.gif");
		ImageIcon unsubIcon = new ImageIcon("unsubscribe.gif");
		// create buttons
		JButton load = new JButton("Load", loadIcon);
		JButton save = new JButton("Save", saveIcon);
		JButton sub = new JButton("Subscribe", subIcon);
		JButton unsub = new JButton("Unsubscribe", unsubIcon);
		// add buttons to toolbar
		JToolBar bar = new JToolBar();
		bar.add(load);
		bar.add(save);
		bar.add(sub);
		bar.add(unsub);
		// create menu
		JMenuItem j1 = new JMenuItem("Load");
		JMenuItem j2 = new JMenuItem("Save");
		JMenuItem j3 = new JMenuItem("Subscribe");
		JMenuItem j4 = new JMenuItem("Unsubscribe");
		JMenuBar menubar = new JMenuBar();
		JMenu menu = new JMenu("Feeds");
		menu.add(j1);
		menu.add(j2);
		menu.add(j3);
		menu.add(j4);
		menubar.add(menu);
		// prepare user interface
		JTextArea edit = new JTextArea(8, 40);
		JScrollPane scroll = new JScrollPane(edit);
		BorderLayout bord = new BorderLayout();
		setLayout(bord);
		add("North", bar);
		add("Center", scroll);
		setJMenuBar(menubar);
		pack();
		setVisible(true);
		
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel(
					"com.sun.java.swing.plaf.nimbus.NimbusLookAndfeel"
					);
			SwingUtilities.updateComponentTreeUI(this);
		}catch (Exception e){
			System.err.println("Couldn't use the system "
					+ "look and feel: " + e);
			
		}
		
	}
	
	public static void main(String[] args){
		FeedBar2 frame = new FeedBar2();
	}
}
