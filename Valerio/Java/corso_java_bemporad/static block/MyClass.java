class MyClass {
  static int x, y;

  static {
     System.out.println("Sono nel blocco static");
     x = 10;
     y = x * 10;
   }
}
