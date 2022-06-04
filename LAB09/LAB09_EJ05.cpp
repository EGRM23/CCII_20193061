#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

template <typename R>
int ubicarasc (R* lista, int ini, int fin) {
	R aux;
	while (ini < fin) {
		while (lista[fin] >= lista[ini] && ini < fin)
			fin--;
		
		aux = lista[fin];
		lista[fin] = lista[ini];
		lista[ini] = aux;
		
		while (lista[ini] <= lista[fin] && ini < fin)
			ini++;
		
		aux = lista[fin];
		lista[fin] = lista[ini];
		lista[ini] = aux;
	}
	return ini;
}

template <typename R>
int ubicardesc (R* lista, int ini, int fin) {
	R aux;
	while (ini < fin) {
		while (lista[fin] <= lista[ini] && ini < fin)
			fin--;
		
		aux = lista[fin];
		lista[fin] = lista[ini];
		lista[ini] = aux;
		
		while (lista[ini] >= lista[fin] && ini < fin)
			ini++;
		
		aux = lista[fin];
		lista[fin] = lista[ini];
		lista[ini] = aux;
	}
	return ini;
}

template <typename R>
void ascendente (R* lista, int ini, int fin) {
	int u;
	if (ini < fin) {
		u = ubicarasc<R>(lista, ini, fin);
		ascendente<R>(lista, ini, u - 1);
		ascendente<R>(lista, u + 1, fin);
	}
}

template <typename R>
void descendente (R* lista, int ini, int fin) {
	int u;
	if (ini < fin) {
		u = ubicardesc<R>(lista, ini, fin);
		descendente<R>(lista, ini, u - 1);
		descendente<R>(lista, u + 1, fin);
	}
}

template <typename R>
void printLista(R* lista, int tam) {
	for (int i = 0; i < tam; i++)
		cout << lista[i] << " ";
	cout << endl;
}

int main(int argc, char *argv[]) {
	int ArrayEntero [9] = {5, 7, 2, 8, 6, 1, 3, 4, 9};
	int tamArrayEntero = sizeof(ArrayEntero) / sizeof(ArrayEntero[0]);
	float ArrayFloat [5] = {10.1, 8.4, 3.6, 4.4, 11.2};
	float tamArrayFloat = sizeof(ArrayFloat) / sizeof(ArrayFloat[0]);
	
	ascendente<int> (&ArrayEntero[0], 0, tamArrayEntero-1);
	cout << "Lista ArrayEntero ordenada ascendente: \n";
	printLista<int>(&ArrayEntero[0], tamArrayEntero);
	
	descendente<float> (&ArrayFloat[0], 0, tamArrayFloat-1);
	cout << "Lista ArrayFloat ordenada descendente: \n";
	printLista<float>(&ArrayFloat[0], tamArrayFloat);
	return 0;
}
