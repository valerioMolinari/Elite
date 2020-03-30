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
public class Elemento {
    protected int n;
    protected Elemento next=null;

    public Elemento(int n, Elemento next) {
        this.n = n;
        this.next = next;
    }

    public int getN() {
        return n;
    }

    public Elemento getNext() {
        return next;
    }

    public void setN(int n) {
        this.n = n;
    }

    public void setNext(Elemento next) {
        this.next = next;
    }
    
}
