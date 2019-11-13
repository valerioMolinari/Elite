/*******************************************************************************
************* nome: Gaia********************************************************
*************cognome: Maresca***************************************************
*************matricola: 320161**************************************************
*************testo esonero: si vuole un programa che cifri la parola o il testo
*************in due differenti crifrari 'Cesare' o 'Sostituzione'***************
*******************************************************************************/

//NOME FILE: string_crypto.c


#include <stdio.h> //libreria che gestisce l'input e l'output
#include <stdbool.h> //libreria che gestisce le variabili booleane
#include <string.h> //libreria che gestisce le stringhe
#include <ctype.h> //librearia che gestisce le funzioni 'isdigit()' e 'isalpha()'

void main(){

  char parola[256]; //Parola da cofidicare
  int scelta = 0; //Variabile per la scelta della cifratura
                  //'1' per il Cifrario di Cesare
                  //'2' per il Cifrario per Sostituzione
  int k = 0; //Chiave che verrà utilizzata per la cifratura
  int len = 0; //Variabile per la lunghezza vera e propria della stringa
  int c = 0; //c = (m+k)%26
                // 'm' -> lettera da cifrare
                // 'k' -> chiave immessa per la cifratura
                // '%26' -> utilizzato per rimanere nel range delle lettere

  bool continua = 1;
  char z;


  char alfabeto; //Carattere per la scelta della modalità per sostituzione
                //'m' per selezionare la cifratura 'manuale'
                //'r' per la cifratura random

  //array di caratteri di grandezza len
  //la sua funzione è quella di contenere la nuova parola cifrata
  char cifrata[len];
  char cifrario[len];
  char r[len];

  do{

    printf("Immettere la parola da codificare:\n");

    //scanf("%[^\n]", parola ); //lo inserisce da tastiera fino all'invio
    //gets(parola); //prende in input una stringa compresi gli spazi(si ha un warning sull'unsafe della gets)
                                                                  //perché non controlla il buffer overflow

    fgets(parola, sizeof(parola),stdin);//anche questa legge gli spazi, ma è più sicura
                                        //perché non va in buffer overflow visto che si controlla la lunghezza della stringa


    printf ("Decidere la modalita' di cifratura.\n");
    printf("Si scelga '1' se si vuole cifrare con Cesare.\n");
    printf("Si scelga '2' se si vuole cifrare per sostituzione.\n");

    scanf("%d\n", scelta);

    continua = 0;

    switch (scelta) {
      case '1':
        printf("Si e' scelto il Cifrario di Cesare!\n"); //Si cifrerà secondo il codice di Cesare

        printf("Inserire la chiave con cui si vuole codificare: %d\n");
        scanf("%d\n", k);

        len = strlen(parola); //Funzione che conta le lettere di una stringa


        for (int i = 0; i < len; i++){

          c = (parola[i] + k)%26; //Si calcola con quale lettera verrà cifrata la lettera corrente

          cifrata[i] = parola[i] + c; //Array di appoggio per la stringa cifrata

        }

        printf("La parola cifrata e': %s\n");

        for (int i = 0; i < len; i++) //Iterazione per la stampa della parola cifrata
            scanf(cifrata[i]);

        break;


      case '2':

        printf("Si e' scelto il Cifrario per Sostituzione!\n"); //Si cifrerà secondo il codice di sostituzione

        printf("Ora si scelga come si vuole la sostituzione.\n");
        printf("Si scelga 'm' per una sostituzione con un alfabero inserito manualmente\n");
        printf("Si scelga 'r' per una sostituzione con alfabeto prenso in modo random\n");

        scanf("%c\n", alfabeto);

        switch (alfabeto) {
          case 'm':
          //si inserisca l'alfabeto in modo automatico per la cifratura 'manuale'

            printf("Si inserisca il cifrario che si vuole utilizzare: \n");

            for (int i = 0; i < len; i++){

              scanf("%c\n", cifrario[i]);

              if (isdigit(cifrario[i]) != 0 || isalnum(cifrario[i]) != 0){

                printf("L'elemento inserito non e' valido.\n");
                printf("Si prega di reinserire la lettera.\n");

              }else if (cifrario[i] == cifrario[i-1]){

                printf("Le lettere devo differire nel cifrario\n");

              }
            }

            for (int i = 0; i < 26; i++){

              parola[i] = cifrario[i];

              printf("%s\n", parola );
            }

            break;

          case 'r':
            //si usi una funzione random per la cifratura con un alfabeto preso 'casualmente'

            for (int i = 0; i < len; i++){

              r[i] = random();

              if ((r[i] == r[i-1]) && (isdigit(r[i]) == 0) && (isalnum(r[i]) == 0)){
                r[i] = random();
              }

              printf("%c\n", r[i]);
            }

            for (int i = 0; i < len; i++){

              parola[i] = r[i];

              printf("%s\n", parola );
            }

            break;

          default:
            printf("La scelta inserita non e' tra quelle disponibili!\n");
          break;
        }
        break;

      default:
        printf("L'opzione scelta non e' valida!\n");
        break;
    }

    printf("Si vuole continuare con la conversione?(y/N)\n");
    scanf("%c\n", z);

    if (z == 'y')
        continua = 1;

  }while (continua == 1);
}
