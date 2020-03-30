public class Vector  {
    private Fraction[] vector;
    private Dimension dimension;
    public final EnumVector type;
    public final int index;

    public Vector(Matrix a, int index, EnumVector type) {
        this.type = type;
        this.index = index;
        Fraction[][] matrix = a.getMatrix();
        if (type == EnumVector.ROW) {
            this.vector = matrix[index];
            dimension = new Dimension(1, a.getDimension().m);
        } else {
            vector = new Fraction[matrix.length];
            for (int i = 0; i < vector.length; i++)
                vector[i] = matrix[i][index];
            dimension = new Dimension(a.getDimension().n, 1);
        }
    }

    public Vector(Vector v) {
        this.vector = v.vector;
        this.dimension = v.dimension;
        this.type = v.type;
        this.index = v.index;
    }

    public Vector(Fraction[] vector, Vector v) {
        this.vector = vector;
        this.dimension = v.dimension;
        this.type = v.type;
        this.index = v.index;
    }

    public boolean isZeroNull() {
        return isZeroNull(this);
    }

    public static boolean isZeroNull(Vector v) {
        Fraction[] V = v.getVector();
        for (int i = 0; i < V.length; i++)
            if (!V[i].equals(0))
                return false;
        return true;
    }

    public int zeroCount() {
        return zeroCount(this);
    }

    public static int zeroCount(Vector v) {
        int count = 0;
        Fraction[] vector = v.vector;
        for (Fraction f : vector)
            if (f.equals(0))
                count++;
        return count;
    }

    public Vector slice(int start) {
        return slice(this, start);
    }

    public Vector slice(int start, int end) {
        return slice(this, start, end);
    }

    public static Vector slice(Vector v, int start) {
        int length = v.vector.length - start;
        Fraction[] newVector = new Fraction[length];
        System.arraycopy(v.vector, start, newVector, 0, length);
        return new Vector(newVector, v);
    }

    public static Vector slice(Vector v, int start, int end) {
        int length = v.vector.length - (start + end);
        Fraction[] newVector = new Fraction[length];
        System.arraycopy(v.vector, start, newVector, 0, length);
        return new Vector(newVector, v);
    }

    public void visualizza() {
        System.out.print("{ ");
        for (int i = 0; i < vector.length; i++)
            System.out.print(i == vector.length - 1 ? vector[i] + " " : vector[i] + ", ");
        System.out.println("}");
    }

    public Fraction[] getVector() {
        return vector;
    }

    public Dimension getDimension() {
        return dimension;
    }
}