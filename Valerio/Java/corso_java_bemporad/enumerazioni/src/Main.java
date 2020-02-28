class Main {
	public static void main(String[] args) {
		Taglia s = Taglia.SMALL;
		Taglia m = Taglia.MEDIUM;
		System.out.println(s+"\n"+m);
		TagliaCostruttore xs = TagliaCostruttore.EXTRASMALL;
		TagliaCostruttore xl = TagliaCostruttore.EXTRALARGE;
		System.out.println(xs.getValore());
		System.out.println(xl.getValore());
		System.out.println();
		int ord = m.ordinal();
		int t1 = s.compareTo(m);
		int t2 = m.compareTo(Taglia.MEDIUM);
		int t3 = Taglia.LARGE.compareTo(Taglia.EXTRASMALL);
		System.out.println(ord + "\n" + t1 + "\n" + t2 + "\n" + t3);
	}
}