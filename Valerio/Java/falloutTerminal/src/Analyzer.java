import java.util.ArrayList;
import java.util.Scanner;

class Analyzer {
    private ArrayList<String> words;
    private Scanner k = new Scanner(System.in);
    private String choice;
    private int affinity;

    private boolean getMatch(String testingString) {
        int count = 0;
        for (int i = 0; i < choice.length(); i++)
            if (choice.charAt(i) == testingString.charAt(i))
                count++;
        return count == affinity;
    }

    private void getWords() {
        System.out.println("Inserisci le parole chiave (0 per terminare)");
        System.out.print("> ");
        words = new ArrayList<>();
        String w;
        do {
            w = k.next();
            if (!w.equals("0"))
                words.add(w.toUpperCase());
        } while (!w.equals("0"));
    }

    private void getChoice() {
        System.out.print("Inserisci la tua scelta: ");
        choice = k.next().toUpperCase();
        // Aggiungere controllo per stringa sbagliata
        System.out.print("Inserisci l'affinità: ");
        affinity = k.nextInt();
    }

    private void analyze() {
        ArrayList<String> match = new ArrayList<>();
        for (String word: words)
            if (getMatch(word))
                match.add(word);
        words = match;
    }

    private void printAnalisys() {
        System.out.println("Parole possibili:");
        for (String word: words)
            System.out.println(">\t" + word);
    }

    void terminal() {
        getWords();
        do {
            getChoice();
            analyze();
            printAnalisys();
        } while (words.size() > 1);
        System.out.println("\nHAI HACKERATO IL TERMINALE! 🤘");
    }
}