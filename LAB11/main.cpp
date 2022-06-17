#include<iostream>
#include "Item.h"
#include "Stack.h"
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI: 20193061

template <typename R>
void Hanoi (int n, Stack<R>* origen, Stack<R>* aux, Stack<R>* destino) {
	int disco;
	if (n == 1) {
		disco = origen->top();
		origen->pop();
		destino->push(disco);
		
		origen->mostrarpila();
		aux->mostrarpila();
		destino->mostrarpila();
		cout << "--------------------------------";
	} else {
		Hanoi<R>(n-1, origen, destino, aux);
		
		disco = origen->top();
		origen->pop();
		destino->push(disco);
		
		origen->mostrarpila();
		aux->mostrarpila();
		destino->mostrarpila();
		cout << "--------------------------------";
		
		Hanoi<R>(n-1, aux, origen, destino);
	}
}

int main (int argc, char *argv[]) {
	
	Stack<int> p1('1');
	
	p1.push(3);
	p1.push(5);
	p1.push(7);
	p1.mostrarpila();
	
	p1.pop();
	p1.mostrarpila();
	
	p1.push(9);
	p1.mostrarpila();
	
	int n = 5;
	
	cout << "\nBuscando " << n << "...\n";
	if (p1.find(n) == true)
		cout << "Elemento encontrado\n";
	else
		cout << "No se encuentra en la pila\n";
	
	n = 11;
	cout << "Buscando " << n << "...\n";
	if (p1.find(n) == true)
		cout << "Elemento encontrado\n";
	else
		cout << "No se encuentra en la pila\n";
	
	cout << "---------------------------------------------------------------";
	
	cout << endl << "\nPROBLEMA HANOI\n";
	
	Stack<int> A('A');
	Stack<int> B('B');
	Stack<int> C('C');
	
	int cantdisc;
	
	cout << "Ingrese la cantidad de discos: ";
	cin >> cantdisc;
	
	for (int i = cantdisc; i > 0; i--) {
		A.push(i);
	}
	
	A.mostrarpila();
	B.mostrarpila();
	C.mostrarpila();
	cout << "--------------------------------";
	
	Hanoi<int>(cantdisc, &A, &B, &C);
	
	return 0;
}

