class Main  {
	public static void main(String[] args) throws MyException {
		try {
			throw new MyException();
		} catch (MyException e){
			System.out.println(e);
		}
		throw new MyException();
	}
}