/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ricorsione;

/**
 *
 * @author Leonardo
 */
public class Ricorsione {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Ricorsione r =new Ricorsione();
        Lista lista= new Lista(20,50);
        ListaOrdinata lo = new ListaOrdinata(50,2);
        
        int n=35;
        double p = r.fattorialeRic(5);
        double f = fattoriale(5);
        double h = Ricorsione.fattorialeRic(5);
        
        double u = Ricorsione.potenzaRic(2,4);
        
        lista.Visualizza();        
        System.out.print("La lista è lunga: " +lista.lunghezzaLista()+"\n");
        System.out.print("Fibonacci di 11: " + r.fibonacciRic(11) +"\n");
        System.out.print("l'elemento "+ n + " è presente? " +lista.cercaElemento(n)+"\n");
        System.out.print("Numero di elementi maggiori di  "+ n + " nella lista = " +lista.superioriDi(n)+"\n");
        System.out.print("Numero di elementi maggiori di  "+ n + " nella lista = " +lista.superioriDiRic(n)+"\n");
        System.out.print("La lista è ordinata in ordine crescente? "+ lista.verificaOrdinataCrescenteRic()+ "\n");
        lista.creaListaMaggiori(n).Visualizza();
        lista.creaListaMaggioriRic(n).Visualizza();
        System.out.print(f+"\n");
        System.out.print(h+"\n");
        System.out.print(p+"\n");
        System.out.print(u+"\n");
        lo.Visualizza();
        Elemento e=lo.estrazioneElemento(10);
        if (e!=null)
            System.out.print("Estratto = " + e.getN() + "\n");
        lo.Visualizza();
        
    }
    
    
   static public double fattorialeRic(int n){
        if (n==0)
        {
            return 1;
        }
        else{
            return (n*fattorialeRic(n-1));
        }
    }
   
   static public double fattoriale(int n){
       double acc=1;
       for(int i = 2;i<=n;i++)
       {
           acc*=i;
       }
       return acc;
    }
   
   static public double potenzaRic(double b, long e){
       if (e==0)
       {
           return 1;
       }      
       else
       {
           return b*potenzaRic(b,e-1);
       }
   }
   
   public long fibonacciRic(int n){
       if (n<=2)
       {
           return 1;
       }
       else
           return fibonacciRic(n-1)+fibonacciRic(n-2);
   }
   
   public long fibonacci(int n){
       long fnm1=1,fn=1;
       long t;
       for (int i=3;i<=n;i++)
       {
           t=fnm1+fn;
           fnm1=fn;
           fn=t;
           
           fn=fnm1+fn;
           fnm1=fn-fnm1;           
       }
       return fn;
   }
   
   static public double potenzaRic2(double b, long e){
       if (e==0)
       {
           return 1;
       }      
       else if (e%2==0)
       {
           return potenzaRic2(b*b,e/2);
       }
       else
       {
           return b*potenzaRic2(b*b, e/2);
       }
   }
   
   public double potenza3(double b, long e){
       double acc=1;
       while(e!=0)
       {
           if(e%2!=0)
           {
               acc*=b;
           }                        
           b=b*b;
           e=e/2;                                 
       }
       return acc;
   }
}
