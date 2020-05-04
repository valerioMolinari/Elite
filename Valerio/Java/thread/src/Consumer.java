import java.io.*;

public class Consumer implements Runnable {
    private DataInputStream in;

    public Consumer(InputStream is) {
        in = new DataInputStream(is);
    }

    @Override
    public void run() {
        double mean = 0;

        for(;;)
            try {
                double newMean = in.readDouble();
                if (Math.abs(newMean - mean) > .01) {
                    System.out.println(newMean);
                    mean = newMean;
                }
            } catch (Exception e) {
                System.out.println("Errore in Consumer: "+e);
            }
    }
}