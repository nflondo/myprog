import java.awt.*;
import javax.swing.*;

public class SurveyFrame extends JFrame {
	public SurveyFrame(){
		super("Survey");
		setSize(290, 140);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		// This object is based on the SurveyWizard.java class
		SurveyWizard wiz = new SurveyWizard();
		add(wiz);
		setVisible(true);
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel(
					"javax.swing.plaf.metal.MetalLookAndFeel"
					);
			SwingUtilities.updateComponentTreeUI(this);		
			
		} catch (Exception e){
			System.err.println("Can't set look and feel: " + e);
		}
	} // setLookAndFeel
	
	public static void main(String[] args) {
		SurveyFrame surv = new SurveyFrame();
	}
}
