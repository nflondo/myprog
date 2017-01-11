//**********************************
// Ends program gracefully
//**********************************

import java.awt.event.*;

public class ExitWindow extends WindowAdapter{

	public void windowClosing(WindowEvent e){

		System.exit(0);
	}


}
