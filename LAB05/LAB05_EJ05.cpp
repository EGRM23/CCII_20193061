#include <iostream>
#include <string.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//5. Implemente su propia funci�n de concatenaci�n de cadenas de texto especial
//	(�no es la funci�n ordinaria de concatenaci�n!), recibir� como par�metro
//	dos punteros de caracteres y tendr� que asignar el contenido del segundo
//	puntero al INICIO del primer puntero. La funci�n no retorna ning�n valor.

void concat (string *cadena_1, string *cadena_2) {
	*cadena_1 = *cadena_2 + *cadena_1;
}

int main(int argc, char *argv[]) {
	string c1, c2;
	
	c1 = "Ruiz";
	c2 = "Eduardo";
	
	concat(&c1, &c2);
	
	cout << c1 << " " << c2;
	return 0;
}

