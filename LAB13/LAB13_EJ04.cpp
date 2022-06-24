#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

struct trabajador {
	string nombre;
	char sexo;
	int sueldo;
};

typedef trabajador Empl;

void ingresotrabajador (Empl &em) {
	cout << "Nombre: ";
	getline(cin >> ws, em.nombre);
	for (int i = 0; i < (int)em.nombre.length(); i++)
		em.nombre[i] = toupper(em.nombre[i]);
	
	do {
		cout << "Sexo(M-F): ";
		cin >> em.sexo;
		em.sexo = toupper(em.sexo);
		
		if (em.sexo != 'M' && em.sexo != 'F')
			cout << "--> Ingrese un valor válido!\n";
	} while (em.sexo != 'M' && em.sexo != 'F');
	
	do {
		cout << "Sueldo: ";
		cin >> em.sueldo;
		
		if (em.sueldo <= 0)
			cout << "--> Ingrese un sueldo válido!\n";
	} while (em.sueldo <= 0);
	
	cout << endl;
}

void mostrarempleado (Empl n) {
	cout << n.nombre;
	cout << ",	Sexo: " << n.sexo;
	cout << ",	Sueldo: " << n.sueldo;
	cout << endl;
}

int main(int argc, char *argv[]) {
	int n;
	
	cout << "Cuántos empleados desea ingresar? ";
	cin >> n;
	cout << endl;
	
	Empl* empresa = new Empl[n];
	
	for (int i = 0; i < n; i++) {
		cout << "EMPLEADO " << i+1 << endl;
		ingresotrabajador(empresa[i]);
	}
	
	int men = 0, may = 0;
	for (int i = 0; i < n; i++) {
		if (empresa[men].sueldo > empresa[i].sueldo)
			men = i;
		else if (empresa[may].sueldo < empresa[i].sueldo)
			may = i;
	}
	
	cout << "MENOR SUELDO\n";
	cout << "Empleado " << men+1 << ". ";
	mostrarempleado(empresa[men]);
	cout << "MAYOR SUELDO\n";
	cout << "Empleado " << may+1 << ". ";
	mostrarempleado(empresa[may]);
	return 0;
}

