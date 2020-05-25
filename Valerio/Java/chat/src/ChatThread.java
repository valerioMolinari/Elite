import java.io.*;
import java.net.*;
import java.util.*;

public class ChatThread extends Thread {
    protected static final int LMESS = 256; // lunghezza massima messaggio
    protected static final int LNOME = 16; // lunghezza massima nome di un utente
    protected static final char SEPARATORE = '\n';
    protected static int pausa;
    protected static ChatServer cs;
    protected static Vector<ChatThread> threads = new Vector<>();
    protected static String elencoNomi = "" + SEPARATORE;

    protected Socket s;
    protected DataInputStream in;
    protected DataOutputStream out;
    protected String nome = "";

    public ChatThread(Socket s, ChatServer cs, int pausa) {
        this.s = s;
        ChatThread.cs = cs;
        ChatThread.pausa = pausa;

        try {
            in = new DataInputStream(new BufferedInputStream(s.getInputStream()));
            out = new DataOutputStream(new BufferedOutputStream(s.getOutputStream()));
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    protected void trasmetti(String messaggio, String destinatario, boolean trasmettiElenco) {
        synchronized (threads) {
            for (ChatThread e : threads) {
                if (e.nome.equals(destinatario) || (destinatario.equals("Tutti") && (e != this || trasmettiElenco))) {
                    try {
                        if (trasmettiElenco)
                            e.out.writeUTF(messaggio + elencoNomi);
                        else
                            e.out.writeUTF(messaggio);
                        e.out.flush();
                    } catch (IOException ex) {
                        e.ferma();
                        e.interrupt();
                    }
                }
            }
        }
    }

    protected void ferma() {
        cs.decrementaUtenti();
        synchronized (threads) {
            threads.removeElement(this);
            elencoNomi = "" + SEPARATORE;
            for (ChatThread e : threads)
                elencoNomi += e.nome + SEPARATORE;
        }
        trasmetti(nome + " ha abandonato la chat", "Tutti", true);
        try { s.close(); }
        catch (IOException ignored) {}
    }

    @Override
    public void run() {
        try { // legge un nuovo nome
            while (nome.equals("")) {
                nome = in.readUTF();
                if (elencoNomi.contains(nome)) {
                    out.writeUTF("RETRY:" + nome);
                    out.flush();
                }
                if (nome.length() > LNOME || nome.indexOf(SEPARATORE) != -1 || elencoNomi.contains(nome)) {
                    ferma();
                    return;
                }
            }

            synchronized (threads) {
                elencoNomi += nome + SEPARATORE;
                threads.addElement(this);
            }

            out.writeUTF(nome);
            out.flush();
            System.out.println(nome);
            trasmetti(nome + " si è unito alla chat", "Tutti", true);

            while (true) { // si mette in ascolto sul canale di input
                String msg = in.readUTF(); // destinatario\ntesto
                int pos = msg.indexOf(SEPARATORE) + 1;
                if (msg.length() <= LMESS && pos != 0 && msg.indexOf(SEPARATORE, pos) == -1)
                    trasmetti(nome + "> " + msg.substring(pos, msg.length()), msg.substring(0, pos - 1), false);
                try {
                    sleep(pausa);
                } catch (InterruptedException ignored) {}
            }
        } catch (IOException e) { ferma(); }
    }
}