import java.awt.*;

public class MovingRects extends AnimationBase {

		private static final long serialVersionUID = 1L;

			public void init() { 
				// The init() method is called when the applet is first 
				// created and can be used to initialize the applet. 
				// Here, it is used to change the number of milliseconds 
				// per frame from the default 100 to 30. The faster 
				// animation looks better. setMillisecondsPerFrame(30); }
			}

                @Override
			public void drawFrame(Graphics g) {

				// Draw one frame in the animation by filling in the background
				// with a solid red and then drawing a set of nested black 
				// rectangles. The frame number tells how much the first
				// rectangle is to be inset from the borders of the applet.

				int width; // Width of the applet, in pixels. 
				int height; // Height of the applet, in pixels.

				int inset; // Gap between borders of applet and a rectangle. 
							// The inset for the outermost rectangle goes from 0 to 
							// 14 then back to 0, and so on, as the frameNumber varies.
				int rectWidth, rectHeight; // the size of one of the rectangles

				width = getWidth(); // find out the size of the drawing area 
				height = getHeight();

				g.setColor(Color.red); // fill the frame with red 
				g.fillRect(0,0,width,height);
				g.setColor(Color.black); // switch color to black
				inset = getFrameNumber() % 15; // get the inset for the outermost rect
				rectWidth = width - 2*inset - 1; // set size of the outermost rect 
				rectHeight = height - 2*inset - 1;
				while (rectWidth >= 0 && rectHeight >= 0) { 
					g.drawRect(inset,inset,rectWidth,rectHeight); 
					inset += 15; // rects are 15 pixels apart 
					rectWidth -= 30; // width decreases by 15 pixels on left and 15 on right 
					rectHeight -= 30; // height decreases by 15 pixels on top and 15 on bottom }
				}
				
			} // end drawFrame()
				
} // end class MovingRect