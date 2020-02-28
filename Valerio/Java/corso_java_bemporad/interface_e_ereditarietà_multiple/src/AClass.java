public class AClass implements IMyInt1, IMyInt2{
    // Errore: La classe eredita due versioni di myMethod() non connesse fra loro
    // È necessario fare l'override

    @Override
    public void myMethod() {
        System.out.println("myMethod in AClass");
    }
}