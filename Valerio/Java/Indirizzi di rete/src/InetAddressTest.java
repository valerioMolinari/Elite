import java.net.*;

public class InetAddressTest  {
	public static void main(String[] args) {
		try {
			if (args.length > 0) {
				String host = args[0];
				InetAddress[] addresses = InetAddress.getAllByName(host);
				for (InetAddress address : addresses)
					System.out.println(address);
			} else
				System.out.println(InetAddress.getLocalHost());
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
	}
}