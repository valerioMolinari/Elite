/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fattoriale;

import java.util.Scanner;

/**
 *
 * @author Cristian
 */
public class Fattoriale
{    
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Inserisci n: ");
        int n = in.nextInt();
        System.out.println("Fattoriale di " + n + " = " + Ricorsione.fattoriale(n));
    }
    
}
