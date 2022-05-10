#include <iostream>
using namespace std;

//EDUARDO GERMÁN RUIZ MAMANI
//20193061

//1. Asignar valores a dos variables enteras, intercambie estos valores almacenados
//	usando solo punteros a enteros.

void cambio (int *x, int *y) {
	int aux;
	
	aux = *x;
	*x = *y;
	*y = aux;
}


int main(int argc, char *argv[]) {
	int x = 5, y = 10;
	
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << endl;
	
	cambio(&x, &y);
	
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	return 0;
}

