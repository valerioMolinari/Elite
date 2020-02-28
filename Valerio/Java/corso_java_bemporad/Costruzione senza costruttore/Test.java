 class Test import MyClass.class{
  public static void main(String[] args) {
    MyClass mc1 = MyClass.create(10,15);
    MyClass mc2 = MyClass.create(20,30);
    mc1.view();
    mc2.view();
  }
}
