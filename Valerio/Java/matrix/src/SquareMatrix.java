public class SquareMatrix extends Matrix {
    public SquareMatrix(int n, Bound bound) {
        super(n,n,bound);
    }

    SquareMatrix(String[][] matrix) {
        super(matrix);
        try {
            boolean b = matrix.length != matrix[0].length;
            if (b)
                throw new SquareMatrixDimensionsException("Cannot create SquareMatrix from a "+matrix.length +"x"+ matrix[0].length + " dimension Matrix\n\t"+this+" was initialized as a null Matrix");
        } catch (SquareMatrixDimensionsException e) {
            setMatrix(new Fraction[][]{{}});
            setDimension(new Dimension(1,0));
            System.out.println("\033[91m"+e+"\033[0m");
        }
    }

    SquareMatrix(Fraction[][] matrix) {
        super(matrix);
    }

    public static SquareMatrix identity(int n) {
        Fraction[][] a = new Fraction[n][n];
        I.zeroLoop.exec(n, n, (i, j) -> a[i][j] = i == j ? new Fraction(1,1) : new Fraction(0,1));

        return new SquareMatrix(a);
    }

    public boolean isSupTriangle() {
        return isSupTriangle(this);
    }

    public boolean isInfTriangle() {
        return isInfTriangle(this);
    }

    public static boolean isSupTriangle(SquareMatrix a) {
        return isTriangle(a, true);
    }

    public static boolean isInfTriangle(SquareMatrix a) {
        return isTriangle(a, false);
    }

    public static boolean isTriangle(SquareMatrix a, boolean isSup) {
        final int N = a.getDimension().n;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (isSup && i > j && !a.getMatrix()[i][j].equals(new Fraction(0)))
                    return false;
                else if (!isSup && i < j && !a.getMatrix()[i][j].equals(new Fraction(0)))
                    return false;
            }
        return true;
    }

    public SquareMatrix setSupTriangle() {
        return setSupTriangle(this);
    }

    public SquareMatrix setInfTriangle() {
        return setInfTriangle(this);
    }

    public static SquareMatrix setSupTriangle(SquareMatrix a) {
        return setTriangle(a, true);
    }

    public static SquareMatrix setInfTriangle(SquareMatrix a) {
        return setTriangle(a, false);
    }

    private static SquareMatrix setTriangle(SquareMatrix a, boolean isSup) {
        final int N = a.getDimension().n;
        Fraction[][] array = new Fraction[N][N];
        I.zeroLoop.exec(N, N, (i, j) -> {
            if (isSup)
                array[i][j] = i <= j ? a.getMatrix()[i][j] : new Fraction(0);
            else
                array[i][j] = i >= j ? a.getMatrix()[i][j] : new Fraction(0);
        });
        return new SquareMatrix(array);
    }

    public boolean isSymmetrical() {
        return isSymmetrical(this);
    }

    public static boolean isSymmetrical(SquareMatrix a) {
        return a.equals(a.transpose());
    }

    public Fraction det() {
        return det(this);
    }

    public static Fraction det(SquareMatrix s) {
        Fraction[][] matrix = s.clone().getMatrix();
        Fraction a, b, c, d;
        switch (s.getDimension().n) {
            case 1:
                return matrix[0][0];
            case 2:
                a = matrix[0][0];
                b = matrix[0][1];
                c = matrix[1][0];
                d = matrix[1][1];
                return a.multiply(d).subtract(b.multiply(c));
            case 3:
                a = matrix[0][0];
                b = matrix[0][1];
                c = matrix[0][2];
                d = matrix[1][0];
                Fraction e = matrix[1][1];
                Fraction f = matrix[1][2];
                Fraction g = matrix[2][0];
                Fraction h = matrix[2][1];
                Fraction i = matrix[2][2];
                return a.multiply(e).multiply(i)
                        .add(b.multiply(f).multiply(g))
                        .add(c.multiply(h).multiply(d))
                        .subtract(c.multiply(e).multiply(g))
                        .subtract(h.multiply(f).multiply(a))
                        .subtract(b.multiply(d).multiply(i));
            default:
                return new Fraction(0);
        }
    }
}