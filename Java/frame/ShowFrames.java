//***************************************************************
// Demonstrates the use of frames
//***************************************************************

//package frame;
//import FrameDemo;
//import GenericWindowListener;
import java.awt.event.*;

public class ShowFrames
{
	// Creates and displays an empty frame
	public static void main (String[] args)
	{
		FrameDemo frame = new FrameDemo();
		frame.addWindowListener (new GenericWindowListener());
		frame.show();
	} // main

} //ShowFrames 
