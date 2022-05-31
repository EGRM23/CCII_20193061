#include "ProductoBancario.h"

ProductoBancario :: ProductoBancario(string n, double s, int num) {
	cliente = n;
	saldo = s;
	numProductos = num;
}

ProductoBancario :: ~ProductoBancario() {}

void ProductoBancario :: imprimir() {
	cout << "CLIENTE\n";
	cout << "Nombre: " << cliente << endl;
	cout << "Saldo: " << saldo << endl;
	cout << "Cantidad de Productos: " << numProductos << endl << endl;
}

