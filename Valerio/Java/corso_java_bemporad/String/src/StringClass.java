public class StringClass {
    private String s1 = "Mario";
    private String s2 = new String("Luigi");
    private String s3 = "Mario";
    /*
    * La stringa s2 è istanziata con l'obsoleta scrittura a costruttore.
    * le stringhe vengono salvate in un'area di memoria detta String pool,
    * quindi gli identificatori sono puntatori a stringhe.
    * La stringa s1 e s3 stanno puntando alla stessa stringa nello String pool,
    * ovvero puntano alla medesima aria di memoria
    */
    void change(String s) {
        String p = s3;
        s3 = s;
        System.out.println(p + " -> " + s3);
        // Se s3 != "Mario" allora viene creata una nuova stringa nello String pool
        // e s3 punterà a questa nuova stringa
    }

    void print() {
        System.out.println(s1 + '\n' + s2 + '\n' + s3);
    }

    void methods() {
        String p = s3;
        change("Mario");
        System.out.println();
        System.out.println("s.length(): " + s3.length());
        System.out.println("s.charAt(3): " + s3.charAt(3));
        System.out.println("s.indexOf(\"io\"): "+ s3.indexOf("io"));
        System.out.println("s.substring(0, 3): " + s3.substring(0, 3));
        System.out.println();
        change(p);
    }
}
