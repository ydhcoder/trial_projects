import java.awt.*;

public class CheckerBoard extends AnimationBase {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	/* This applet draws a red-and-black checker board.
	 * It is assumed that the size of the applet is 160 by 160
	 * pixels
	 */

	public void drawFrame(Graphics g) {
		int row; // Row number, from 0 to 7
		int col; // Column number, from 0 to 7
		int x,y; // Top-left corner of the square
		
		for( row = 0; row < 8; row++ ){
			for ( col = 0; col < 8; col++ ) {
				x = col*20;
				y = row*20;
				if( (row % 2) == (col % 2)) {
					g.setColor(Color.red);
				}
				else
					g.setColor(Color.black);
				g.fillRect(x,y,20,20);
			}
		}	// end of for loop
	}	// end paint()
}	// end class checkerboard
