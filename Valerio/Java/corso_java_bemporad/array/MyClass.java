public class MyClass {
  private int array[] = new int[10];
  public void printArray() {
    for (int i = 0; i < 10 ; i++) {
      array[i] = i;
      System.out.println(array[i]);
    }
  }
}
