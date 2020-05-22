import java.io.*;

public class Consumer implements Runnable {
    private DataInputStream in;

    public Consumer(InputStream is) {
        in = new DataInputStream(is);
    }

    @Override
    public void run() {
        double avg = 0;

        for(;;)
            try {
                double newAvg = in.readDouble();
                if (Math.abs(newAvg - avg) > .01) {
                    System.out.println(newAvg);
                    avg = newAvg;
                }
            } catch (Exception e) {
                System.out.println("Errore in Consumer: "+e);
            }
    }
}