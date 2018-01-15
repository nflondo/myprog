/* Solution to Chapter 11, Exercise 2 in Teach Yourself Java in 21 Days (Covering Java 8
   and Android by Rogers Cadenhead. */

import java.awt.*;
import javax.swing.*;
import javax.swing.UIManager.*;

class AlphabetBorder extends JFrame {
    JButton north = new JButton("North");
    JButton south = new JButton("South");
    JButton east = new JButton("East");
    JButton west = new JButton("West");
    AlphabetPanel alpha = new AlphabetPanel();

    AlphabetBorder() {
        super("AlphabetBorder");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(240, 300);
        setLayout(new BorderLayout());
        add("North", north);
        add("South", south);
        add("East", east);
        add("West", west);
        add("Center", alpha);
        setVisible(true);
    }
    
    private static void setLookAndFeel() {
        try {
            for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println("Couldn't use the system look and feel: " + e);
        }
    }

    public static void main(String[] arguments) {
        AlphabetBorder.setLookAndFeel();
        JFrame frame = new AlphabetBorder();
    }
}

class AlphabetPanel extends JPanel {
    JButton a = new JButton("Alibi");
    JButton b = new JButton("Burglar");
    JButton c = new JButton("Corpse");
    JButton d = new JButton("Deadbeat");
    JButton e = new JButton("Evidence");
    JButton f = new JButton("Fugitive");

    AlphabetPanel() {
        FlowLayout lm = new FlowLayout(FlowLayout.LEFT);
        setLayout(lm);
        add(a);
        add(b);
        add(c);
        add(d);
        add(e);
        add(f);
    }

}