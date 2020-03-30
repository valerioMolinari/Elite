import java.util.*;

public class Library  {
    private ArrayList<Book> library;
    private long istantLibrary;

    public Library() {
        this.library = new ArrayList<>();
        this.istantLibrary = System.currentTimeMillis();
    }

    public boolean addBook(Book book) {
        if (library.contains(book))
            return false;
        library.add(book);
        return true;
    }

    public boolean loanBook(Book book) throws MissingBookException {
        if (!library.contains(book))
            throw new MissingBookException("Book \"" + book.getTitle() + "\" doesn't exist in this library");

        if (book.isLoaned)
            return false;

        book.setIstantLoan((int) (System.currentTimeMillis() - istantLibrary));
        return book.isLoaned = true;
    }

    public void returnBook(Book book) throws MissingBookException, LoanedBookException {
        if (!library.contains(book))
            throw new MissingBookException("Book \"" + book.getTitle() + "\" never was in this library");

        if (!book.isLoaned)
            throw new LoanedBookException("Book \"" + book.getTitle() + "\" wasn't loaned'");

        book.setIstantLoan(0);
        book.isLoaned = false;
    }

    public void printLoan() {
        ArrayList<Book> loaned = new ArrayList<>();
        for (Book currentBook : library) {
            if (currentBook.isLoaned) {
                if (loaned.size() == 0)
                    loaned.add(currentBook);
                else
                    for (int i = 0; i < loaned.size(); i++)
                        if (loaned.get(i).getIstantLoan() >= currentBook.getIstantLoan()) {
                            loaned.add(i, currentBook);
                            break;
                        }
            }
        }

        for (Book book : loaned)
            System.out.println(book.getTitle() + " " + book.getIstantLoan());
    }
}