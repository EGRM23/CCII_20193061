#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

template <typename R>
R mayorval (const R arr[], int tam) {
	R mayor = arr[0];
	
	for(int i = 1; i < tam; i++) {
		if (mayor < arr[i])
			mayor = arr[i];
	}
	
	return mayor;
}

template <typename R>
R menorval (const R arr[], int tam) {
	R menor = arr[0];
	
	for(int i = 1; i < tam; i++) {
		if (menor > arr[i])
			menor = arr[i];
	}
	
	return menor;
}

int main(int argc, char *argv[]) {
	int ArrayEntero [5] = {10, 7, 2, 8, 6};
	int tamArrayEntero = sizeof(ArrayEntero) / sizeof(ArrayEntero[0]);
	float ArrayFloat [5] = {12.1, 8.7, 5.6, 8.4, 1.2};
	float tamArrayFloat = sizeof(ArrayFloat) / sizeof(ArrayFloat[0]);
	
	cout << "Mayor Valor Array entero = " << mayorval<int> (ArrayEntero, tamArrayEntero) << endl;
	cout << "Menor Valor Arrat entero = " << menorval<int> (ArrayEntero, tamArrayEntero) << endl;
	cout << "Mayor Valor Array float = " << mayorval<float> (ArrayFloat, tamArrayFloat) << endl;
	cout << "Menor Valor Arrat float = " << menorval<float> (ArrayFloat, tamArrayFloat) << endl;
	return 0;
}

