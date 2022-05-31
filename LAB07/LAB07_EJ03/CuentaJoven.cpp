#include "CuentaJoven.h"

CuentaJoven :: CuentaJoven(string n, double s, int num) : Cuenta(n,s,num) {}
	
CuentaJoven :: ~CuentaJoven() {}

void CuentaJoven :: imprimir() {
	cout << "CUENTA JOVEN DE ";
	ProductoBancario :: imprimir();
}

