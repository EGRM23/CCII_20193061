#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "ArbolBinario.h"
using namespace std;

int main (int argc, char *argv[]) {
	srand(time(NULL));
	
	int cantnodos;
	cout << "Numero de datos: ";
	cin >> cantnodos;
	cout << endl;
	
	ArbolBinario<int>* arbolint = new ArbolBinario<int>();

	int valor;
	for(int i = 0; i < cantnodos; i++) {
		valor = 1 + rand()%(200 - 1);
		arbolint->insertar(valor);
	}
	
	arbolint->imprimir();
	
	delete arbolint;
	return 0;
}

