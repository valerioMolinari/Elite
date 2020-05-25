import java.net.*;
import java.io.*;

public class ThreadedEchoServer {
	public static class ThreadedEchoHandler extends Thread {
		private Socket incoming;
		private int counter;

		public ThreadedEchoHandler(Socket incoming, int counter) {
			this.incoming = incoming;
			this.counter = counter;
		}

		@Override
		public void run() {
			try (InputStreamReader isr = new InputStreamReader(incoming.getInputStream());
				 BufferedReader in = new BufferedReader(isr);
				 PrintWriter out = new PrintWriter(incoming.getOutputStream(), true)
			){
				out.println("\nHello client" + counter + ", enter BYE to exit.");

				String line;
				boolean go = true;
				while(go) {
					line = in.readLine().trim();
					if (!line.equals("bye") && !line.equals("BYE"))
						out.println("Echo (" + counter +"): " + line);
					else
						go = false;
				}
				incoming.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		int i = 1;
		try (ServerSocket s = new ServerSocket(8189)){
			for (;;) {
				Socket incoming = s.accept();
				System.out.println("Spawning: " + i);
				new ThreadedEchoHandler(incoming, i).start();
				i++;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
