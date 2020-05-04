import java.util.*;
import java.io.*;

public class PipeTest  {
	public static void main(String[] args) {
		try {
			PipedOutputStream pout1 = new PipedOutputStream();
			PipedInputStream pin1 = new PipedInputStream(pout1);

			PipedOutputStream pout2 = new PipedOutputStream();
			PipedInputStream pin2 = new PipedInputStream(pout2);

			Producer p = new Producer(pout1);
			Filter f = new Filter(pin1, pout2);
			Consumer c = new Consumer(pin2);

			Thread t = new Thread(c);

			p.start();
			f.start();
			t.start();

		} catch (IOException e) {
			System.out.println("Errore: "+e.getMessage());
		}
	}
}