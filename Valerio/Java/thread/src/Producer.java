import java.io.DataOutputStream;
import java.io.OutputStream;
import java.util.Random;

public class Producer extends Thread {
    private DataOutputStream out;

    public Producer(OutputStream os) {
        out = new DataOutputStream(os);
    }

    @Override
    public void run() {
        Random r = new Random();
        while (true) {
            try {
                Double num = r.nextDouble();
                out.writeDouble(num);
                out.flush();
                sleep(Math.abs(r.nextInt() % 1000));
            } catch (Exception e) {
                System.out.println("Errore in Producer: " + e);
            }
        }
    }
}