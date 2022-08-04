#ifndef NODO_H
#define NODO_H

template <typename R> class ArbolBinario;
template <typename R> class Nodo {
public:
	Nodo(R val, int ord, Nodo* i = nullptr, Nodo* d = nullptr) {
		valor = val;
		izq = i;
		der = d;
		orden = ord;
	}
	~Nodo() {}
	friend class ArbolBinario<R>;
private:
	Nodo* izq;
	Nodo* der;
	R valor;
	int orden;
};

#endif

