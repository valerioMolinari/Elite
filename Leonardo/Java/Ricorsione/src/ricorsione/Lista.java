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
public class Lista {
    protected Elemento testa=null;
    protected int lunghezza=0;
    
    
    public Lista (int n,int limite){
        for (int i =0;i<n;i++)
        {
            testa=new Elemento((int) (Math.random()*limite),testa);
        }
        lunghezza=n;
    }    
    
    public Lista (Elemento e)
    {
        testa=e;
        lunghezza=1;
    }
    
    public void aggiungi(Elemento e)
    {
        Elemento i=testa;
        while(i.getNext()!=null)
        {
            i=i.getNext();
        }
        i.setNext(e);                
    }

    public Elemento getTesta() {
        return testa;
    }

    public int getLunghezza() {
        return lunghezza;
    }
    
    public void Visualizza(){
        //visualizza con while
        Elemento e=testa;
        while (e!=null){
            System.out.print(e.getN()+" ");
            e=e.getNext();
        }
        System.out.println("");
    }
    
    public void Visualizza2(){
//visualizza con for        
        for (Elemento e=testa;e!=null;e=e.getNext()){
            System.out.print(e.getN()+" ");            
        }
        System.out.println("");
    }
    
    public int somma(){       
       int somma=0;
       for (Elemento e=testa; e!=null;e=e.getNext())
       {           
           somma+=e.getN();
       }
       return somma;
    }
    
    public int maggiori(int n){
        int n_maggiori=0;
        for (Elemento e=testa;e!=null;e=e.getNext()){
            if (e.getN()>n)          
            {
                n_maggiori++;
            }
        }
        return n_maggiori;
    }
    
    public boolean verificaOrdinata(){
        if (testa!=null)
        {
            for (Elemento e=testa;e.getNext()!=null;e=e.getNext()){
                if(e.getN()>e.getNext().getN())
                {
                    return false;
                }            
            }
        }    
        return true;
    }
    
    public boolean presente(int n){
        for (Elemento e=testa;e!=null;e=e.getNext()){
            if (n==e.getN())
            {
                return true;
            }
        }
        return false;
    }
    
    public int posizioneElemento(int n)
    {
        int contatore=0;
        for (Elemento e=testa;e!=null;e=e.getNext()){            
            if (e.getN()== n)
            {
                return contatore;
            }
            contatore++;
        }
        return -1;
    }
    
    public int lunghezzaLista(){
      return lunghezzaLista(testa);
   }
    
    private int lunghezzaLista(Elemento t){
       if (t==null)
       {return 0;}
       else 
       {
           return 1+lunghezzaLista(t.getNext());
       }
    }
    
    public boolean cercaElemento(int n){
      return cercaElementoRic(testa,n);
   }
    
    private boolean cercaElementoRic(Elemento t, int n){
        if(t==null)
        {
            return false;
        }
        else
        {
            if (t.getN()==n)
            {
                return true;
            }
        }
        return cercaElementoRic(t.getNext(),n);
    }
    public int superioriDi(int n){
        int contatore=0;
        for (Elemento e=testa;e!=null;e=e.getNext())
        {
            if(e.getN()>n)
            {
                contatore++;
            }
        }
        return contatore;
    }
    public int superioriDiRic(int n)
    {
        return superioriDiRic(n,testa);
    }
    private int superioriDiRic(int n, Elemento e){
        if(e==null)
        {
            return 0;
        }
        else 
            return e.getN()> n ? 1+superioriDiRic(n, e.getNext()) : superioriDiRic(n, e.getNext());
    }
    
    public boolean verificaOrdinataCrescenteRic()
    {
        if (testa==null)
        {
            return true;
        }
        else
        {
            return verificaOrdinataCrescenteRic(testa);
        }
    }
    
    private boolean verificaOrdinataCrescenteRic(Elemento e){
        if (e.getNext()==null)
        {
            return true;
        }
        else
        {
            return e.getN()<e.getNext().getN() && verificaOrdinataCrescenteRic(e.getNext());
        }
    }
    
    public Lista creaListaMaggioriRic(int n){
        return new Lista(creaListaMaggioriRic(testa,n));
    }
    
    private Elemento creaListaMaggioriRic(Elemento e,int n){
        if (e==null)
        {
            return null;
        }
        else
        {
            if(e.getN()>n)
            {
                return new Elemento(e.getN(),creaListaMaggioriRic(e.getNext(),n));
            }
            else
            {
                return creaListaMaggioriRic(e.getNext(),n);
            }
        }
    }
              
    
    
    public Lista creaListaMaggiori(int n)
    {
        if (testa!=null)
            return creaListaMaggiori(testa,n);
        return null;
    }
    private Lista creaListaMaggiori(Elemento e,int n){        
        Elemento copia = null;
        for (Elemento i = e;i!=null;i=i.getNext())
        {
            if (i.getN()>n)
            {
                copia=new Elemento(i.getN(),copia);
            }
        }
        return new Lista(copia);
    }
    
    
    private Lista inverti() {
        Elemento lista = null;
        for (Elemento e = testa; e != null; e = e.getNext())
            lista = new Elemento(e.getN(), lista);
        return new Lista(lista);
    }
    public Lista copiaMaggiore1(int n) {
        Elemento lista = null;
        for (Elemento e = testa; e != null; e = e.getNext())
            if (e.getN() > n)
                lista = new Elemento(e.getN(), lista);
        return new Lista(lista).inverti();
    }

    public Lista copiaMaggiore2(int n) {
        Elemento copia = null;
        Elemento ultimo = null;
        for (Elemento e = testa; e != null; e = e.getNext()) {
            if (e.getN() > n && copia == null) {
                copia = new Elemento(e.getN(), null);
                ultimo = copia;
            }
            else if (e.getN() > n) {                
                    ultimo.setNext(new Elemento(e.getN(), null));
                    ultimo=ultimo.getNext();
                    }
        }
        return new Lista(copia);
    }
}