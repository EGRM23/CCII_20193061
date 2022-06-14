#ifndef NODO_H
#define NODO_H
#include <iostream>

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

using namespace std;

template <typename R> class Lista;
template <typename R> class Nodo {
public:
	Nodo(R val, Nodo* = NULL);
	~Nodo();
	friend class Lista<R>;
private:
	Nodo* sig;
	R valor;
};

template <typename R>
Nodo<R> :: Nodo(R val, Nodo* s) {
	valor = val;
	sig = s;
}

template <typename R>
Nodo<R> :: ~Nodo() {}
#endif

