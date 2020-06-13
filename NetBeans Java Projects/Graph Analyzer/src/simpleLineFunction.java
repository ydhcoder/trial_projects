import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class simpleLineFunction extends JFrame {

	private static class LineDisplay extends JPanel {
		int width, height; // Dimensions of the panel in terms of number of pixels
		
		public void paintComponent(Graphics g) { // paints the line and grid desired
			super.paintComponent(g);
			g.setColor(Color.BLACK); // sets the painting color to black
			width = getWidth(); // gets the current width of the displayed window
			height = getHeight(); // gets the current height of the displayed window
			
			for (int lineNum = 0; lineNum <= 20; lineNum++) {
				int width2 = lineNum * width / 20;
				
				if (width2 == width/2) g.setColor(Color.BLUE);
				else g.setColor(Color.BLACK);
				g.drawLine(width2, 0, width2, height);
			}
			
			for (int lineNum = 0; lineNum <= 20; lineNum++) {
				int height2 = lineNum * height / 20;
				
				if (height2 == height/2) g.setColor(Color.BLUE);
				else g.setColor(Color.BLACK);
				
				g.setColor(Color.BLACK);
				g.drawLine(0, height2, width, height2);
			}
			g.setColor(Color.RED);
			g.drawLine(0, height, width, 0 );
		}
	}
	
	public static void main(String[] args) {
		JFrame window = new JFrame("Grid");
		JPanel content = new JPanel();
		LineDisplay Line = new LineDisplay();
		
		content.setLayout(new BorderLayout());
		content.add(Line, BorderLayout.CENTER);
		
		window.setContentPane(content);
		window.setSize(640, 480);
		window.setLocation(0,0);
		window.setVisible(true);
	
	}
}
