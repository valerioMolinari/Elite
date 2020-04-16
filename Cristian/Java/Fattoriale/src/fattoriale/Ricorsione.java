/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fattoriale;

/**
 *
 * @author Cristian
 */
public class Ricorsione 
{
    static double fattoriale(int n)
    {
        if (n==0)
            return 1;
        else return n*fattoriale(n-1);
    }
}
