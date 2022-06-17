#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Item.h"
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

template <typename R> class Item;
template <typename R> class Stack {
public:
	Stack(char);
	~Stack();
	void push(const R val);
	void pop();
	R& top();
	bool find(const R val);
	void mostrarpila();
private:
	Item<R>* cima;
	int cant;
	char nom;
};

template <typename R>
Stack<R> :: Stack(char n) {
	cima = NULL;
	cant = 0;
	nom = n;
}

template <typename R>
Stack<R> :: ~Stack() {
	Item<R> *temp = cima;
	Item<R> *borrar;
	while(temp!=NULL){
		borrar = temp;
		temp = temp->debajo;
		delete borrar;
	}
}

template <typename R>
void Stack<R> :: push(const R val) {
	Item<R>* nuevo = new Item<R>(val);
	
	if (cima == NULL)
		nuevo->debajo = NULL;
	else
		nuevo->debajo = cima;
	
	cima = nuevo;
	cant++;
}

template <typename R>
void Stack<R> :: pop() {
	Item<R>* temp = cima; 
	cima = cima->debajo;
	delete temp;
}

template <typename R>
R& Stack<R> :: top() {
	return cima->valor;
}

template <typename R>
bool Stack<R> :: find(const R val) {
	Item<R>* temp = cima;
	
	while(temp!=NULL){
		if (temp->valor == val)
			return true;
		else
			temp = temp->debajo;
	}
	
	return false;
}

template <typename R>
void Stack<R> :: mostrarpila() {
	cout << "\nPILA " << nom << ": \n";
	Item<R>* temp = cima;
	while (temp != NULL) {
		cout << temp->valor << endl;
		temp = temp->debajo;
	}
}
	
#endif

