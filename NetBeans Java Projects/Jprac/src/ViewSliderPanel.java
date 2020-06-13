//******************************************************************** 
//  ViewSliderPanel.java       Authors: Lewis/Loftus // 
//  Represents the slider control panel for the ViewColors program. 
//********************************************************************

import java.awt.*; 
import javax.swing.*; 

public class ViewSliderPanel extends JPanel { 
    private JPanel colorPanel; 
    private JSlider rSlider, gSlider, bSlider; 
    private JLabel rLabel, gLabel, bLabel;
//----------------------------------------------------------------
//  Sets up the sliders and their labels, aligning them along 
//  their left edge using a box layout. 
//----------------------------------------------------------------
    public ViewSliderPanel (JPanel panel) { colorPanel = panel;
        rSlider = new JSlider (JSlider.HORIZONTAL, 0, 255, 0); 
        rSlider.setMajorTickSpacing (50); 
        rSlider.setMinorTickSpacing (10); 
        rSlider.setPaintTicks (true); 
        rSlider.setPaintLabels (true); 
        rSlider.setAlignmentX (Component.LEFT_ALIGNMENT);
        
        gSlider = new JSlider (JSlider.HORIZONTAL, 0, 255, 0); 
        gSlider.setMajorTickSpacing (50); gSlider.setMinorTickSpacing (10); 
        gSlider.setPaintTicks (true); gSlider.setPaintLabels (true); 
        gSlider.setAlignmentX (Component.LEFT_ALIGNMENT);
        
        bSlider = new JSlider (JSlider.HORIZONTAL, 0, 255, 0); 
        bSlider.setMajorTickSpacing (50); 
        bSlider.setMinorTickSpacing (10); 
        bSlider.setPaintTicks (true); 
        bSlider.setPaintLabels (true); 
        bSlider.setAlignmentX (Component.LEFT_ALIGNMENT);
        
        SliderListener listener = new SliderListener(); 
        
        rSlider.addChangeListener (listener); 
        gSlider.addChangeListener (listener); 
        bSlider.addChangeListener (listener);
        rLabel = new JLabel ("Red: 0"); 
        rLabel.setAlignmentX (Component.LEFT_ALIGNMENT); 
        gLabel = new JLabel ("Green: 0"); 
        gLabel.setAlignmentX (Component.LEFT_ALIGNMENT);
        bLabel = new JLabel ("Blue: 0"); 
        bLabel.setAlignmentX (Component.LEFT_ALIGNMENT);
        setLayout (new BoxLayout (this, BoxLayout.Y_AXIS)); 
        
        add (rLabel); 
        add (rSlider); 
        add (Box.createRigidArea (new Dimension (0, 20)));
        add (gLabel); 
        add (gSlider);
        add (Box.createRigidArea (new Dimension (0, 20))); 
        add (bLabel); 
        add (bSlider);
    }
}