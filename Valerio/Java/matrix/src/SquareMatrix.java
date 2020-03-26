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

    public SquareMatrix reduce(int[] rows, int[] columns) {
        return reduce(this, rows, columns);
    }

    public static SquareMatrix reduce(final SquareMatrix a, final int[] rows, final int[] columns) {
        if (rows.length != columns.length)
            return a;
        int N = a.getDimension().n;
        // Mi assicuro che all'inizio esistano sia le righe sia le colonne da eliminare
        for (int row : rows)
            if (row > N)
                return a;
        for (int column : columns)
            if (column > N)
                return a;

        int newDimension = N - rows.length;
        Fraction[][] temp = new Fraction[N][N];
        I.zeroLoop.exec(N, N, (i,j) -> temp[i][j] = a.getMatrix()[i][j]);
        Fraction[][] newFractionMatrix = new Fraction[newDimension][newDimension];

        // Annullo tutti i termini da scartare in una matrice temporanea
        I.zeroLoop.exec(N, N, (i,j) -> {
            if (contains(rows, i + 1) || contains(columns, j + 1))
                temp[i][j] = null;
        });

        int countRow = 0, countColumn = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (temp[i][j] != null) {
                    newFractionMatrix[countRow][countColumn] = temp[i][j];
                    if (countColumn == newDimension - 1) {
                        countColumn = 0;
                        countRow++;
                    } else
                        countColumn++;
                }
            }
        return new SquareMatrix(newFractionMatrix);
    }

    public SquareMatrix reverse() {
        return reverse(this);
    }

    public static SquareMatrix reverse(SquareMatrix a) {
        a = a.clone();
        if (a.rank() != a.getDimension().n)
            return new SquareMatrix(new Fraction[][] {{}});
        SquareMatrix identity = SquareMatrix.identity(a.rank());
        SquareMatrix[] results = reverse(new SquareMatrix[] {a, identity.clone()});
        a = results[0];
        SquareMatrix b = results[1];
        if (a.matrixProduct(b).equals(b.matrixProduct(a)) && a.matrixProduct(b).equals(identity))
            return results[1];
        else
            return new SquareMatrix(new Fraction[][] {{}});
    }

    private static SquareMatrix[] reverse(SquareMatrix[] matrices) {
        SquareMatrix a = matrices[0];
        SquareMatrix b = matrices[1];
        Fraction[][] A = a.getMatrix();
        Fraction[][] B = b.getMatrix();

        Vector v;
        // Se la matrice è nulla o è la matrice identità ho finito
//        if (SquareMatrix.identity(A.length).equals(a) || a.isZeroNull() || a.isREF())
//            return new SquareMatrix[] {a, new SquareMatrix(new Fraction[][] {{}})};


        return new SquareMatrix[] {a, new SquareMatrix(new Fraction[][] {{}})};
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
                Fraction iFraction = matrix[2][2];
                return a.multiply(e).multiply(iFraction)
                        .add(b.multiply(f).multiply(g))
                        .add(c.multiply(h).multiply(d))
                        .subtract(c.multiply(e).multiply(g))
                        .subtract(h.multiply(f).multiply(a))
                        .subtract(b.multiply(d).multiply(iFraction));
            default:
                int zeroROW = 0;
                int countZeroRow = 0;
                int zeroCOLUMN = 0;
                int countZeroColumn = 0;
                for (int i = 1; i < matrix.length; i++)
                    if(new Vector(s, i, EnumVector.ROW).zeroCount() > new Vector(s, i - 1, EnumVector.ROW).zeroCount()) {
                        zeroROW = i;
                        countZeroRow = new Vector(s, i, EnumVector.ROW).zeroCount();
                    }

                for (int i = 1; i < matrix.length; i++)
                    if(new Vector(s, i, EnumVector.COLUMN).zeroCount() > new Vector(s, i - 1, EnumVector.COLUMN).zeroCount()) {
                        zeroCOLUMN = i;
                        countZeroColumn = new Vector(s, i, EnumVector.COLUMN).zeroCount();
                    }
                Vector startVector = new Vector(
                        s,
                        countZeroRow > countZeroColumn ? zeroROW : zeroCOLUMN,
                        countZeroRow > countZeroColumn ? EnumVector.ROW : EnumVector.COLUMN
                        );
                Fraction[] startMatrix = startVector.getVector();

                Fraction det = new Fraction(0);
                Fraction partialDet;
                for (int i = 0; i < startMatrix.length; i++) {
                    if (!startMatrix[i].equals(0)) {
                        String doubleSign = String.valueOf(Math.pow(-1, i + startVector.index + 2));
                        partialDet = new Fraction(doubleSign.substring(0, doubleSign.indexOf('.')))
                                        .multiply(startMatrix[i].multiply(det(s.clone().reduce(
                                                new int[] {1 + (startVector.type == EnumVector.ROW ? startVector.index : i)},
                                                new int[] {1 + (startVector.type == EnumVector.COLUMN ? startVector.index : i)}
                                        ))));
                        det = det.add(partialDet);
                    }
                }
                return det;
        }
    }

    public SquareMatrix clone() {
        return SquareMatrix.clone(this);
    }

    public static SquareMatrix clone(SquareMatrix a) {
        int N = a.getDimension().n;
        Fraction[][] newFraction = new Fraction[N][N];
        I.zeroLoop.exec(N, N, (i,j) -> newFraction[i][j] = a.getMatrix()[i][j]);
        return new SquareMatrix(newFraction);
    }
}