#include "Prestamo.h"

Prestamo :: Prestamo(string n, double s, int num) : ProductoBancario(n,s,num) {}

Prestamo :: ~Prestamo () {}

void Prestamo :: imprimir() {
	cout << "PRESTAMO DEL ";
	ProductoBancario :: imprimir();
}
