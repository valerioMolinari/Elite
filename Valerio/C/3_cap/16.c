#include <stdio.h>

int main(void) {
  float gallons = 0;
  int miles;
  float average = 0;
  float count = 0;
  while (1) {
    printf("Enter the gallons used (-1 to end): ");
    scanf("%f", &gallons);
    if (gallons == -1) break;
    printf("Enter the miles driven: ");
    scanf("%d", &miles);
    printf("The miles/gallons for this tank was %f\n\n", miles/gallons);
    average += miles/gallons;
    count++;
  }
  printf("\nThe overall average miles/gallon was %f\n", average/count);
}
