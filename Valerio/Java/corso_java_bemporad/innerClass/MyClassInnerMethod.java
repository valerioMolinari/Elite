
public class MyClassInnerMethod {
  private int x, y;

  //  Il cambio sta nello scope... ritengo che l'utilità possa essere al livello di prestazioni
  public void MyMethod() {
    class InnerClass {
      void messaggio() {
        System.out.println("\nMyClassInnerMethod $ Inner: " + x + " " + y + "\n");
      }
    }
    InnerClass ic = new InnerClass();
    x = 10;
    y = 20;
    ic.messaggio();
  }
}
