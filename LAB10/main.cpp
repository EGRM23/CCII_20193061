#include<iostream>
#include "Nodo.h"
#include "Lista.h"

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

using namespace std;

int main (int argc, char *argv[]) {
	Lista<int> l1;
	
	l1.insertarfinal(3);
	l1.mostrarlista();
	
	l1.insertarfinal(4);
	l1.insertarfinal(5);
	l1.mostrarlista();
	
	l1.insertarcomienzo(7);
	l1.insertarcomienzo(8);
	l1.mostrarlista();
	
	l1.insertarmedio(2,6);
	l1.mostrarlista();
	
	l1.eliminarfinal();
	l1.mostrarlista();
	
	l1.eliminarcomienzo();
	l1.mostrarlista();
	
	l1.eliminarpos(3);
	l1.mostrarlista();
	
	l1.ordenar();
	l1.mostrarlista();
	
	l1.~Lista();
	return 0;
}

