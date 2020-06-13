/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Warehouse;

/**
 *
 * @author Yeabsra Debebe
 */
public class StartUp {
    public static void main (String[] args) {
        Scene scene;
        scene = new Scene();
        scene.setVisible(true);
        Home home = new Home();
        
        int count = 1;
        
        try {
            for (int i = 0; i <= 100; i++) {

                Thread.sleep(60);

                switch(count) {
                    case (1): {
                        scene.queueLabel.setText("Preparing your interface.");
                        count++;
                        break;
                    }
                    case(2): {
                        scene.queueLabel.setText("Preparing your interface..");
                        count++;
                        break;
                    }
                    case(3): {
                        scene.queueLabel.setText("Preparing your interface...");
                        count = 1;
                        break;
                    }     
                }

                if(i > 75) {
                    scene.lastLabel.setText("Almost there...");
                }
                
                scene.progress.setValue(i);
                
                if (i == 100) {
                    scene.setVisible(false);
                    home.setVisible(true);
                }
            }
        } 
        catch (InterruptedException e) {
        }
        
    }
    
}
