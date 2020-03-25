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
		Matrix d = new Matrix(new String[][] {
				{"5", "15", "97", "1", "0"},
				{"66", "0", "1", "-2", "7"},
				{"83", "100", "9", "0", "88"},
				{"1/2", "1/4", "1/9", "0", "1"},
				{"107", "35", "29", "0", "1"}
		});
		Matrix e = new Matrix(new String[][] {
				{"3", "5", "1", "1"},
				{"2", "0", "3", "0"},
				{"0", "1", "5", "8"}
		});
		Matrix f = new Matrix(new String[][] {
				{"1", "-1", "1", "3"},
				{"0", "1", "4", "0"},
				{"0", "0", "0", "1"}
		});
		SquareMatrix g = new SquareMatrix(new String[][] {
				{"1", "2", "2"},
				{"2", "1", "-2"},
				{"2", "-2", "1"}
		});
		g.det().visualizza();
	}
}
