class Test  {
	public static void main(String[] args) {
		Day compleanno = new Day(1998, 9, 18);
		Day today = new Day();

		System.out.println(today.daysFrom(compleanno));
	}
}