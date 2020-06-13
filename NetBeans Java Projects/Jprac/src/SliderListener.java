
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

//***************************************************************** 
//  Represents the listener for all three sliders. 
//***************************************************************** 
abstract class SliderListener implements ChangeListener { 

//-------------------------------------------------------------
//  Gets the value of each slider, then updates the labels and 
//  the color panel. 
//-------------------------------------------------------------
    public void stateChanged (ChangeEvent event) { 
        int red, green, blue;
        red = rSlider.getValue(); 
        green = gSlider.getValue(); 
        blue = bSlider.getValue();
        
        rLabel.setText ("Red: " + red); 
        gLabel.setText ("Green: " + green); 
        bLabel.setText ("Blue: " + blue);
        
        colorPanel.setBackground (new Color (red, green, blue));
    }
}