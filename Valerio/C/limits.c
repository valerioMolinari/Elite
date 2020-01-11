#include <stdio.h>
#include <limits.h>

int main(void) {
  puts("");

  printf("CHAR_BIT%s:\t%-32s %-5s =  %d\n", "\t",
  "numero di bit in un byte ", "(\%d)",CHAR_BIT);
  printf("SCHAR_MIN%s:\t%-32s %-5s = %d \n", "\t",
  "minimo di un signed char ", "(\%d)",SCHAR_MIN);
  printf("SCHAR_MAX%s:\t%-32s %-5s =  %d\n", "\t",
  "massimo di un signed char ", "(\%d)",SCHAR_MAX);
  printf("UCHAR_MAX%s:\t%-32s %-5s =  %d\n", "\t",
  "massimo di un unsigned char ", "(\%d)",UCHAR_MAX);
  printf("SHRT_MIN%s:\t%-32s %-5s = %d\n", "\t",
  "minimo di un signed short ", "(\%d)",SHRT_MIN);
  printf("SHRT_MAX%s:\t%-32s %-5s =  %d\n", "\t",
  "massimo di un signed short ", "(\%d)",SHRT_MAX);
  printf("USHRT_MAX%s:\t%-32s %-5s =  %d\n", "\t",
  "massimo di un unsigned short ", "(\%d)",USHRT_MAX);
  printf("INT_MIN%s:\t%-32s %-5s = %d\n", "\t\t",
  "minimo di un signed int ", "(\%d)",INT_MIN);
  printf("INT_MAX%s:\t%-32s %-5s =  %d\n", "\t\t",
  "massimo di un signed int ", "(\%d)",INT_MAX);
  printf("UINT_MAX%s:\t%-32s %-5s =  %u\n", "\t",
  "massimo di un unsigned int ", "(\%u)",UINT_MAX);
  printf("LONG_MIN%s:\t%-32s %-5s = %ld\n", "\t",
  "minimo di un signed long int ", "(\%ld)",LONG_MIN);
  printf("LONG_MAX%s:\t%-32s %-5s =  %ld\n", "\t",
  "massimo di un signed long int ", "(\%ld)",LONG_MAX);
  printf("ULONG_MAX%s:\t%-32s %-5s =  %lu\n", "\t",
  "massimo di un unsigned long int", "(\%lu)",ULONG_MAX);

  puts("");
}
