import java.io.*;
import java.util.*;

public class Files {
    private static Random r = new Random();

    public static void writeCharFile_intRange(String fileName, int n, int m) {
        try (FileWriter stream = new FileWriter(fileName);
             BufferedWriter bf = new BufferedWriter(stream);
             PrintWriter out = new PrintWriter(bf)
        ) {
            for (int i = 0; i < n; i++)
                out.println(r.nextInt(m));
        }
        catch (IOException e) {
            System.out.println("Errore: " + e.getMessage());
        }
    }

    public static void writeBinFile_intRange(String fileName, int n, int m) {
        try (FileOutputStream stream = new FileOutputStream(fileName);
             DataOutputStream output = new DataOutputStream(stream);
        ) {
            for (int i = 0; i < n; i++)
                output.writeInt(r.nextInt(m));
        }
        catch (IOException e) {
            System.out.println("Errore: " + e.getMessage());
        }
    }

    public static int readBinFile_sumMajors(String fileName, int n) {
        int s = 0;

        try (FileInputStream bin = new FileInputStream(fileName);
             BufferedInputStream bis = new BufferedInputStream(bin);
             DataInputStream input = new DataInputStream(bis);
        ) {
            int dato;
            while (true) {
                dato = input.readInt();
                if (dato > n)
                    s += dato;
            }
        } catch (EOFException e) {
            return s;
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileName + " non trovato");
        } catch (IOException e) {
            System.out.println("Errore: " + e.getMessage());
        }
        return 0;
    }

    public static int risultatoSommaMaggioriDiNBinario (String nomeFile, int n) {
        int risultato = 0;
        try (DataInputStream lettore = new DataInputStream (new FileInputStream (nomeFile))){
            while(lettore.available()!=0){
                int parziale = lettore.readInt();
                if (parziale > n)
                    risultato = risultato + parziale;
            }
            return risultato;
        }
        catch (IOException e){}
        return 0;
    }

    public static int readCharFile_sumMajors(String fileName, int n) {
        int s = 0;
        try (FileReader stream = new FileReader(fileName);
             Scanner input = new Scanner(stream);
        ) {
            int nInt;
            while (input.hasNextLine()) {
                if (input.hasNextInt()) {
                    nInt = input.nextInt();
                    if (nInt > n)
                        s += nInt;
                } else
                    input.nextLine();
            }
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileName + " non trovato");
            return 0;
        } catch (IOException e) {
            System.out.println("Errore: " + e.getMessage());
            return 0;
        }
        return s;
    }



    public static int readCharFile_countNotInt(String fileName) {
        int s = 0;
        try (FileReader stream = new FileReader(fileName);
             Scanner input = new Scanner(stream);
        ) {
            while (input.hasNextLine()) {
                try {
                    Integer.parseInt(input.nextLine());
                } catch (NumberFormatException e) {
                    s++;
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileName + " non trovato");
            return 0;
        } catch (IOException e) {
            System.out.println("Errore: " + e.getMessage());
            return 0;
        }
        return s;
    }

    public static boolean readCharFile_atLeast1int(String fileName) {
        try (FileReader stream = new FileReader(fileName);
             Scanner input = new Scanner(stream);
        ) {
            while (input.hasNextLine()) {
                try {
                    Integer.parseInt(input.nextLine());
                    return true;
                } catch (NumberFormatException ignored) { }
            }
            return false;
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileName + " non trovato");
        } catch (IOException e) {
            System.out.println("Errore: " + e.getMessage());
        }
        return false;
    }

    public static void main(String[] args) {
        String fileName = "file.txt";
        String binFileName = "binFile.txt";
        int majors = 6;
        //writeCharFile_intRange(fileName, 10, 10);
        System.out.print("Somma di numeri maggiori di " + majors + " in " + fileName + ": ");
        System.out.println(readCharFile_sumMajors(fileName, majors));
        System.out.println(readCharFile_countNotInt_lowLevel(fileName));
        System.out.println(readCharFile_countNotInt(fileName));
        System.out.println(readCharFile_atLeast1int(fileName));
        writeBinFile_intRange(binFileName, 10, 10);
        System.out.println(readBinFile_sumMajors(binFileName, majors));
    }
}
