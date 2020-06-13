import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Test2 extends JFrame {
	
	private static class GridDisplay extends JPanel {
		int width, height;
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.setColor(Color.BLACK);
			width = getWidth();
			height = getHeight();
			for (int lineNum = 0; lineNum <= 10; lineNum++) {
				int width2 = lineNum * width / 10;
				
				if (width2 == width/2) g.setColor(Color.BLUE);
				else g.setColor(Color.BLACK);
				
				g.drawLine(width2, 0, width2, height);
			}
			
			for (int lineNum = 0; lineNum <= 10; lineNum++) {
				int height2 = lineNum * height / 10;
				
				if (height2 == height/2) g.setColor(Color.BLUE);
				else g.setColor(Color.BLACK);
				
				g.setColor(Color.BLACK);
				g.drawLine(0, height2, width, height2);
			}
		}
	}
	
	public static void main(String[] args) {
		JFrame window = new JFrame("Grid");
		JPanel content = new JPanel();
		GridDisplay grid = new GridDisplay();
		
		content.setLayout(new BorderLayout());
		content.add(grid, BorderLayout.CENTER);
		
		window.setContentPane(content);
		window.setSize(640, 480);
		window.setLocation(0,0);
		window.setVisible(true);
	
	}

}
