import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

public class ChatClientFrame extends JFrame implements Runnable, ActionListener {
    static String host = null;
    static int porta;

    protected DataInputStream in;
    protected DataOutputStream out;
    protected String nome = "";
    protected JLabel l;
    protected JTextArea output;
    protected JTextField input;
    protected JList scelta;
    protected Thread ascolta = null;
    protected final char SEPARATORE = '\n';
    volatile boolean continua = true;
    Socket socket = null;
    DefaultListModel listModel = new DefaultListModel();

    public ChatClientFrame(String titolo) {
        super(titolo);

        JPanel pannello = new JPanel();
        pannello.setLayout(new BorderLayout());

        setFont(new Font("Helvetica", Font.PLAIN, 16));
        setLayout(new BorderLayout());
        output = new JTextArea(10, 10); // "",10,10
        JScrollPane sp =  new JScrollPane(output);
        add(sp, "Center");
        output.setEditable(false);

        listModel.addElement("Tutti");
        scelta = new JList(listModel);
        scelta.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        scelta.setSelectedIndex(0);
        JScrollPane sp2 = new JScrollPane(scelta);
        pannello.add(sp2, "Center");
        add(pannello, "East");

        l = new JLabel("Destinatario:");
        pannello.add(l, "North");
        input = new JTextField();
        input.setEditable(false);
        input.addActionListener(this);
        add(input, "South");

        ascolta = new Thread(this);
        ascolta.start();
    }

    private void termina() {
        if (ascolta != null) {
            continua = false;
            ascolta = null;
        }

        try {
            if (out != null) out.close();
            if (in != null) in.close();
            if (socket != null) socket.close();
        }
        catch (IOException e) { e.printStackTrace(); }
    }

    @Override
    public void dispose() {
        termina();
        super.dispose();
    }

    @Override
    public void run() {
        try {
            output.append("G/L Chat di Gentile Francesco e Lucarelli Marco\n\n");
            output.append("Puoi inviare messaggi alla chat scrivendo nella riga in basso e poi battendo INVIO. \n");
            output.append("Puoi scergliere dalla lista a destra il destinatario a cui li invii. \n\n");
            output.append("Connessione al server in corso... ");
            socket = new Socket(host, porta);
            in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            out = new DataOutputStream(new BufferedOutputStream(socket.getOutputStream()));
            output.append("OK\n\nInserisci il tuo nome:\n");
            String riga = "";
            String selezionato = "";
            int  n, posizione;
            String[] parole;

            do {
                if (riga.length() >= 6 && riga.substring(0, 5).equals("RETRY"))
                    output.append("\nIl nome " + riga.substring(6) + " è già presente tra i partecipanti. Prova con un altro nome:\n");
                input.requestFocus();
                if (!input.isEditable())
                    input.setEditable(true);
                riga = in.readUTF();
            } while (riga.substring(0, 5).equals("RETRY"));

            nome = riga;
            setTitle("Esempio chat: " + nome);

            while (continua) {
                riga = in.readUTF();
                if (riga.indexOf(SEPARATORE) == -1) // valerio > Ciao!
                    output.append(riga + '\n');
                else { // valerio si è unito alla chat\nstefano\nfrato\ngiulia
                    parole = riga.split("\\n");
                    output.append(parole[0]+'\n');
                    selezionato = (String) scelta.getSelectedValue();
                    listModel.removeAllElements();
                    listModel.addElement("Tutti");
                    scelta.setSelectedIndex(0);
                    posizione = 0;

                    for (n = 1; n < parole.length; n++)
                        if (!nome.equals(parole[n])) {
                            listModel.addElement(parole[n]);
                            posizione++;
                            if (parole[n].trim().equals(selezionato.trim()))
                                scelta.setSelectedIndex(posizione);
                        }
                }
            }
        } catch (IOException e) {
            output.append("Errore!\n");
            output.append(e.getMessage());
            termina();
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if ((e.getSource() instanceof JTextField) && e.getSource() == input && !input.getText().equals("")) {
            String msg; // messaggio finale
            String testo = input.getText(); // testo scritto dall'utente
            if (nome.equals("")) { // se l'utente non ha ancora inserito il suo nome
                nome = testo;
                output.setText(""); // ripulisco la finestra contenente i messaggi di benvenutp
                msg = nome;
            } else {
                output.append("> " + testo + '\n');
                msg = (String) scelta.getSelectedValue() + SEPARATORE + testo;
            }
            try {
                out.writeUTF(msg);
                out.flush();

            } catch (IOException ignored) {}
            input.setText("");
        }
    }

    public static void main(String[] args) {
        host = args.length >= 1 ? args[0] : "localhost";
        porta = args.length >= 2 ? Integer.parseInt(args[1]) : 3000;
        ChatClientFrame finestra = new ChatClientFrame("Esempio Chat: ");
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setSize(600,400);
        finestra.setVisible(true);
    }
}