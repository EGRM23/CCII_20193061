#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Nodo.h"

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

using namespace std;

template <typename R> class Nodo;
template <typename R> class Lista {
public:
	Lista();
	~Lista();
	void insertarfinal(const R);
	void insertarcomienzo(const R);
	void insertarmedio(int,const R);
	void eliminarfinal();
	void eliminarcomienzo();
	void eliminarpos(int);
	void ordenar();
	void mostrarlista();
private:
	Nodo<R>* cabeza;
	Nodo<R>* cola;
	int cant;
};

template <typename R>
Lista<R> :: Lista() {
	cabeza = NULL;
	cola = NULL;
	cant = 0;
}

template <typename R>
Lista<R> :: ~Lista() {
	Nodo<R>* temp = cabeza;
	Nodo<R>* borrar;
	while(temp != NULL){
		borrar = temp;
		temp = temp->sig;
		delete borrar;
	}
	cabeza = NULL;
	cola = NULL;
}

template <typename R>
void Lista<R> :: insertarfinal(const R val) {
	Nodo<R>* nuevo = new Nodo<R>(val);
	
	if (cabeza == NULL)
		cabeza = nuevo;
	else
		cola->sig = nuevo;
	
	nuevo->sig = NULL;
	cola = nuevo;
	cant++;
}

template <typename R>
void Lista<R> :: insertarcomienzo(const R val) {
	Nodo<R>* nuevo = new Nodo<R>(val);
	
	if (cabeza == NULL) {
		cola = nuevo;
		nuevo->sig = NULL;
	} else {
		nuevo->sig = cabeza;
	}
	
	cabeza = nuevo;
	cant++;
}

template <typename R>
void Lista<R> :: insertarmedio(int pos, const R val) {
	Nodo<R>* nuevo = new Nodo<R>(val);
	Nodo<R>* temp = cabeza;
	pos--;
	
	if (cabeza == NULL) {
		nuevo->sig = cabeza;
		cabeza = nuevo;
	} else {
		while(pos != 1) {
			temp = temp->sig;
			pos--;
		}
		
		nuevo->sig = temp->sig;
		temp->sig = nuevo;
	}

	cant++;
}

template <typename R>
void Lista<R> :: eliminarfinal() {
	Nodo<R>* temp = cabeza;
	int cont = cant;
	
	if (cabeza->sig == NULL) {
		delete temp;
		cabeza = NULL;
		cola = NULL;
	} else {
		while (cont != 2) {
			temp = temp->sig;
			cont--;
		}
		delete temp->sig;
		temp->sig = NULL;
		cola = temp;
	}
	
	cant--;
}

template <typename R>
void Lista<R> :: eliminarcomienzo() {
	Nodo<R>* temp = cabeza;
	
	if (cabeza->sig == NULL) {
		cabeza = NULL;
		cola = NULL;
	} else
		cabeza = temp->sig;
	
	delete temp;
	cant--;
}

template <typename R>
void Lista<R> :: eliminarpos(int pos) {
	
	if (pos == 1)
		eliminarcomienzo();
	else if (pos == cant)
		eliminarfinal();
	else {
		Nodo<R>* temp = cabeza;
		Nodo<R>* borrar;
		pos--;
		
		while(pos != 1) {
			temp = temp->sig;
			pos--;
		}
		
		borrar = temp->sig;
		temp->sig = borrar->sig;
		
		delete borrar;		
		cant--;
	}
	
}

template <typename R>
void Lista<R> :: ordenar() {
	Nodo<R>* temp1 = cabeza;
	Nodo<R>* temp2 = cabeza->sig;
	
	while(temp2 != NULL){
		if((temp1->valor) > (temp2->valor)) {
			temp1->sig = temp2->sig;
			if (temp2->sig != NULL) {
				temp2->sig = temp1;
				
				if((temp1->sig != NULL) && ((temp1->valor) > ((temp1->sig)->valor))) {
					temp2->sig = temp1->sig;
				}
				if(temp1 == cabeza) {
					cabeza = temp2;
				}
			}
		} else {
			temp1 = temp2;
		}
		temp2 = temp1->sig;
	}
	
	cola = temp1;
}

template <typename R>
void Lista<R> :: mostrarlista() {
	cout << "LISTA: ";
	Nodo<R>* temp = cabeza;
	while (temp != NULL) {
		cout << temp->valor << " ";
		temp = temp->sig;
	}
	cout << endl;
}
#endif

