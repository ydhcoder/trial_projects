/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.Security.Key_Generator;

/**
 *
 * @author Yeabsra Debebe
 */
import static java.lang.Math.random;
public class RandKey {
    /**
     *
     * @param charSize
     * @return genString
     */
    public static String keyGen(int charSize) {
        String NumValue = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_-+=[]{}:;'";
        String genString = "";
        for (int i = 0; i <= charSize; i++) {
            int randValue;
            randValue = NumValue.charAt((int)(random()*83));
            genString += randValue;
        }
        return genString;
    }
    
    public static void main (String[] args) {
        String str = keyGen(64);
        System.out.println(str);
    }
}
