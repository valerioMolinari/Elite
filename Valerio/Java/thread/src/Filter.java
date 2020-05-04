import java.io.*;

public class Filter extends Thread {
    private DataInputStream in;
    private DataOutputStream out;

    public Filter(InputStream is, OutputStream os) {
        in = new DataInputStream(is);
        out = new DataOutputStream(os);
    }

    @Override
    public void run() {
        double total = 0;
        int count = 0;

        for(;;)
            try {
                double x = in.readDouble();
                total += x;
                count++;
                out.writeDouble(total / count);
                out.flush();
            } catch (Exception e) {
                System.out.println("Errore in Filter: "+e);
            }
    }
}