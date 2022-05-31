#include<iostream>
#include "Ave.h"
#include "Ganso.h"
#include "Pato.h"
#include "Gallina.h"
using namespace std;

int main (int argc, char *argv[]) {
	Ganso a1("Armando");
	a1.mostrardat();
	
	Pato a2("Donald");
	a2.mostrardat();
	
	Gallina a3("Bessy");
	a3.mostrardat();
	return 0;
}

