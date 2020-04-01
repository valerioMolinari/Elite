#include <iostream>

using namespace std;

using MyStruct = struct myStruct {
	int value;
};

int main(void) {
	system("clear");

	/*
		In C++ la memoria viene allocata tramite la keyword "new" e deallocata
		tramite la keyword "delete". La zona in cui viene allocata tale
		memoria è detta "Free Store". È importante ricordare che la memoria
		allocata con new va sempre deallocata con delete e che solo la memoria
		allocata da new può essere deallocata da delete, in altre parole
		non possiamo usare delete su una zona di memoria non allocata da new
	*/

	// La seguente istruzione alloca memoria per un puntatore ad un elemento
	// di tipo struct myStruct
	MyStruct *ptr = new MyStruct;

	// Questa istruzione invece dealloca la memoria
	delete ptr;

	// In questo caso abbiamo allocato memoria per un array di elementi MyStruct
	// dove *ptrArr è un puntatore al primo elemento dell'array
	MyStruct *ptrArr = new MyStruct[30];

	// Così si dealloca tutto l'array
	delete[] ptrArr;

	// Esempio
	int *nPtr = new int;
	*nPtr = 10;

	cout << *nPtr << endl;
	delete nPtr;

	int *nPtrArr = new int[2];
	nPtrArr[0] = 20;
	*(nPtrArr + 1) = 30;

	for (int i = 0; i < 2; i++)
		cout << *(nPtr + i) << " ";
	cout << endl;

	delete[] nPtrArr;

	return 0;
}
