import java.util.Arrays;
import java.util.Random;

public class Matrix {
    private Fraction[][] matrix;
    private Dimension dimension;
    private static String text;
    static Interfaces I = new Interfaces();

    public Matrix(String[][] matrix) {
        Fraction[][] c = new Fraction[matrix.length][matrix[0].length];
        I.zeroLoop.exec(matrix.length, matrix[0].length, (i, j) -> c[i][j] = new Fraction(matrix[i][j]));
        this.matrix = c;
        dimension = new Dimension(matrix.length, matrix[0].length);
    }

    public Matrix(Fraction[][] matrix) {
        this.matrix = matrix;
        dimension = new Dimension(matrix.length, matrix[0].length);
    }

    public Matrix(int n, int m, Bound bound) {
        dimension = new Dimension(n, m);
        matrix = new Fraction[n][m];
        boolean bool = bound.isPositive();
        int b = bound.getBound();
        Random r = new Random();
        // I.zeroLoop.exec(a, b, (i, j) -> blocco di codice)
        // significa fai un ciclo dentro a un ciclo che va da 0 ad a per la i
        // e da 0 a b per la j, quindi utilizza i e j nel tuo blocco di codice
        // solo a patto che tale blocco non contenga dei return

        switch (bound.getType()) {
            case "Integer":
                I.zeroLoop.exec(n, m, (i, j) -> {
                    matrix[i][j] = bool ? new Fraction(r.nextInt(b)) : new Fraction(r.nextInt(b * 2) - b);
                });
                break;
            case "Double":
                I.zeroLoop.exec(n, m, (i, j) -> {
                    matrix[i][j] = bool ? new Fraction(r.nextInt(b), r.nextInt(b - 1) + 1) : new Fraction(r.nextInt(b * 2) - b, r.nextInt(b - 1) + 1);
                });
                break;
            default:
                System.out.println("Unknown bound type: " + this + " is a Null Matrix");
                matrix = new Fraction[][] {{}};
        }
    }



    public void visualizza() {
        visualizza(0);
    }

    public void visualizza(int startSpaces) {
        if (dimension.getM() == 0) {
            System.out.println("Null matrix\n");
            return;
        }

        int max = 0;

        for (Fraction[] i : matrix)
            for (Fraction j : i)
                if (j.toString().length() > max)
                    max = j.toString().length() + 1;

        String s = "%"+max+"s ";

        for (Fraction[] i : matrix) {
            System.out.print(" ".repeat(startSpaces));
            for (Fraction j : i)
                System.out.printf(s, j.toString());
            System.out.println();
        }
        System.out.println();
    }

    public boolean isSymmetrical() {
        return isSymmetrical(this);
    }

    public static boolean isSymmetrical(Matrix a) {
        if (a.dimension.getN() != a.dimension.getM())
            return false;
        return a.equals(a.transpose());
    }

    public Matrix sum(Matrix a) {
        return Matrix.sum(this, a);
    }

    public static Matrix sum(Matrix a, Matrix b) {
        if(!a.dimension.equals(b.dimension))
            return new Matrix(new Fraction[][] {{}});
        final int aN = a.dimension.getN();
        final int aM = a.dimension.getM();
        Fraction[][] c = new Fraction[aN][aM];

        I.zeroLoop.exec(aN, aM, (i, j) -> c[i][j] = a.matrix[i][j].add(b.matrix[i][j]));

        return new Matrix(c);
    }

    public static Matrix sum(Matrix ...args) {
        if (args.length == 2)
            return sum(args[0], args[1]);
        return sum(args[0], sum(Arrays.copyOfRange(args, 1, args.length)));
    }

    public Matrix subtract(Matrix a) {
        return Matrix.sum(this, a.scalarProduct("-1"));
    }

    public static Matrix subtract(Matrix a, Matrix b) {
        return sum(a, b.scalarProduct("-1"));
    }

    public Matrix scalarProduct(String n) {
        return scalarProduct(this, n);
    }

    public static Matrix scalarProduct(Matrix a, String n) {
        final int aN = a.dimension.getN();
        final int aM = a.dimension.getM();
        Fraction[][] b = new Fraction[aN][aM];
        Fraction f = new Fraction(n);
        I.zeroLoop.exec(aN, aM, (i, j) -> b[i][j] = a.matrix[i][j].multiply(f));
        return new Matrix(b);
    }

    public Matrix transpose() {
        return transpose(this);
    }

    public static Matrix transpose(Matrix a) {
        final int aN = a.dimension.getN();
        final int aM = a.dimension.getM();

        Fraction[][] b = new Fraction[aM][aN];
        I.zeroLoop.exec(aN, aM, (i, j) -> b[j][i] = a.matrix[i][j]);
        return new Matrix(b);
    }

    public Matrix matrixProduct(Matrix a) {
        return matrixProduct(this, a);
    }

