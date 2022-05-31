#include "Hipoteca.h"

Hipoteca :: Hipoteca(string n, double s, int num) : Prestamo(n,s,num) {}
	
Hipoteca :: ~Hipoteca() {}

void Hipoteca :: imprimir() {
	cout << "HIPOTECA EN EL ";
	Prestamo :: imprimir();
}

