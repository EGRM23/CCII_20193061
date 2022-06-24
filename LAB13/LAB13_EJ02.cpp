#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

struct alumno {
	string nombre;
	char grupo;
	int nota_1;
	int nota_2;
	int nota_3;
	int nota_pryctfin;
	float promed_fin;
};

typedef alumno Est;

Est ingresoAlumno () {
	string nom;
	char g;
	int n1, n2, n3, npf;
	float pf;
	
	cout << "Nombre: ";
	getline(cin >> ws,nom);
	for (int i = 0; i < (int)nom.length(); i++)
		nom[i] = toupper(nom[i]);
	
	do {
		cout << "Grupo(A-B-C): ";
		cin >> g;
		g = toupper(g);
		
		if (g != 'A' && g != 'B' && g != 'C')
			cout << "--> Ingrese un grupo válido!\n";
	} while (g != 'A' && g != 'B' && g != 'C');
	
	do {
		cout << "Nota 1: ";
		cin >> n1;
		
		if (n1 < 0 || n1 > 20)
			cout << "--> Ingrese una nota válida!\n";
	} while (n1 < 0 || n1 > 20);
	
	do {
		cout << "Nota 2: ";
		cin >> n2;
		
		if (n2 < 0 || n2 > 20)
			cout << "--> Ingrese una nota válida!\n";
	} while (n2 < 0 || n2 > 20);
	
	do {
		cout << "Nota 3: ";
		cin >> n3;
		
		if (n3 < 0 || n3 > 20)
			cout << "--> Ingrese una nota válida!\n";
	} while (n3 < 0 || n3 > 20);
	
	do {
		cout << "Nota Proyecto Final: ";
		cin >> npf;
		
		if (npf < 0 || npf > 20)
			cout << "--> Ingrese una nota válida!\n";
	} while (npf < 0 || npf > 20);
	
	pf = 0.15*n1 + 0.20*n2 + 0.25*n3 + 0.40*npf;
	
	Est temp = {nom, g, n1, n2, n3, npf, pf};
	
	cout << endl;
	return temp; 
}

void mostrarpromedio(Est n) {
	cout << n.nombre;
	cout << "	Promedio: " << n.promed_fin << endl;
}

int main(int argc, char *argv[]) {
	int n;
	
	cout << "Cuántos alumnos desea ingresar? ";
	cin >> n;
	cout << endl;
	
	Est* alumCC = new Est[n];
	
	for (int i = 0; i < n; i++) {
		cout << "ESTUDIANTE " << i+1 << endl;
		alumCC[i] = ingresoAlumno();
	}
	
	cout << "NOTAS FINALES DEL CURSO DE CIENCIAS DE LA COMPUTACION\n";
	for (int i = 0; i < n; i++) {
		cout << i+1 << ". ";
		mostrarpromedio(alumCC[i]);
	}
	
	delete[] alumCC;

	return 0;
}

