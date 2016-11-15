//***************************************************************
// Generic listener for window components
//***************************************************************
import java.awt.event.*;

public class GenericWindowListener extends WindowAdapter
{
	//Terminates the program when window is closed
	public void windowClosing (WindowEvent event)
	{
		System.exit(0);
	}

} // GenericWindowListener