    public static Matrix matrixProduct(Matrix a, Matrix b) {
        final int aN = a.dimension.getN();
        final int M = a.dimension.getM();
        final int bM = b.dimension.getM();

        if (a.dimension.getM() != b.dimension.getN())
            return new Matrix(new Fraction[][] {{}});

        Fraction[][] c = new Fraction[aN][bM];

        I.zeroLoop.exec(aN, bM, (i, j) -> {
            c[i][j] = new Fraction(0);

            for (int m = 0; m < M; m++)
                c[i][j] = c[i][j].add(a.matrix[i][m].multiply(b.matrix[m][j]));
        });
        return new Matrix(c);
    }

    public static Matrix matrixProduct(Matrix ...args) {
            if (args.length == 2)
                return matrixProduct(args[0], args[1]);
            return matrixProduct(args[0], matrixProduct(Arrays.copyOfRange(args, 1, args.length)));
    }

    public boolean isZeroNull() {
        return isZeroNull(this);
    }

    public static boolean isZeroNull(Matrix a) {
        Fraction[][] x = a.getMatrix();
        for (int i = 0; i < x.length; i++)
            for (int j = 0; j < x[0].length; j++)
                if (!x[i][j].equals(0))
                    return false;
        return true;
    }

    public Matrix swap(int row1, int row2) {
        return swap(this, row1, row2);
    }

    public static Matrix swap(Matrix a, int row1, int row2) {
        Fraction[][] matrix = a.getMatrix();
        Fraction[] temp = matrix[row1];
        matrix[row1] = matrix[row2];
        matrix[row2] = temp;
        return new Matrix(matrix);
    }

    public Matrix setRef() {
        return setREF(this);
    }

    public static Matrix setREF(Matrix a) {
        Fraction[][] A = a.getMatrix()
        if (SquareMatrix.identity(A.length).equals(a) || a.isZeroNull())
            return a;
        for (int i = 0; i < A.length; i++)
            if (!new Vector(a, i, EnumVector.COLUMN).isZeroNull()) {


                break;
            }
    }

    public boolean equals(Matrix a) {
        final int aN = a.dimension.getN();
        final int aM = a.dimension.getM();
        if (dimension.getN() != aN || dimension.getM() != aM)
            return false;

        for (int i = 0; i < aN; i++)
            for (int j = 0; j < aM; j++)
                if (!matrix[i][j].equals(a.matrix[i][j]))
                    return false;
        return true;
    }

    public Dimension getDimension() {
        return dimension;
    }

    public Fraction[][] getMatrix() {
        return matrix;
    }

    void setMatrix(Fraction[][] matrix) {
        this.matrix = matrix;
    }

    void setDimension(Dimension dimension) {
        this.dimension = dimension;
    }

    public static void defMatrice() {
        text = "\nUna matrice reale M𝗇ₓ𝗆(ℛ) è una tabella con n righe e m colonne di reali del tipo\n"
                + "\t\ta₁,₁     a₁,₂    ...     a₁,𝗆\n\t\ta₂,₁     a₂,₂    ...     a₂,𝗆"
                + "\n\t\t  .      .               .".repeat(3)
                + "\n\t\ta𝗇,₁     a𝗇,₂    ...     a𝗇,𝗆\n\n"
                + "dove aᵢ,ⱼ indica l'elemento posto alla riga i e colonna j e si chiama campo di componente (i,j).\n"
                + "Una matrice si dice quadrata se n == m.\n\nes.\n";
        System.out.println(text);
        new SquareMatrix(4, new Bound(10, false, "Integer")).visualizza(15);
        text = "Una matrice quadrata M ∈ M𝗇ₓ𝗇(ℛ) si dice triangolare superiore se aᵢ,ⱼ = 0 ∀i > j:\n\nes.\n";
        System.out.println(text);
        new SquareMatrix(4, new Bound(10, false, "Integer")).setSupTriangle().visualizza(15);
        text = "Si dice triangolare inferiore se aᵢ,ⱼ = 0 ∀i < j:\n\nes.\n";
        System.out.println(text);
        new SquareMatrix(4, new Bound(10, false, "Integer")).setInfTriangle().visualizza(15);
        text = "";
    }

    public static void defSomma() {
        text = "\nSiano A, B ∈ M𝗇ₓ𝗆(ℛ) due matrici. La somma A + B è definita da "
                + "C = A + B ∈ M𝗇ₓ𝗆(ℛ), Cᵢ,ⱼ = aᵢ,ⱼ + bᵢ,ⱼ\n\nes.";
        Matrix a = new Matrix(3, 4, new Bound(15, false, "Integer"));
        Matrix b = new Matrix(3, 4, new Bound(15, false, "Integer"));
        Matrix c = a.sum(b);
        System.out.println(text);
        a.visualizza(15);
        System.out.println(" ".repeat(23) + "+\n");
        b.visualizza(15);
        System.out.println(" ".repeat(23) + "=\n");
        c.visualizza(15);
        text = "";
    }

