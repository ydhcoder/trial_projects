public class SymmetricBrighten extends Brighten {
    /** 
     * Brighten the specified square, at position (row,col) and its 
     * horizontal and vertical reflections. This overrides the
     * brighten() method from the RandomBrighten class, which just 
     * brightens one square. 
     */ 
    void brighten(int row, int col) { 
        super.brighten(row, col); 
        super.brighten(ROWS - 1 - row, col); 
        super.brighten(row, COLUMNS - 1 - col); 
        super.brighten(ROWS - 1 - row, COLUMNS - 1 - col); 
    }
} // end class SymmetricBrighten