#ifndef AVE_H
#define AVE_H
#include <iostream>
using namespace std;

class Ave {
public:
	Ave(string);
	~Ave();
	bool getvolar() {return volar;}
	string getNombre() {return nombre;}
	string getTipo() {return tipo;}
	void mostrardat();
protected:
	string nombre;
	string tipo;
	int patas = 2;
	bool volar;
};

#endif

