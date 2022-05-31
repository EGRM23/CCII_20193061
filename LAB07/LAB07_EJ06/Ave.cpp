#include "Ave.h"

Ave :: Ave(string n) {
	nombre = n;
}

Ave :: ~Ave() {}

void Ave :: mostrardat() {
	cout << "AVE\n";
	cout << "Nombre: " << nombre << endl;
	cout << "Especie: " << tipo << endl;
	cout << "Cantidad de Patas: " << patas << endl;
	cout << "Puede Volar? ";
	if (volar == true)
		cout << "SI\n";
	else
		cout << "NO\n";
	
	cout << endl;
}
