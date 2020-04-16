#include <stdio.h>
#include <stdlib.h>

struct Linked_list
  {
    char d;
    struct Linked_list *next;
  };

//CONTARE GLI ELEMENTI DI UNA LISTA
int count (struct Linked_list *head)
  {
    int cnt = 0;
    for ( ; head != NULL; head = head -> next)
      cnt++;
    return cnt;
  }

//STAMPA GLI ELEMENTI DELLA LISTA RICORSIVAMENTE
void print_list (struct Linked_list *head)
  {
    if (head == NULL)
      printf ("NULL");
    else
      {
        printf("%c --> ", head -> d);
        print_list (head -> next);
      }
    printf("\n");
  }

int main ()
  {
    int elementi_lista;
    struct Linked_list *head = (struct Linked_list*) malloc (sizeof(struct Linked_list));
    head -> d = 'c';
    head -> next = NULL;
    printf("%c\n",head -> d);
    printf("%p\n",head -> next);
    head -> next = malloc (sizeof(struct Linked_list));
    head -> next -> d = 'i';
    head -> next -> next = NULL;
    printf("%c  %c\n",head -> d, head -> next -> d);
    printf("%p  %p\n",head -> next, head -> next -> next);
    elementi_lista = count (head);
    printf("Numero elementi lista: %d\n", elementi_lista);
    print_list(head);
  }
