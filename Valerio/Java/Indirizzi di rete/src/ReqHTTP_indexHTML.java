import java.io.*;
import java.net.*;

public class ReqHTTP_indexHTML {
	public static void main(String[] args) {
		try {
			String nomeHost;
			int porta;

			if (args.length == 0)
				nomeHost = "www.google.it";
			else
				nomeHost = args[0];

			if (args.length <= 1)
				porta = 80;
			else
				porta = Integer.parseInt(args[1]);

			try (Socket s = new Socket(nomeHost, porta);
				 InputStreamReader isr = new InputStreamReader(s.getInputStream());
				 BufferedReader in = new BufferedReader(isr);
				 PrintWriter out = new PrintWriter(s.getOutputStream(), true)
			) {
				out.println("GET / HTTP/1.1");
				out.println("accept: text/html");
				out.println("host: " + nomeHost);

				boolean somethingLeft = true;
				String line;
				while (somethingLeft) {
					line = in.readLine();
					if (line != null)
						System.out.println(line);
					else
						somethingLeft = false;
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}