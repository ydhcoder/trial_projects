
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Yeabsra
 */
import java.util.Scanner;

public class Guess {

    public static void main (String[] args) {
        double x,y,z,r;
        Scanner stdin = new Scanner (System.in);
        System.out.println("Enter the first number:");
        x = stdin.nextDouble();
        System.out.println("Enter the second number:");
        y = stdin.nextDouble();
        System.out.println("Enter the third number:");
        z = stdin.nextDouble();

        r = Math.sqrt(x*x + y*y + z*z);

        System.out.println("The three dimensional resultant is " + r);

    }
}
    

