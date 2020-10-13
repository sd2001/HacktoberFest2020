import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;

public class demo {
	
	public static void main(String[] args) {
		blue b = new blue();
		b.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		b.setSize(350, 190);
		b.setVisible(true);
	}
}

class blue extends JFrame{
	
	private JTextField item1;
	private JTextField item2;
	private JTextField item3;
	private JPasswordField pw;
	
	public blue() {
		super("title");
		setLayout(new FlowLayout());
		
		item1 = new JTextField(10);
		add(item1);
		
		item2 = new JTextField("entr text here");
		add(item2);
		
		item3 = new JTextField("uneditable", 20);
		item3.setEditable(false);
		add(item3);
		
		pw = new JPasswordField("mypass");
		add(pw);
		
		thehandler handler = new thehandler();
		
		item1.addActionListener(handler);
		item2.addActionListener(handler);
		item3.addActionListener(handler);
		pw.addActionListener(handler);
		
	}
	
	private class thehandler implements ActionListener{
		
		public void actionPerformed(ActionEvent e) {
			
			String str = "";
			
			if(e.getSource()==item1)
				str = String.format("Field1 is: %s", e.getActionCommand());
			else if(e.getSource()==item2)
				str = String.format("Field2 is: %s", e.getActionCommand());
			else if(e.getSource()==item3)
				str = String.format("Field3 is: %s", e.getActionCommand());
			else if(e.getSource()==pw)
				str = String.format("Password field is: %s", e.getActionCommand());
			
			JOptionPane.showMessageDialog(null, str);
		}
	}
}
