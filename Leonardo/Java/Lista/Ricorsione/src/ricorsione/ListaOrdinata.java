/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ricorsione;

import java.util.Random;

/**
 *
 * @author Leonardo
 */
public class ListaOrdinata extends Lista{
    public ListaOrdinata(){
        super(null);    
    }
    
   public ListaOrdinata(int n, int maxInc) {
    super(null);
    Random r = new Random();
    Elemento ultimo = null;
    int valore = 0;
    for (int i = 0; i < n; i++) {
        valore+=r.nextInt(maxInc)+1;
        if (testa == null) {
            testa = new Elemento(r.nextInt(maxInc), null);
            ultimo = testa;
        } 
        else {                       
            ultimo.setNext(new Elemento(valore, null));
            ultimo = ultimo.getNext();
        }
    }
   }
   
   //inserimento
    void inserisciElemento (int n){
        if (testa==null){
            testa=new Elemento(n,null);
        }
        else if(n<testa.getN())
        {
            testa=new Elemento(n,testa);
        }
        else{
            Elemento e = testa;
            while (e.getNext()!=null && e.getNext().getN()<n)
            {
                e.setNext(e.getNext());
            }
            e.setNext(new Elemento(n,e.getNext()));
        }                    
    }  
    
    //estrazione 
    public Elemento estrazioneElemento(int n){
        Elemento estratto=null;
        if (testa==null)
        {
            return null;
        }
        else if (testa.getN()==n)
            {
                estratto=testa;
                testa=testa.getNext();
                estratto.setNext(null);
                return estratto;
            }
            else{
                Elemento prev=testa;
                for (Elemento e=testa.getNext();e !=null && e.getN()<=n;e=e.getNext())
                {
                    if(e.getN()==n)
                    {
                        estratto=e;
                        prev.setNext(e.getNext());
                        estratto.setNext(null);
                        return estratto;
                    }
                    else{
                        prev=prev.getNext();
                    }
                }     
                 return null;
            }               
    }
}
