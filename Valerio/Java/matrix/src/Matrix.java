import java.util.Arrays;
import java.util.Random;

public class Matrix {
    private int[][] matrix;
    private Dimension dimension;

    public Matrix(int[][] matrix) {
        this.matrix = matrix;
        dimension = new Dimension(matrix.length, matrix[0].length);
    }

    public Matrix(int n, Bound bound) {
        this(n, n, bound);
    }

    public Matrix(int n, int m, Bound bound) {
        dimension = new Dimension(n, m);
        matrix = new int[n][m];
        boolean bool = bound.isPositive();
        int b = bound.getBound();
        Random r = new Random();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                matrix[i][j] = bool ? r.nextInt(b) : r.nextInt(b * 2) - b;
    }

    public static Matrix identity(int n) {
        int[][] a = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = i == j ? 1 : 0;

        return new Matrix(a);
    }


    public void visualizza() {
        if (dimension.getM() == 0) {
            System.out.println("Null matrix\n");
            return;
        }

        int max = 0;

        for (int[] i : matrix)
            for (int j : i)
                if (Integer.toString(j).length() > max)
                    max = Integer.toString(j).length();

        String s = "%"+max+"d ";

        for (int[] i : matrix) {
            for (int j : i)
                System.out.printf(s, j);
            System.out.println();
        }
        System.out.println();
    }

    public Matrix sum(Matrix a) {
        return Matrix.sum(this, a);
    }

    public static Matrix sum(Matrix a, Matrix b) {
        if(!a.dimension.equals(b.dimension))
            return new Matrix(new int[][] {{}});
        int aN = a.dimension.getN();
        int aM = a.dimension.getM();
        int[][] c = new int[aN][aM];

        for (int i = 0; i < aN; i++)
            for (int j = 0; j < aM; j++)
                c[i][j] = a.matrix[i][j] + b.matrix[i][j];

        return new Matrix(c);
    }

    public static Matrix sum(Matrix ...args) {
        if (args.length == 2)
            return sum(args[0], args[1]);
        return sum(args[0], sum(Arrays.copyOfRange(args, 1, args.length)));
    }

    public Matrix scalarProduct(int n) {
        return scalarProduct(this, n);
    }

    public static Matrix scalarProduct(Matrix a, int n) {
        int aN = a.dimension.getN();
        int aM = a.dimension.getM();
        int[][] b = new int[aN][aM];
        for (int i = 0; i < aN; i++)
            for (int j = 0; j < aM; j++)
                b[i][j] = a.matrix[i][j] * n;
        return new Matrix(b);
    }

    public Matrix transpose() {
        return transpose(this);
    }

    public static Matrix transpose(Matrix a) {
        int aN = a.dimension.getN();
        int aM = a.dimension.getM();

        int[][] b = new int[aM][aN];
        for (int i = 0; i < aN; i++)
            for (int j = 0; j < aM; j++)
                b[j][i] = a.matrix[i][j];
        return new Matrix(b);
    }

    public boolean isSymmetrical() {
        return isSymmetrical(this);
    }

    public static boolean isSymmetrical(Matrix a) {
        if (a.dimension.getM() != a.dimension.getN())
            return false;
        return a.equals(a.transpose());
    }

    public Matrix matrixProduct(Matrix a) {
        return matrixProduct(this, a);
    }

    public static Matrix matrixProduct(Matrix a, Matrix b) {
        int aN = a.dimension.getN();
        int M = a.dimension.getM();
        int bM = b.dimension.getM();

        if (a.dimension.getM() != b.dimension.getN())
            return new Matrix(new int[][] {{}});

        int[][] c = new int[aN][bM];

        for (int i = 0; i < aN; i++)
            for (int j = 0; j < bM; j++)
                for (int m = 0; m < M; m++)
                    c[i][j] += a.matrix[i][m] * b.matrix[m][j];

        return new Matrix(c);
    }

    public static Matrix matrixProduct(Matrix ...args) {
            if (args.length == 2)
                return matrixProduct(args[0], args[1]);
            return matrixProduct(args[0], matrixProduct(Arrays.copyOfRange(args, 1, args.length)));
    }

    public boolean equals(Matrix a) {
        int aN = a.dimension.getN();
        int aM = a.dimension.getM();
        if (dimension.getN() != aN || dimension.getM() != aM)
            return false;

        for (int i = 0; i < aN; i++)
            for (int j = 0; j < aM; j++)
                if (matrix[i][j] != a.matrix[i][j])
                    return false;

        return true;
    }

    public static void sommaProp() {
        String text = "La somma in Mn,m(ℛ) è un'operazione binaria interna tra matrici "
                + "che gode delle seguenti proprietà:\n"
                + "\t1. A + B = B = A   ∀A,B ∈ Mn,m(ℛ)\n"
                + "\t2. A + (B + C) = (A + B) + C   ∀A,B,C ∈ Mn,m(ℛ)\n"
                + "\t3. ∃𝟘nxm ∈ Mn,m(ℛ) : A + 𝟘nxm = 𝟘nxm + A = A   ∀A,B ∈ Mn,m(ℛ)\n"
                + "\t(ovvero esiste la matrice neutra 𝟘nxm, ovvero la matrice nulla)\n"
                + "\t4. ∀A ∈ Mn,m(ℛ) ∃(-A) ∈ Mn,m(ℛ) : A + (-A) = (-A) + A = 𝟘nxm\n";
        System.out.println(text);
    }
}