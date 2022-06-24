#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
// CUI: 20193061

struct fecha {
	int dia;
	int mes;
	int anio;
	string nombre_mes[9];
};

typedef fecha Fecha;

struct persona {
	char nombre[10];
	Fecha fecu;
};

typedef persona Persona;
typedef char Nombre[10];

void asignardatos (Persona &p, Nombre n, Fecha f) {
	for (int i = 0; i < 10; i++) {
		p.nombre[i] = n[i];
	}
	p.fecu = f;
}

int main(int argc, char *argv[]) {
	Persona compa[5];
	Nombre n[5] = {"German", "Edson", "Victor", "Jose", "Silvia"};
	Fecha f[5] = {{23,4,2002,"Abril"},{8,12,2002,"Diciembre"},{28,12,2022,"Diciembre"},{19,3,2002,"Marzo"},{30,8,2002,"Agosto"}};

	for (int i = 0; i < 5; i++) {
		asignardatos(compa[i], n[i], f[i]) ;
	}

	for (int i = 0; i < 5; i++) {
		if ((compa[i].fecu).mes == 12) {
			for (int j = 0; j < 10; j++) {
				cout << compa[i].nombre[j];
			}
			cout << " cumple anios este mes\n";
		}
	}
	return 0;
}

