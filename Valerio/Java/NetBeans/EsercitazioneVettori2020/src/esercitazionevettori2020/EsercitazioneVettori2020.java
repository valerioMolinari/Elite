/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esercitazionevettori2020;
import java.util.Scanner;

/**
 *
 * @author mr.anderson2159
 */
public class EsercitazioneVettori2020 {

    public static long fattoriale(long n) {
        if (n <= 1)
            return 1;
        return n * fattoriale(n - 1);
    }
    
    public static long leggiPositivo() {
        Scanner tastiera = new Scanner(System.in);
        System.out.print("Inserisci un numero: ");
        return tastiera.nextInt();
    }
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        long n = leggiPositivo();
        System.out.println("Il fattoriale di "+n+" è "+fattoriale(n));
    }
    
}
