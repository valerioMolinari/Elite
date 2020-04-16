#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//FUNZIONI ASCII ART
void print_gameover(void);
void print_lampeggio_gameover(void);
void print_nome(void);
void print_matricola(void);
void printfile(char str[]);

//FUNZIONI COLORI SHELL
void red (void);
void yellow (void);
void blu (void);
void magenta (void);
void green (void);
void cyan (void);
void reset (void);

//FUNZIONI MENU' PRINCIPALE
int crea_cunicoli (void);
int gioca (void);
int termina_gioco (void);
