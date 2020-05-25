import java.net.*;
import java.io.*;
import java.util.*;

public class ChatServer  {
	protected int utentiConnessi = 0;

	public ChatServer() throws IOException, InterruptedException {
		this(3000, 0, 0);
	}

	public ChatServer(int porta) throws IOException, InterruptedException {
		this(porta, 0, 0);
	}

	public ChatServer(int porta, int utenti) throws IOException, InterruptedException {
		this(porta, utenti, 0);
	}

	public ChatServer(int porta, int utenti, int pausa) throws IOException, InterruptedException {
		ServerSocket server = new ServerSocket(porta);
		while (true) {
			if (utentiConnessi < utenti || utenti == 0) {
				Socket client = server.accept();
				System.out.println(client.getInetAddress());
				Thread c = new ChatThread(client, this, pausa);
				c.start();
				synchronized (this) { utentiConnessi++; }
			} else
				Thread.sleep(1000);
		}
	}

	public synchronized void decrementaUtenti() {
		utentiConnessi--;
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		switch (args.length) {
			case 0: new ChatServer(); break;
			case 1: new ChatServer(Integer.parseInt(args[0])); break;
			case 2: new ChatServer(Integer.parseInt(args[0]), Integer.parseInt(args[1])); break;
			default: new ChatServer(Integer.parseInt(args[0]), Integer.parseInt(args[1]), Integer.parseInt(args[2]));
		}
	}
}