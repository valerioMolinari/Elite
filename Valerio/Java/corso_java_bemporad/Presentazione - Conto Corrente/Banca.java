 class Banca {

   public static void main(String[] args) {
     // Crea due istanze della classe ContoCorrente c1 e c2
     ContoCorrente c1 = new ContoCorrente(100);
     ContoCorrente c2 = new ContoCorrente(400);

     // Eseguo un deposito e un prelievo per il conto c1
     c1.deposito(500);
     c1.prelievo(200);

     c2.deposito(100);
     c2.prelievo(200);

     double saldo1 = c1.saldo();
     double saldo2 = c2.saldo();

     System.out.println("\nSaldo del conto c1 = "+saldo1+"\nSaldo del conto c2 = "+saldo2+"\n");
   }
}
