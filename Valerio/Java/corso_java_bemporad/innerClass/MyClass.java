//  Creiamo una public class (se non è public nella main non gira)
public class MyClass {
  //  Creiamo due private int
  private int x, y;

  //  Creiamo una inner class che contiene solo un metodo che stampa la x e la y della sua classe superiore
  //  ed è in grado di farlo poiché le eredita
  class InnerClass {
    void messaggio() {
      System.out.println("\nMyClass $ Inner: " + x + " " + y);
    }
  }
  //  Creiamo un metodo che crea una nuova istanza della InnerClass, aggiorna i valori delle private int
  //  ed esegue il metodo della InnerClass, ovvero stampa il messaggio
  public void MyMethod() {
    InnerClass ic = new InnerClass();
    x = 10;
    y = 20;
    ic.messaggio();
  }
}
