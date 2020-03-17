class Tester  {
	public static void main(String[] args) {
		Matrix a = new Matrix(new int[][] {
				{2, 3},
				{4, 5}
		});
		Matrix b = new Matrix(new int[][] {
				{5, 7, -4, 6},
				{6, -1, 12, -2}
		});

		Matrix c = new Matrix(new int [][] {
				{3, 3, 9},
				{3, 5, 0},
				{9, 0, 7}
		});

		Matrix d = new Matrix(2, 3, new Bound(5, true));
		Matrix e = new Matrix(3, 4, new Bound(5, true));
		Matrix f = new Matrix(4, 5, new Bound(5, true));
		Matrix g = new Matrix(5, 6, new Bound(5, true));
		Matrix h = new Matrix(6, 7, new Bound(5, true));
		Matrix i = new Matrix(7, 8, new Bound(5, true));

		Matrix[] arr = {a, b, c, d, e, f, g, h, i};

		for (Matrix m : arr)
			m.visualizza();

	}
}
