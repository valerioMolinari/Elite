/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mcd;

/**
 *
 * @author Cristian
 */
import java.util.Scanner;

public class Mcd
{
  
  public static void main(String[] args)
  {
    int ricomincia;
    do 
    {
      int n, m;
      Scanner in = new Scanner(System.in);
      System.out.print("Inserisci n: ");
      n = in.nextInt();
      System.out.print("Inserisci m: ");
      m = in.nextInt();
      if (n < m)
      {
        int temp = n;
        n = m;
        m = temp;
      }
      System.out.printf("MCD(%d,%d) = %d\n",n, m, mcd(n,m));
      System.out.printf("Calcolare un'altro MCD?\n1) SI\n2) NO\n> ");
      ricomincia = in.nextInt();
    }while(ricomincia == 1);
  }
  
  public static int mcd (int n, int m)
  {
    int copy_m = m;
    return mcd (n, m, copy_m);
  }
  
  private static int mcd (int n, int m, int copy_m)
  {
  	if (n == 0 && m == 0)
  		return 0;
  	else if (n > 0 && m == 0)
  		return n;
  	else if (n < 0 || m < 0)
  	{
  		System.out.println("Usa numeri non negativi");
  		return -1;	
  	}
  	else if ((n == 1 && m == 1) || copy_m == 1)
  		return 1;
  	else 
  	{
  		if ((n%copy_m == 0) && (m%copy_m == 0))
                    return copy_m;  			
  		else return mcd(n, m, --copy_m);
  	}
  }
}
