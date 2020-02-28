import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        StringClass s = new StringClass();
        s.print();
        System.out.println();
        System.out.print("Nuovo Nome: ");
        s.change(scan.nextLine());
        System.out.println();
        s.print();
        System.out.println();
        s.methods();
    }
}
