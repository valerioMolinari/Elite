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
		Matrix c = new Matrix(new int[][] {{1,2,3},{-2,0,1},{3,2,1}});
		Matrix d = new Matrix(new int[][] {{4,1},{-1,-8},{-2,5},{-5,1}});
//		c.visualizza();
//		d.visualizza();
//		c.matrixProduct(d).visualizza();
//		c.matrixProduct(d).transpose();
		Matrix f = new Matrix(2,2,new Bound(5,true));
		Matrix g = new Matrix(2,2,new Bound(5,true));
		f.visualizza();
		g.visualizza();
		f.matrixProduct(g).visualizza();
	}
}
