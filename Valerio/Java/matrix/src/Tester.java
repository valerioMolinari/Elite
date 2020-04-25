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

		new SquareMatrix(new String[][] {
				{"1", "0", "1"},
				{"3", "2", "4"},
				{"1", "-6", "-2"}
		}).det().visualizza();
	}
}
