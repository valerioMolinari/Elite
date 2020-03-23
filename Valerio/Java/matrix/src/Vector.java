public class Vector  {
    private Fraction[] vector;

    public Vector(Matrix a, int index, EnumVector type) {
        Fraction[][] matrix = a.getMatrix();
        if (type == EnumVector.ROW)
            this.vector = matrix[index];
        else {
            vector = new Fraction[matrix.length];
            for (int i = 0; i < vector.length; i++)
                vector[i] = matrix[i][index];
        }
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

    public void visualizza() {
        System.out.print("{ ");
        for (int i = 0; i < vector.length; i++)
            System.out.print(i == vector.length - 1 ? vector[i] + " " : vector[i] + ", ");
        System.out.println("}");
    }

    public Fraction[] getVector() {
        return vector;
    }
}