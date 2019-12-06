#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum classe {PRIMA = 1, ECONOMY};

struct persona {
	char nome[30];
	char cognome[30];
	enum classe classe;
	unsigned short posto;
	struct persona *nextPtr;
};

typedef struct persona Persona;
typedef Persona *PersonaPtr;

unsigned int sceltaClasse(PersonaPtr listaPersone, enum classe classe);
unsigned int acquista(PersonaPtr *listaPersone, enum classe classe);
void istruzioni();
void cartaImbarco(PersonaPtr personaCorrente);
void listaPasseggeri(PersonaPtr listaPersone);
unsigned int postiDisponibili(PersonaPtr listaPersone);
char * nomeClasse(enum classe classe);
unsigned int isEmpty(PersonaPtr currentPtr);
void removeReturnChar(char * string);
unsigned int cambiaScelta(enum classe classe);

int main(void) {
	system("clear");
	PersonaPtr passeggeri = NULL;
	int scelta;
	unsigned int disponibilità;

	puts("Benvenuto alla nostra compagnia aerea\n");
	istruzioni();
	printf("> ");
	scanf("%d", &scelta);

	while (scelta != 3) {
		switch (scelta) {
			case 1:
				disponibilità = sceltaClasse(passeggeri, PRIMA);
				if (!disponibilità && !cambiaScelta(PRIMA)) {
					puts("\nIl prossimo volo parte tra tre ore\n");
					break;
				}
				if (!acquista(&passeggeri, disponibilità ? PRIMA : ECONOMY))
					return 0;
				break;
			case 2:
				disponibilità = sceltaClasse(passeggeri, ECONOMY);
				if (!disponibilità && !cambiaScelta(ECONOMY)) {
					puts("\nIl prossimo volo parte tra tre ore\n");
					break;
				}
				if (!acquista(&passeggeri, disponibilità ? ECONOMY : PRIMA))
					return 0;
				break;
			default:
				puts("\nScelta non valida\n");
				istruzioni();
		}
		if (!postiDisponibili(passeggeri)) {
			system("sleep 1");
			system("clear");
			puts("\nLista Passeggeri");
			for (size_t i = 0; i < 50; i++)
				putchar('-');
			puts("");
			system("sleep 1");
			listaPasseggeri(passeggeri);
			puts("");
			for (size_t i = 0; i < 50; i++)
				putchar('-');
			puts("\n\nPurtroppo i posti sono esauiriti");
			break;
		}
		printf("\n> ");
		scanf("%d", &scelta);
	}
	puts("Ci scusiamo per il disagio. Il prossimo volo parte tra tre ore\nA presto!\n");
}

unsigned int sceltaClasse(PersonaPtr listaPersone, enum classe classe) {
	if (listaPersone == NULL)
		return 1;
	else {
		unsigned int count = 0;
		while (listaPersone != NULL) {
			if (listaPersone->classe == classe)
				count++;
			listaPersone = listaPersone->nextPtr;
		}
		return count < 5 ? 1 : 0;
	}
}

unsigned int acquista(PersonaPtr *listaPersone, enum classe classe) {
	PersonaPtr nuovaPersona = malloc(sizeof(Persona));

	if (isEmpty(nuovaPersona)) {
		printf("Non è possibile prenotare altri posti a causa di un errore di memoria interno al programma, siamo spiacenti\n");
		return 0;
	}

	unsigned int posto = 1;

	nuovaPersona->classe = classe;
	nuovaPersona->posto = posto;
	nuovaPersona->nextPtr = NULL;

	printf("\nHa scelto di viaggiare in %s, inserisca: \n\n", nomeClasse(classe));

	printf("Nome: ");
	scanf("\n");
	fgets(nuovaPersona->nome, 30, stdin);
	printf("Cognome: ");
	fgets(nuovaPersona->cognome, 30, stdin);

	removeReturnChar(nuovaPersona->nome);
	removeReturnChar(nuovaPersona->cognome);

	if (isEmpty(*listaPersone))
		*listaPersone = nuovaPersona;
	else {
		PersonaPtr personaPrecedente = NULL;
		PersonaPtr personaCorrente = *listaPersone;
		while (personaCorrente != NULL) {
			personaPrecedente = personaCorrente;
			personaCorrente = personaCorrente->nextPtr;
			if (personaPrecedente->classe == classe)
				++posto;
		}
		nuovaPersona->posto = posto;
		personaPrecedente->nextPtr = nuovaPersona;
	}

	cartaImbarco(nuovaPersona);
	return 1;
}

void istruzioni() {
	puts("Inserisci:\n"
			 "\t1. Per acquistare un biglietto in prima classe\n"
			 "\t2. Per acquistare un biglietto in classe economy\n"
			 "\t3. Per uscire dal sito\n"
	);
}

void cartaImbarco(PersonaPtr personaCorrente) {
	puts("\nCarta d'imbarco\n");
	for (size_t i = 0; i < 49; i++)
		putchar('-');
	puts("");
	putchar('|');
	for (size_t i = 0; i < 47; i++)
		printf(" ");
	putchar('|');
	printf("\n|     Nome: %33s   |\n", personaCorrente->nome);
	printf("|     Cognome: %30s   |\n", personaCorrente->cognome);
	printf("|     Classe: %31s   |\n", nomeClasse(personaCorrente->classe));
	printf("|     Posto: %32d   |\n", personaCorrente->posto);
	putchar('|');
	for (size_t i = 0; i < 47; i++)
		printf(" ");
	puts("|");
	for (size_t i = 0; i < 49; i++)
		putchar('-');
	puts("");
}

unsigned int postiDisponibili(PersonaPtr listaPersone) {
	unsigned int count = 10;
	while (!isEmpty(listaPersone)) {
		listaPersone = listaPersone->nextPtr;
		count--;
	}
	return count;
}

char * nomeClasse(enum classe classe) {
	switch (classe) {
		case PRIMA: return "prima classe"; break;
		case ECONOMY: return "classe economy";
	}
}

unsigned int isEmpty(PersonaPtr currentPtr) {
	return currentPtr == NULL;
}

void removeReturnChar(char * string) {
	string[strlen(string)-1] = '\0';
}
unsigned int cambiaScelta(enum classe classe) {
	char conferma;
	printf("\nPurtroppo i posti per la %s sono esauiriti, vorresti comunque comprare un biglietto di %s? (Y/n)\n> ",
				 nomeClasse(classe), nomeClasse(classe == PRIMA ? ECONOMY : PRIMA)
	);
	scanf("%c", &conferma);
	while (tolower(conferma) != 'y' && tolower(conferma) != 'n')  {
		printf("Scelta sbagliata, vuoi cambiare biglietto? (Y/n)\n> ");
		scanf("%c", &conferma);
	}
	return conferma == 'y' ? 1 : 0;
}

void listaPasseggeri(PersonaPtr listaPersone) {
	PersonaPtr temp = listaPersone;
	while (temp != NULL) {
		if (temp->classe == PRIMA) {
			system("sleep 0.3");
			cartaImbarco(temp);
		}
		temp = temp->nextPtr;
	}
	temp = listaPersone;
	while (temp != NULL) {
		if (temp->classe == ECONOMY) {
			system("sleep 0.3");
			cartaImbarco(temp);
		}
		temp = temp->nextPtr;
	}
}
