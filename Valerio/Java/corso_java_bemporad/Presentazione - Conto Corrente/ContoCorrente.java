public class ContoCorrente {
  private double saldo;

  ContoCorrente(double saldo) {
    this.saldo = saldo;
  }

  public double saldo() {
    return saldo;
  }
  public void deposito(double importo) {
    saldo += importo;
  }
  public void   prelievo(double importo) {
    if (saldo>importo) saldo -= importo;
  }
}
