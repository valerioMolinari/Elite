import java.io.*;
import java.net.*;

public class EchoServer  {
	public static void main(String[] args) {
		try {
			ServerSocket s = new ServerSocket(8189);
			while (true) {
				Socket incoming = s.accept();
				InputStreamReader isr = new InputStreamReader(incoming.getInputStream());
				BufferedReader in = new BufferedReader(isr);
				PrintWriter out = new PrintWriter(incoming.getOutputStream(), true);

				out.println("\nHello! Enter BYE to exit.");

				boolean done = false;
				String line;
				while (!done) {
					line = in.readLine().trim();
					if (!line.equals("BYE") && !line.equals("bye"))
						out.println("Echo: " + line);
					else
						done = true;
				}
				incoming.close();
				isr.close();
				in.close();
				out.close();
 			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}