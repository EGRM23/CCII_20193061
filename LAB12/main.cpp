#include<iostream>
#include "Item.h"
#include "Cola.h"
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

template <typename R>
void comparacion (int iter, Cola<R>* H, Cola<R>* M) {
	Cola<R>* mayor;
	int aux;
	int cont = iter;
	while (cont > 0) {
		
		if ((H->primero()) >= (M->primero()))
			mayor = H;
		else
			mayor = M;
		
		aux = H->primero();
		H->salida();
		H->ingreso(aux);
		
		aux = M->primero();
		M->salida();
		M->ingreso(aux);
		
		cont--;
	}
	
	cout << "En la iteracion " << iter
			<< " es mayor " << mayor->getnombre() << endl; 
}

int main (int argc, char *argv[]) {
	
	Cola<int> c1("1");
	cout << "Se ha creado la pila 1\n";
	
	c1.ingreso(5);
	c1.ingreso(7);
	c1.ingreso(10);
	c1.mostrarcola();
	cout << "---> Se ha ingresado 3 datos\n";
	
	c1.salida();
	c1.mostrarcola();
	cout << "---> Se ha eliminado 1 dato\n";
	
	c1.salida();
	c1.mostrarcola();
	cout << "---> Se ha eliminado 1 dato\n";
	
	c1.salida();
	c1.mostrarcola();
	cout << "---> Se ha eliminado 1 dato\n";
	
	c1.ingreso(9);
	c1.ingreso(12);
	c1.ingreso(15);
	c1.mostrarcola();
	cout << "---> Se ha ingresado 3 datos\n";
	
	int n = 12;
	cout << "\nBuscando " << n << "...\n";
	if (c1.find(n) == true)
		cout << "Elemento encontrado\n";
	else
		cout << "No se encuentra en la cola\n";
	
	n = 7;
	cout << "Buscando " << n << "...\n";
	if (c1.find(n) == true)
		cout << "Elemento encontrado\n";
	else
		cout << "No se encuentra en la cola\n";
	
	cout << "---------------------------------------------------------------";
	
	cout << endl << "\nPROBLEMA COMPARACION\n";
	
	Cola<int> H("Los Hombres");
	Cola<int> M("Las Mujeres");
	
	H.ingreso(22);
	H.ingreso(12);
	H.ingreso(15);
	M.ingreso(17);
	M.ingreso(21);
	M.ingreso(18);
	M.ingreso(26);
	
	H.mostrarcola();
	M.mostrarcola();
	
	cout << endl;
	comparacion(3, &H, &M);
	comparacion(10, &H, &M);
	comparacion(100, &H, &M);
	return 0;
}

