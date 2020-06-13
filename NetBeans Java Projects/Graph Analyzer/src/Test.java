/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.GradientPaint;
import java.awt.GridLayout;
import javax.swing.JApplet;
import java.awt.GridBagLayout;

public class Test extends JApplet {
  
    private static final long serialVersionUID = 7666141551123433848L;

    @Override
    public void init () {}
    
    int width, height;
    
    public void paintComponent(Graphics g) {
        super.paintComponents(g);
        width = getWidth();
        height = getHeight();
        g.setColor(Color.BLACK);
        g.drawLine(width / 2, 0, width / 2, height);          
        g.drawLine(0, height/2, width, height/2);
    }
}
