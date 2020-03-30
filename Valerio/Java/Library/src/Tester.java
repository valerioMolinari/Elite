public class Tester  {
	public static void main(String[] args) throws MissingBookException, LoanedBookException, InterruptedException {
		Book a = new Book("a");
		Book b = new Book("b");
		Book c = new Book("c");
		Book d = new Book("d");
		Library lib = new Library();
		lib.addBook(a);
		lib.addBook(b);
		lib.addBook(c);
		lib.addBook(d);
		lib.loanBook(c);
		Thread.sleep(10);
		lib.loanBook(b);
		Thread.sleep(10);
		lib.loanBook(d);
		Thread.sleep(10);
		lib.loanBook(a);
		Thread.sleep(10);
		lib.printLoan();
	}
}