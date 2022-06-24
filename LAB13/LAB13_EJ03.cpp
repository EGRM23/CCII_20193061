#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

struct jugador {
	string nombre;
	int edad;
	float talla;
};

typedef jugador Jugador10[10];

void ingresojugador (jugador &pj) {
	cout << "Nombre: ";
	getline(cin >> ws, pj.nombre);
	for (int i = 0; i < (int)pj.nombre.length(); i++)
		pj.nombre[i] = toupper(pj.nombre[i]);
	
	cout << pj.nombre;
	do {
		cout << "Edad: ";
		cin >> pj.edad;
		
		if (pj.edad <= 0)
			cout << "--> Ingrese una edad válida!\n";
	} while (pj.edad <= 0);
	
	do {
		cout << "Talla: ";
		cin >> pj.talla;
		
		if (pj.talla <= 0)
			cout << "--> Ingrese una talla válida!\n";
	} while (pj.talla <= 0);
	
	cout << endl;
}

void mostrarjugador (jugador n) {
	cout << n.nombre;
	cout << ",	Edad: " << n.edad;
	cout << ",	Talla: " << n.talla;
	cout << endl;
}

int main(int argc, char *argv[]) {
	int n = 10;
	
	Jugador10 equipo;
	
	//VALORES EJEMPLO
//	equipo[0].nombre = "Eduardo"; 	equipo[0].edad = 20; equipo[0].talla = 1.75;
//	equipo[1].nombre = "Fernando"; 	equipo[1].edad = 17; equipo[1].talla = 1.80;
//	equipo[2].nombre = "Jose"; 		equipo[2].edad = 21; equipo[2].talla = 1.72;
//	equipo[3].nombre = "Silvia"; 	equipo[3].edad = 18; equipo[3].talla = 1.71;
//	equipo[4].nombre = "Edson"; 	equipo[4].edad = 19; equipo[4].talla = 1.71;
//	equipo[5].nombre = "Joaquin"; 	equipo[5].edad = 22; equipo[5].talla = 1.72;
//	equipo[6].nombre = "Sebastian"; equipo[6].edad = 20; equipo[6].talla = 1.68;
//	equipo[7].nombre = "Stephanie";	equipo[7].edad = 19; equipo[7].talla = 1.71;
//	equipo[8].nombre = "Victor";	equipo[8].edad = 18; equipo[8].talla = 1.65;
//	equipo[9].nombre = "Galy";		equipo[9].edad = 19; equipo[9].talla = 1.70;
	
	for (int i = 0; i < n; i++) {
		cout << "JUGADOR " << i+1 << endl;
		ingresojugador(equipo[i]);
	}

	cout << "JUGADORES MENORES DE 20 Y CON MAS DE 1.70 m\n";
	for (int i = 0; i < n; i++) {
		if (equipo[i].edad < 20) {
			if (equipo[i].talla > 1.70) {
				cout << i+1 << ". ";
				mostrarjugador(equipo[i]);
			}
		}
	}
	return 0;
}
