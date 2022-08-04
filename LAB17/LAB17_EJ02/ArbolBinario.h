#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "Nodo.h"

#include<iostream>
using namespace std;

template <typename R> class ArbolBinario {
public:
	ArbolBinario() {
		raiz = nullptr;
		cantnodos = 0;
	}
	~ArbolBinario();
	void insertar(R const);
	void imprimir();
private:
	void ubicar(R, Nodo<R>*);
	void infoxnodo(Nodo<R>*);
	void eliminar(Nodo<R>*); 
	Nodo<R> *raiz;
	int cantnodos;
};

template <typename R>
ArbolBinario<R> :: ~ArbolBinario() {
	if (raiz != nullptr)
		eliminar(raiz);
}

template <typename R>
void ArbolBinario<R> :: eliminar(Nodo<R>* temp) {
	if (temp->izq != nullptr) { eliminar(temp->izq); }
	if (temp->der != nullptr) { eliminar(temp->der); }
	delete temp;
}

template <typename R>
void ArbolBinario<R> :: insertar(const R v) {
	if (raiz == nullptr) {
		Nodo<R>* nuevo = new Nodo<R>(v, cantnodos);
		raiz = nuevo;
		cantnodos++;
	} else {
		ubicar(v,raiz);
	}
}

template <typename R>
void ArbolBinario<R> :: ubicar(const R v, Nodo<R>* temp) {
	if ((temp->valor) < v) {
		if (temp->der == nullptr) {
			Nodo<R>* nuevo = new Nodo<R>(v, cantnodos);
			temp->der = nuevo;
			cantnodos++;
		} else  {
			ubicar(v,temp->der);
		}
	} else {
		if (temp->izq == nullptr) {
			Nodo<R>* nuevo = new Nodo<R>(v, cantnodos);
			temp->izq = nuevo;
			cantnodos++;
		} else  {
			ubicar(v,temp->izq);
		}
	}
}

template <typename R>
void ArbolBinario<R> :: imprimir() {
	if (raiz != nullptr) {
		cout << "Para visualizar, pegar la estructura generada en este link:\n";
		cout << "https://dreampuf.github.io/GraphvizOnline/";
		cout << endl << endl;
		
		cout << "digraph ArbolBinario_" << cantnodos << " {\n";
		cout << "\tn0_" << raiz->valor << ";\n";
		infoxnodo(raiz);
		cout << "}\n";
	}
}

template <typename R>
void ArbolBinario<R> :: infoxnodo(Nodo<R>* temp) {
	if (temp->izq != nullptr) {
		cout << "\tn" << temp->orden << "_" << temp->valor << " -> ";
		cout << "n" << temp->izq->orden << "_" << temp->izq->valor << ";\n";
		infoxnodo(temp->izq);
	} else {
		cout << "\tn" << temp->orden << "_" << temp->valor;
		cout << " -> n" << temp->orden << "_nullizq;\n";
	}
	if (temp->der != nullptr) {
		cout << "\tn" << temp->orden << "_" << temp->valor << " -> ";
		cout << "n" << temp->der->orden << "_" << temp->der->valor << ";\n";
		infoxnodo(temp->der);
	} else {
		cout << "\tn" << temp->orden << "_" << temp->valor;
		cout << " -> n" << temp->orden << "_nullder;\n";
	}
}
#endif

