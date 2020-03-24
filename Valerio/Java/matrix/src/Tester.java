import java.util.Random;

class Tester  {
	public static void main(String[] args) throws SquareMatrixDimensionsException {
		Random r = new Random();
		int n1 = r.nextInt(3)+2;
		int nm = r.nextInt(3)+2;
		int n2 = r.nextInt(3)+2;
		int b1 = r.nextInt(5) + 5;
		int b2 = r.nextInt(5) + 5;
		boolean bool1 = r.nextBoolean();
		boolean bool2 = r.nextBoolean();

//		Matrix a = new Matrix(n1, nm, new Bound(b1, bool1));
//		Matrix b = new Matrix(nm, n2, new Bound(b2, bool2));
//		a.visualizza();
//		b.visualizza();
//		Matrix c = new Matrix(new String[][] {{"1","2","3/4"},{"2","1/2","1"},{"3","2","1"}});
		Matrix d = new Matrix(new String[][] {{"0","-2","3/4"},{"2","1/2","2"},{"3/4","2","1"}});

		//SquareMatrix e = new SquareMatrix(4,new Bound(10, false, "Double"));
		d.visualizza();
		//d.setRef().visualizza();
		Matrix e = Matrix.reduce(d, new int[] {3}, new int[] {3});
		e.visualizza();
		e.compose(
				new Vector(d, 2, EnumVector.ROW),
				new Vector(d, 2, EnumVector.COLUMN)
		).visualizza();
	}
}
