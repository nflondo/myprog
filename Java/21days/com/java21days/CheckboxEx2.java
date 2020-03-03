package com.java21days;

import java.awt.*;
import java.awt.event.*;

public class CheckboxEx2 implements ItemListener
{
	Frame jf;
	Checkbox chk1, chk2;
	Label label1;

	CheckboxEx2()
	{
		jf= new Frame("Checkbox");
		chk1 = new Checkbox("Water");
		chk2 = new Checkbox("Coffee");
		label1 = new Label();
		
		jf.add(chk1);
		jf.add(chk2);
		
		chk1.addItemListener(this);
		chk2.addItemListener(this);
		
		jf.setLayout(new FlowLayout());
		jf.setSize(232,150);
		jf.setVisible(true);		
	}

	public void itemStateChanged(ItemEvent ie)
	{
		Checkbox ch =(Checkbox)ie.getItemSelectable();
		if(ch.getState()==true)
		{
			label1.setText(ch.getLabel()+ " is checked");
			jf.add(label1);
			jf.setVisible(true);
		}
		else
		{
			label1.setText(ch.getLabel()+ " is unchecked");
			jf.add(label1);
			jf.setVisible(true);
		}
	}
	
	public static void main(String... ar)
	{
		new CheckboxEx2();
	}

}
