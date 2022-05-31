#include "Cuenta.h"

Cuenta :: Cuenta(string n, double s, int num) : ProductoBancario(n,s,num) {}

Cuenta :: ~Cuenta() {}

void Cuenta :: imprimir() {
	cout << "CUENTA DE ";
	ProductoBancario :: imprimir();
}

