#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MASSIMO  256


int main(int argc, char const *argv[]) {

  int k, l;
  printf("Inserire stringa:\n" );
  char stringa [MASSIMO];
  fgets (stringa, sizeof (stringa), stdin);
  printf("Inserire chiave:\n" );
  scanf("%d",&k );

  if (k>26)
    k=k-((k%26)*26);
  if (k<0&&k>-27)
    k=k+26;
  if (k<-26)
    k=26+(k%26);



  l= strlen(stringa);
  char cypher [l];
  for(int i=0; i<l; i++){
    stringa[i]= tolower(stringa[i]);
    if(stringa[i]>='a' && stringa [i]<='z'){
      if (k+stringa[i]>'z'){
        cypher [i]= 'a'+k -('z'-stringa[i])-1;
      }else{
        cypher[i]=stringa[i]+k;
      }
    }else{
      cypher[i]=stringa[i];
    }
  }
  cypher[l]='\0';
  printf("%s\n", cypher);

  return 0;
}
