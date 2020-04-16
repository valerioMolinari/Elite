#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

  int  chiave_int=0, chiave_temp_int=0, chiave_errata=0;
  char chiave_char [3];
  char chiave_sicurezza [15];
do
  {
    chiave_errata = 0;
    chiave_int = 0;
    chiave_temp_int = 0;

    printf  ("Inserisci chiave di criptazione (da 1 a 26): \n");
    fgets   (chiave_sicurezza, sizeof(chiave_sicurezza), stdin);
    getchar ();
    strncpy (chiave_char, chiave_sicurezza, sizeof(chiave_char));
    chiave_char [2] = '\0';
    printf  ("RIGA 19. Chiave sicurezza:\n%s\n",chiave_sicurezza);
    printf  ("RIGA 21. chiave_char: %s\n",chiave_char);

     for (int i=0; chiave_char[i] != '\0'; i++)
      {
        printf("RIGA 26. chiave_int: %d\n",chiave_int);
        printf("RIGA 28. chiave_char[%d]: %c, %d\n",i,chiave_char[i], chiave_char[i]);
        if(chiave_char[i] >= 48 && chiave_char[i] <= 57)
         {
          if(i == 0)
            {
              switch (chiave_char[i])
                {
                  case '0':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '1':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '2':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '3':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '4':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '5':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '6':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '7':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '8':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                  case '9':
                    chiave_temp_int = (chiave_char[i] -48) *10;
                    break;
                }
              printf("RIGA 64. chiave_temp_int: %d\n",chiave_temp_int);
              chiave_int = chiave_int + chiave_temp_int;
              printf("RIGA 67. chiave_int: %d\n",chiave_int);
            }
          else
            {
              switch (chiave_char[i])
                {
                  case '0':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '1':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '2':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '3':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '4':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '5':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '6':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '7':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '8':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                  case '9':
                    chiave_temp_int = chiave_char[i] -48;
                    break;
                }
              printf("RIGA 102. chiave_temp_int: %d\n",chiave_temp_int);
              chiave_int = chiave_int + chiave_temp_int;
            }

         }
        else
         {
           printf ("%s\n%s\n","RIGA 109. Chiave errata. Deve essere compresa fra 1 e 26","Inserisci nuova chiave di criptazione (da 1 a 26):");
           chiave_errata = 1;
           break;
         }
      }
    if (chiave_int < 1 || chiave_int > 26)
      {
        printf ("%s\n%s\n","RIGA 116. Chiave errata. Deve essere compresa fra 1 e 26","Inserisci nuova chiave di criptazione (da 1 a 26):");
        chiave_errata = 1;
      }

   }while(chiave_errata == 1);

  printf("RIGA 122. chiave_int: %d\n",chiave_int);


}
