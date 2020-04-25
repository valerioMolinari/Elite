import java.awt.event.*;

/*
* La classe windowAdapter è astratta in un modo che al momento non conosco:
* sostanzialmente può essere ereditata tuttavia è possibile scegliere i metodi
* da ereditare senza doverli implementare tutti... probabilmente è astratta la classe
* ma i metodi sono di default...
*
* Comunque si sceglie il metodo di cui fare l'override e una classe che estende
* WindowAdapter si limita ad istanziare un ascoltatore del metodo
* (o forse dei metodi) che ha scelto di ridefinire
* */

public class DistruttoreFinestra extends WindowAdapter {
    // L'override di questo metodo della classe WindowAdapter permette di terminare il programma
    // al click della crocetta rossa della finestra
    @Override
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
}

/*
* Alcuni altri metodi di WindowAdapter sono
*   windowOpen() -> quando la finestra viene aperta
*   windowClosed() -> quando la finestra è stata chiusa
*   windowIconified() -> quando la finestra è stata ridotta a icona (minimizzata)
*   windowDeiconified() -> quando l'icona diventa finestra
*   windowActivated() -> quando la finestra viene attivata
*   windowDeactivated() -> quando la finestra viene resa non attiva
*   windowGainedFocus() -> quando la finestra ottiene il focus
*   windowLostFocus() -> quando una finestra perde il focus
*   windowChangeStatus() -> quando la finestra cambia stato
*
* tutti questi metodi prendono come parametro un WindowEvent e
* */