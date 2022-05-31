#include<iostream>
#include "ProductoBancario.h"
#include "Cuenta.h"
#include "Prestamo.h"
#include "CuentaJoven.h"
#include "Hipoteca.h"

using namespace std;

int main (int argc, char *argv[]) {
	ProductoBancario c1("Alejandro", 28.12, 20);
	c1.imprimir();
	
	Cuenta c2("Edson", 8.12, 20);
	c2.imprimir();
	
	Prestamo c3("Eduardo", 23.04, 20);
	c3.imprimir();
	
	CuentaJoven c4("Jose", 19.03, 20);
	c4.imprimir();
	
	Hipoteca c5("Silvia", 30.08, 20);
	c5.imprimir();
	
	return 0;
}

