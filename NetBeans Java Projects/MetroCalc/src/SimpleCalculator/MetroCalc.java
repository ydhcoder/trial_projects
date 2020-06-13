/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SimpleCalculator;

/**
 *
 * @author Yeabsra Debebe
 */
public class MetroCalc {
    public static void main (String[] args) {
        
        Entrance ent = new Entrance();
        ent.setVisible(true);
        Home_Interface calc = new Home_Interface();
        
        try {
            for (int i = 0; i <= 100; i++) {
                Thread.sleep(80);
                ent.load_percent.setText(Integer.toString(i) + "%");
                ent.loadingBar.setValue(i);
                
                if (i == 100 ) {
                    ent.setVisible(false);
                    calc.setVisible(true);
                }
            }
        } 
        catch (InterruptedException e){
        } 
    }
}
