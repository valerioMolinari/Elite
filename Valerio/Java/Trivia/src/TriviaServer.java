import java.net.*;
import java.io.*;
import java.util.Random;

public class TriviaServer  {
	private static String[] questions;
	private static String[] answers;

	public static class TriviaServerThread extends Thread {
		private String[] questions;
		private String[] answers;
		private Socket clientSocket = null;
		private final int WAITFORCLIENT = 0;
		private final int WAITFORANSWER = 1;
		private final int WAITFORCONFIRM = 2;
		private int state = WAITFORCLIENT;
		private int num;

		public TriviaServerThread(Socket incoming, String[] questions, String[] answers) {
			clientSocket = incoming;
			this.questions = questions;
			this.answers = answers;
		}

		private String processInput(String inStr) {
			Random rand = new Random(System.currentTimeMillis());

			String outStr = "";
			switch (state) {
				case WAITFORCLIENT:
					//Ask a question
					num = Math.abs(rand.nextInt(questions.length));
					outStr = questions[num];
					state = WAITFORANSWER;
					break;
				case WAITFORANSWER:
					//Check the answer
					if (inStr.trim().equalsIgnoreCase(answers[num]))
						outStr = "That's correct! Want another? (y/n): ";
					else
						outStr = "Wrong, answer was " + answers[num] + ". Want another? (y/n): ";
					state = WAITFORCONFIRM;
					break;
				case WAITFORCONFIRM:
					state = WAITFORCLIENT;
					if (inStr.trim().equalsIgnoreCase("y")) {
//						num = Math.abs(rand.nextInt(questions.length));
//						outStr = questions[num];
//						state = WAITFORANSWER;
						return processInput(null);
					} else
						outStr = "bye";
			}
			return outStr;
		}

		@Override
		public void run() {
			try {
				DataInputStream is = new DataInputStream(new BufferedInputStream(clientSocket.getInputStream()));
				DataOutputStream os = new DataOutputStream(new BufferedOutputStream(clientSocket.getOutputStream()));
				String inLine, outLine;

				//Output server request
				outLine = processInput(null);
				os.writeUTF(outLine);
				os.flush();

				//Process and output user input
				while ((inLine = is.readUTF()) != null) {
					outLine = processInput(inLine);
					os.writeUTF(outLine);
					os.flush();
					if (outLine.equals("bye"))
						break;

				}

			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private static boolean initQnA() {
		boolean isQ = true;
		int index = 0;
		int numQuestions;
		BufferedReader inStream = null;
		try {
			inStream = new BufferedReader(new FileReader("QnA.txt"));
			String riga = inStream.readLine();
			numQuestions = Integer.parseInt(riga);
			numQuestions /= 2;
			questions = new String[numQuestions];
			answers = new String[numQuestions];
			while ((riga = inStream.readLine()) != null) {
				if (isQ) {
					questions[index] = riga;
					isQ = false;
				} else {
					answers[index] = riga;
					isQ = true;
					index++;
				}
			}
		} catch (FileNotFoundException e) {
			System.err.println("Exception: couldn't find the fortune file");
			return false;
		} catch (IOException e) {
			System.err.println("Exception: I/O error trying reading questions");
			return false;
		}

		try {
			inStream.close();
		} catch (IOException e) {
			System.err.println("Exception: I/O error trying to close the file");
			return false;
		}
		return true;
	}

	public static void main(String[] args) {
		final int PORTNUM = 1234;

		ServerSocket serverSocket = null;

		if (!initQnA()) {
			System.err.println("Error: couldn't initialize questions and answers");
			System.exit(1);
		}

		try {
			serverSocket = new ServerSocket(PORTNUM);
			System.out.println("TriviaServer up and running...");
		} catch (IOException e) {
			System.err.println("Error: couldn't create ServerSocket");
			System.exit(1);
		}

		try {
			while (true) {
				Socket incoming = serverSocket.accept();
				Thread t = new TriviaServerThread(incoming, questions, answers);
				t.start();
			}
 		} catch (IOException e) {
			System.err.println("Error: couldn't connect to client Socket");
			System.exit(1);
		}

	}
}