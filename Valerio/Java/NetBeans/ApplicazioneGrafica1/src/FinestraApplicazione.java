/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author mr.anderson2159
 */
public class FinestraApplicazione extends javax.swing.JFrame {

    /**
     * Creates new form FinestraApplicazione
     */
    public FinestraApplicazione() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        pannello = new javax.swing.JPanel();
        primoNumero = new javax.swing.JTextField();
        secondoNumero = new javax.swing.JTextField();
        bottone = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        pannello.setLayout(new java.awt.GridLayout(3, 1));

        primoNumero.setText("0");
        primoNumero.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                primoNumeroActionPerformed(evt);
            }
        });
        pannello.add(primoNumero);

        secondoNumero.setText("0");
        pannello.add(secondoNumero);

        bottone.setText("Premi il pulsante");
        bottone.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bottoneActionPerformed(evt);
            }
        });
        pannello.add(bottone);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(pannello, javax.swing.GroupLayout.DEFAULT_SIZE, 722, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(pannello, javax.swing.GroupLayout.DEFAULT_SIZE, 354, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void primoNumeroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_primoNumeroActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_primoNumeroActionPerformed

    private void bottoneActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bottoneActionPerformed
         String testo1 = primoNumero.getText();
         String testo2 = secondoNumero.getText();
         int n1, n2;
      
             n1 = Integer.parseInt(testo1);
             n2 = Integer.parseInt(testo2);
             if (n1 == n2) {
                 // Colora la finestra di verde
                 System.out.println("Verde");
             } else {
                 // Colora la finestra di rosso
                 System.out.println("Rosso");
             }
         
    }//GEN-LAST:event_bottoneActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(FinestraApplicazione.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(FinestraApplicazione.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(FinestraApplicazione.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(FinestraApplicazione.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new FinestraApplicazione().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bottone;
    private javax.swing.JPanel pannello;
    private javax.swing.JTextField primoNumero;
    private javax.swing.JTextField secondoNumero;
    // End of variables declaration//GEN-END:variables
}
