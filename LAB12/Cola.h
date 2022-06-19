#ifndef COLA_H
#define COLA_H
#include <iostream>
#include "Item.h"
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

template <typename R> class Item;
template <typename R> class Cola {
public:
	Cola(string);
	~Cola();
	void ingreso(const R val);
	void salida();
	R& primero();
	string getnombre() {return nom;}
	bool find(const R val);
	void mostrarcola();
private:
	Item<R>* thefirst;
	Item<R>* thelast;
	int cant;
	string nom;
};

template <typename R>
Cola<R> :: Cola(string n) {
	thefirst = NULL;
	thelast = NULL;
	cant = 0;
	nom = n;
}

template <typename R>
Cola<R> :: ~Cola() {
	Item<R> *temp = thefirst;
	Item<R> *borrar;
	while(temp!=NULL){
		borrar = temp;
		temp = temp->detras;
		delete borrar;
	}
}

template <typename R>
void Cola<R> :: ingreso(const R val) {
	Item<R>* nuevo = new Item<R>(val);
	
	if (thefirst == NULL) {
		nuevo->detras = NULL;
		thefirst = nuevo;
	} else
		thelast->detras = nuevo;
	
	thelast = nuevo;
	cant++;
}

template <typename R>
void Cola<R> :: salida() {
	Item<R>* temp = thefirst;
	
	if (thefirst->detras == NULL)
		thelast = NULL;
	
	thefirst = thefirst->detras;
	delete temp;
	cant--;
}

template <typename R>
R& Cola<R> :: primero() {
	return thefirst->valor;
}

template <typename R>
bool Cola<R> :: find(const R val) {
	Item<R>* temp = thefirst;
	
	while(temp != NULL){
		if (temp->valor == val)
			return true;
		else
			temp = temp->detras;
	}
	
	return false;
}

template <typename R>
void Cola<R> :: mostrarcola() {
	cout << "\nCOLA " << nom << ": \n";
	Item<R>* temp = thefirst;
	while (temp != NULL) {
		cout << temp->valor << endl;
		temp = temp->detras;
	}
}

#endif

