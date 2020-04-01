public class Book  {
    private String title;
    private int istantLoan;
    public boolean isLoaned;

    public Book(String title) {
        this.title = title;
        this.isLoaned = false;
        this.istantLoan = 0;
    }

    public String getTitle() {
        return title;
    }

    public long getIstantLoan() {
        return istantLoan;
    }

    public void setIstantLoan(int istantLoan) {
        this.istantLoan = istantLoan;
    }
}
