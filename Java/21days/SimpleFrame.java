//******************************
// Simple framework for a frame
//******************************

import javax.swing.JFrame;

public class SimpleFrame extends JFrame{

    public SimpleFrame(){
        super ("Frame Title");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setVisible(true);
    
    }
    
    public static void main (String[] args){
        SimpleFrame sf = new SimpleFrame();
        sf.setVisible(true);
    }

}
