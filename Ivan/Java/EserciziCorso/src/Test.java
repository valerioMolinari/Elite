public class Test {
    public static void main(String[] args) {
        AClass ac = new AClass("Superclasse", true);
        BClass bc = new BClass("Sottoclasse", false);
        bc.viewAtrr();
        System.out.println(bc.st);
        ac.viewAtrr();
        
    }
    
}
