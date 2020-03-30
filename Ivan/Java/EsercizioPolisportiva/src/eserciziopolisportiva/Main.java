package eserciziopolisportiva;

public class Main {
    public static void main(String[] args) {
        Archivio a = new Archivio(10);
        a.visualizza();
        System.out.println("La media dei premi è: "+ a.mediaPremio());
    }
    
}
