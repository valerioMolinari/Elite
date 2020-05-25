import java.net.*;
import java.io.*;

public class Trivia  {
	public static void main(String[] args) {
		final int PORTNUM = 1234;
		Socket socket = null;
		DataInputStream in = null;
		DataOutputStream out = null;
		String address;

		if (args.length != 1) {
			System.out.println("\nUsage: java Trivia <address>\n");
			System.exit(1);
		}

		address = args[0];

		try {
			socket = new Socket(address, PORTNUM);
			in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
			out = new DataOutputStream(new BufferedOutputStream(socket.getOutputStream()));
		} catch (IOException e) {
			System.err.println("Exception: couldn't create stream socket");
			System.exit(1);
		}

		try {
			StringBuffer str = new StringBuffer(128);
			String inStr;
			int c;

			while ((inStr = in.readUTF()) != null) {
				System.out.println("Server: " + inStr);
				if (inStr.equals("bye"))
					break;
				while ((c = System.in.read()) != '\n')
					str.append((char) c);
				System.out.println("Client: " + str);
				out.writeUTF(str.toString());
				out.flush();
				str.setLength(0);
			}
			out.close();
			in.close();
			socket.close();
		} catch (IOException e) {
			System.err.println("Exception: I/O error trying talk to server");
		}


	}
}