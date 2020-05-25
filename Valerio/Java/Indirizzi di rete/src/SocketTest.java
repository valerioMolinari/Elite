import java.net.*;
import java.io.*;

public class SocketTest {
	public static void main(String[] args) {
		try (Socket s = new Socket("time-a.timefreq.bldrdoc.gov",13);
			 InputStreamReader isr = new InputStreamReader(s.getInputStream());
			 BufferedReader in = new BufferedReader(isr);
		){
			boolean continua = true;
			String line;
			while (continua) {
				line = in.readLine();
				if (line != null)
					System.out.println(line);
				else
					continua = false;
			}
 		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}