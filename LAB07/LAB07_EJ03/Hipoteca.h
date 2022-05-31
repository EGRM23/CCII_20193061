#ifndef HIPOTECA_H
#define HIPOTECA_H
#include "Prestamo.h"

class Hipoteca : public Prestamo{
public:
	Hipoteca(string,double,int);
	~Hipoteca();
	void imprimir();
};

#endif

