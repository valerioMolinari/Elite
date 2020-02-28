class MyClass {
  private int x;
  private int y;

  public void view() {
    System.out.println(x+" "+y);
  }

  public static MyClass create(int x, int y) {
    MyClass mc = new MyClass();
    mc.x = x;
    mc.y = y;
    return mc;
  }
}
