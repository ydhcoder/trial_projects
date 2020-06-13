/**
 * This program shows an animation in which a small square grows from the 
 * center of the window until it fills the whole mosaic.  The filled square
 * is built up by a series of outlines of squares, which get brighter as
 * they get bigger.  After the entire mosaic is filled, the square is 
 * erased, there is a one-second delay, and the process repeats.  This
 * continues until the user closes the window.  This program depends on 
 * the non-standard classes Mosaic and MosaicCanvas.
 */

public class MosaicStrobe {

   
   /**
    * Opens a mosaic window then play the "strobe" animation over and over
    * as long as the window is still open.
    */
   public static void main(String[] args) {
      Mosaic.open(41,41,6,6);
      while ( Mosaic.isOpen() ) {
          Mosaic.delay(1);
          strobe();
          Mosaic.fill(0,0,0);
      }
   }  // end main()


   /**
    * Draw the animation, showing a square that starts at the center of the
    * mosaic and grows to fill the whole window.  The outline added to the
    * square at each step square gets brighter as the square grows.  Note 
    * that the animation ends immediately if the user closes the window.
    */
   static void strobe() {

      int rectSize;    // The number of rows (and columns) in the part of the square
                       // that has been drawn so far.
      int left;        // The leftmost column in the next square outline to be drawn.
      int top;         // The topmost row in the next square outline.
      int brightness;  // The brightness of the outline, which increases from
                       //   50 to a maximum of 250 as the square grows.  This
                       //   quantity is used for all three color components,
                       //   giving a gray color that brightens to white.

      left = 20;       // Start at the center of the 41-by-41 mosaic.
      top = 20;
      
      rectSize = 1;  
      brightness = 50;

      while (left >= 0 && Mosaic.isOpen()) {

         /* Draw the outline in gray, pause so the user can see it. */

         outlineRectangle(top,left,rectSize,rectSize,brightness,brightness,brightness);
          Mosaic.delay(200);
          
          /*  Now, adjust the parameters to get ready to draw the next outline. */

          left--;
          top--;
          rectSize += 2;
          brightness += 10;
      }
      
   }
   

   /**
    * Draws the outline of a rectangle in the mosaic window by setting the color
    * of each little square on that outline. 
    * @param top gives the starting row, at the top edge of the rectangle
    * @param left gives the starting column, at the left edge of the rectangle
    * @param height gives the number of rows in the rectangle
    * @param width gives the number of columns in the rectangle
    * @param red the red component of the color, in the range 0 to 255
    * @param green the green component of the color
    * @param blue the blue component of the color
    */
   static void outlineRectangle(int top, int left, int height, int width, int r, int g, int b) {
      int row, col;
      for ( row = top;  row < top + height;  row++ ) {
         Mosaic.setColor(row, left, r, g, b);
         Mosaic.setColor(row, left + width - 1, r, g, b);
      }
      for ( col = left;  col < left + width; col++ ) {
         Mosaic.setColor(top, col, r, g, b);
         Mosaic.setColor(top + height - 1, col, r, g, b);
      }
   }  // end outlineRectangle()


}  // end class MosaicStrobe
