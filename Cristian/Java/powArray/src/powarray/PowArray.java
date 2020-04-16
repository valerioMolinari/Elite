package powarray;

import java.awt.Rectangle;
import java.util.Scanner;

/**
 *
 * @author Cristian
 */
public class PowArray
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        int lunghezza_array, potenza;
        System.out.println("Quanti elementi vuoi elaborare?");
        lunghezza_array = in.nextInt();
        System.out.println("A che potenza li vuoi elevare?");
        potenza = in.nextInt();
        //System.out.println("Potenza: " + potenza);
        double[] a = createArray(lunghezza_array);
        printArray(a);
        double[] new_a = powArray(a, potenza);
        //System.out.println(Arrays.toString(new_a));
        printArray(new_a);
        System.out.println();
        System.out.println();
        System.out.println();
        
        Rectangle box = new Rectangle(0, 0, 100, 200);
        System.out.println(box);
        box.translate(50, 100);
        System.out.println(box);
    }
        
    public static void printArray(double[] a)
    {
        System.out.print("[");
        for (int i = 0; i<a.length; i++)
            if (i == a.length - 1)
                System.out.println(a[i]+ "]");
            else
                System.out.print(a[i]+ ", ");
    }
    
    public static double[] powArray(double[] a, int b)
    {
        double[] new_a = new double[a.length];
        System.arraycopy(a, 0, new_a, 0, a.length);
        
        for (int i = 0; i<b-1; i++)
            for (int c = 0; c<a.length; c++)
                new_a[c] *= a[c];
        
        return new_a;
    }
    
    public static double[] createArray(int n)
    {
        Scanner in = new Scanner(System.in);
        double[] a = new double[n];
        for (int i = 0; i<a.length; i++)
        {
            System.out.print("Inserisci elemento a["+i+"]: ");
            a[i]= in.nextDouble();
        }
        return a;
    }
    
}