    public static void propSomma() {
        text = "\nLa somma in M𝗇ₓ𝗆(ℛ) è un'operazione binaria interna tra matrici "
                + "che gode delle seguenti proprietà:\n"
                + "\t1. A + B = B = A   ∀A,B ∈ M𝗇ₓ𝗆(ℛ)\n"
                + "\t2. A + (B + C) = (A + B) + C   ∀A,B,C ∈ M𝗇ₓ𝗆(ℛ)\n"
                + "\t3. ∃𝟘𝗇ₓ𝗆 ∈ M𝗇ₓ𝗆(ℛ) : A + 𝟘𝗇ₓ𝗆 = 𝟘𝗇ₓ𝗆 + A = A   ∀A,B ∈ M𝗇ₓ𝗆(ℛ)\n"
                + "\t(ovvero esiste la matrice neutra 𝟘nxm, ovvero la matrice nulla)\n"
                + "\t4. ∀A ∈ M𝗇ₓ𝗆(ℛ) ∃(-A) ∈ M𝗇ₓ𝗆(ℛ) : A + (-A) = (-A) + A = ∃𝟘𝗇ₓ𝗆\n";
        System.out.println(text);
        text = "";
    }

    public static void defProdottoScalare() {
        text = "\nSia A ∈ M𝗇ₓ𝗆(ℛ) una matrice e sia 𝛌 ∈ ℛ uno scalare. "
                + "Il prodotto per uno scalare 𝛌A di 𝛌 e A è definito da\n"
                + "C = 𝛌A ∈ M𝗇ₓ𝗆(ℛ), Cᵢ,ⱼ = 𝛌aᵢ,ⱼ\n\nes.";
        Matrix a = new Matrix(3, 4, new Bound(15, false, "Integer"));
        Matrix lA = a.scalarProduct("3");
        System.out.println(text);
        a.visualizza(15);
        System.out.println(" ".repeat(23) + "*\n");
        System.out.println(" ".repeat(23) + "3\n");
        System.out.println(" ".repeat(23) + "=\n");
        lA.visualizza(15);
        System.out.println("La somma tra due matrici è possibile solo se hanno le stesse dimensioni");
        text = "";
    }

    public static void propProdottoScalare() {
        text = "\nLa somma in M𝗇ₓ𝗆(ℛ) è una operazione binaria interna tra matrici che gode delle seguenti proprietà\n\n"
                + "\t1. 𝛌(A + B) = 𝛌A + 𝛌B\t\t\t\t∀A,B ∈ M𝗇ₓ𝗆(ℛ), ∀𝛌 ∈ ℛ\n"
                + "\t2. (𝛌 + 𝛍)A = 𝛌A + 𝛍A\t\t\t\t∀A ∈ M𝗇ₓ𝗆(ℛ), ∀𝛌,𝛍 ∈ ℛ\n"
                + "\t3. 𝛌(𝛍A) = (𝛌𝛍)A\t\t\t\t\t∀A ∈ M𝗇ₓ𝗆(ℛ), ∀𝛌,𝛍 ∈ ℛ\n"
                + "\t4. 1A = A\t\t\t\t\t\t\t∀A ∈ M𝗇ₓ𝗆(ℛ)\n"
                + "\t5. Se 𝛌A = 𝟘𝗇ₓ𝗆 allora 𝛌 = 0 oppure A = 𝟘𝗇ₓ𝗆";
        System.out.println(text);
        text = "";
    }

    public static void defTrasposizione() {
        text = "\nSia A ∈ M𝗇ₓ𝗆(ℛ) una matrice. La matrice trasposta di A è definita da\n"
                + "Aᵀ ∈ M𝗇ₓ𝗆(ℛ), aᵀᵢ,ⱼ = aⱼ,ᵢ\n\nes.";
        Matrix a = new Matrix(3, 4, new Bound(9, true, "Integer"));
        Matrix aT = a.transpose();
        System.out.println(text);
        a.visualizza(15);
        System.out.println(" ".repeat(12) + "Trasposizione\n");
        aT.visualizza(16);
        text = "";
    }

    public static void propTrasposizione() {
        text = "\nLa trasposizione di una matrice gode delle seguenti proprietà\n\n"
                +"\t1. (Aᵀ)ᵀ = A\t\t\t∀A ∈ M𝗇ₓ𝗆(ℛ)\n"
                +"\t2. (𝛌A)ᵀ = 𝛌Aᵀ\t\t\t∀A ∈ M𝗇ₓ𝗆(ℛ), ∀𝛌 ∈ ℛ"
                +"\t3. (A + B)ᵀ = Aᵀ + Bᵀ\t\t∀A,B ∈ M𝗇ₓ𝗆(ℛ)";
        System.out.println(text);
    }
}