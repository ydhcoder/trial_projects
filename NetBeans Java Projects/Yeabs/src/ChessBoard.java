import java.awt.*;
public class ChessBoard extends AnimationBase {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	public void drawFrame(Graphics g) {
		int w, h, rowSize, columnSize, insetx, insety, row, column;
		w = h = 40;
		insetx = 40;
		insety = 40;
		rowSize = insetx + 40;
		columnSize = insety + 40;
		row = (rowSize - insetx) / 40;
		column = (columnSize - insety) / 40;
		while (insetx <= 320 && insety <= 320) {
			if ( (row % 2 == 0 && column % 2 == 0) || (row % 2 == 1 && column % 2 == 1) ) {
				g.setColor(Color.black);
				g.fillRect(insetx, insety, w, h);
			}
			else if ( (row % 2 == 1 && column % 2 == 0) || (row % 2 == 0 && column % 2 == 1)) {
				g.setColor(Color.white);
				g.fillRect(insetx, insety, w, h);
			}
			insetx += 40;
		}
		insetx = 40;
		insety = 40;
		while (insetx <= 320 && insety <= 320) {
			if ( (row % 2 == 0 && column % 2 == 0) || (row % 2 == 1 && column % 2 == 1) ) {
				g.setColor(Color.black);
				g.fillRect(insetx, insety, w, h);
			}
			else if ( (row % 2 == 1 && column % 2 == 0) || (row % 2 == 0 && column % 2 == 1)) {
				g.setColor(Color.white);
				g.fillRect(insetx, insety, w, h);
			}
			insetx += 40;
			insety += 40; 
		}
	}
}