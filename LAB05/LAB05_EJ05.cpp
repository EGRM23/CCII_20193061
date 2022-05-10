#include <iostream>
#include <string.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//5. Implemente su propia función de concatenación de cadenas de texto especial
//	(¡no es la función ordinaria de concatenación!), recibirá como parámetro
//	dos punteros de caracteres y tendrá que asignar el contenido del segundo
//	puntero al INICIO del primer puntero. La función no retorna ningún valor.

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

