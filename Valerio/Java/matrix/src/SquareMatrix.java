public class SquareMatrix extends Matrix {
    public SquareMatrix(int n, Bound bound) {
        super(n,n,bound);
    }

    SquareMatrix(int[][] matrix) {
        super(matrix);

//        if (matrix.length != matrix[0].length)
//            throw new SquareMatrixDimensionsException("Cannot create SquareMatrix from a "+matrix.length +"x"+ matrix[0].length + "dimension Matrix");
    }

    public static SquareMatrix identity(int n) {
        int[][] a = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = i == j ? 1 : 0;

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
        final int N = a.getDimension().getN();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (isSup && i > j && a.getMatrix()[i][j] != 0)
                    return false;
                else if (!isSup && i < j && a.getMatrix()[i][j] != 0)
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
        final int N = a.getDimension().getN();
        int[][] array = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (isSup)
                    array[i][j] = i <= j ? a.getMatrix()[i][j] : 0;
                else
                    array[i][j] = i >= j ? a.getMatrix()[i][j] : 0;
            }
        return new SquareMatrix(array);
    }

    public boolean isSymmetrical() {
        return isSymmetrical(this);
    }

    public static boolean isSymmetrical(SquareMatrix a) {
        return a.equals(a.transpose());
    }
}