import java.awt.*;

public class ChessBoard2 extends AnimationBase {
	private static final long serialVersionUID = 1L;
	/* This applet draws a white-and-black checker board.
	 * It is assumed that the size of the applet is 160 by 160
	 * pixels
	 */

	public void drawFrame(Graphics g) {
		int row; // Row number, from 0 to 7
		int col; // Column number, from 0 to 7
		int x,y; // Top-left corner of the square
		
		for( row = 0; row < 8; row++ ){
			for ( col = 0; col < 8; col++ ) {
				x = col*80;
				y = row*80;
				if( (row % 2) == (col % 2)) {
					g.setColor(Color.black);
				}
				else
					g.setColor(Color.white);
				g.fillRect(x,y,80,80);
			}
			g.setColor(Color.black);
			g.drawRect(0, 0, 640, 640);
		}	// end of for loop
	}	// end paint()
}	// end class chessboard2
