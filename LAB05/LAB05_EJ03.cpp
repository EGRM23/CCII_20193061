#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//3. Construya una lista enlazada simple utilizando solo punteros. Añada las funciones
//	de insertar y eliminar un elemento. En la función insertar se debe asegurar que los
//	números insertados estén en orden creciente. Simule el proceso con 10000 números
//	aleatorios sin que el programa falle.

struct casilla {
	int num;
	casilla *sig;
};

struct lista {
	casilla *cabeza;
};

void insertaraleatorio (int v, lista *e) {
	casilla *nuevo = new casilla;
	nuevo->num = v;
	if (e->cabeza == NULL) {
		nuevo->sig = NULL;
		e->cabeza = nuevo;
	} else {
		nuevo->sig = e->cabeza;
		e->cabeza = nuevo;
	}
}

void ordenar (lista *e, int tam) {
	casilla *temp1;
	casilla *temp2;
	int a = 0;
	
	while (tam != 1) {
		temp1 = e->cabeza;
		temp2 = (e->cabeza)->sig;
		
/*		cout << temp1->num << " " << temp2->num << endl;*/
		
		for (int i = 1; i < tam; i++) {
			if((temp1->num) > (temp2->num)){
				temp1->sig = temp2->sig;
				temp2->sig = temp1;
				
				if(temp1 == e->cabeza)
					e->cabeza = temp2;
				
				if((temp1->sig != NULL) && ((temp1->num) > ((temp1->sig)->num)))
				   temp2->sig = temp1->sig;
				
				a=1;
			} else {
				if((temp2->sig != NULL) && ((temp2->num) > ((temp2->sig)->num)))
					temp1->sig = temp2->sig;
				temp1 = temp2;
			}
			temp2 = temp1->sig;
		}
		
		if (a == 0)
			break;
		a=0;
		
		tam--;
	}
}


void imprimir (lista *e) {
	casilla *temp = e->cabeza;
	
	while (temp != NULL) {
		cout << temp->num << " ";
		temp = temp->sig;
	}
	
	cout << endl;
}

void insertarelem (lista *e) {
	int v;
	
	cout << "LISTA ACTUAL:" << endl;
	imprimir(e);
	
	cout << "Numero a insertar: ";
	cin >> v;
	
	casilla *nuevo = new casilla;
	nuevo->num = v;
	
	if (e->cabeza == NULL) {
		nuevo->sig = NULL;
		e->cabeza = nuevo;
	} else if ((e->cabeza)->num >= nuevo->num) {
		nuevo->sig = e->cabeza;
		e->cabeza = nuevo;
	} else {
		casilla *temp1 = e->cabeza;
		casilla *temp2 = (e->cabeza)->sig;
		
		while (true)
			if ((nuevo->num) <= (temp2->num)) {
				nuevo->sig = temp2;
				temp1->sig = nuevo;
				break;
			} else if (temp2 == NULL) {
				nuevo->sig = NULL;
				temp1->sig = nuevo;
				break;
			} else {
				temp1 = temp2;
				temp2 = temp1->sig;
			}
	}
	
	cout << "LISTA ACTUALIZADA:" << endl;
	imprimir(e);
}

void eliminarelem (lista *e) {
	cout << "LISTA ACTUAL:" << endl;
	imprimir(e);
	
	int v;
	
	cout << "Numero a eliminar: ";
	cin >> v;
	
	casilla *temp1;
	casilla *temp2 = e->cabeza;
	
	while (true) {
		if (temp2 == NULL)
			cout << "El valor no se encuentra en la lista";
		else
			if (temp2->num == v) {
				if (temp2 == e->cabeza)
					e->cabeza = temp2->sig;
				else
					temp1->sig = temp2->sig;
				
				delete temp2;
				
				cout << "\nLISTA ACTUALIZADA:" << endl;
				imprimir(e);
				
				break;
			} else {
				temp1 = temp2;
				temp2 = temp1->sig;
			}
	}
}

void borrarcasillas (casilla *ref) {
	if (ref != NULL) {
		borrarcasillas(ref->sig);
		delete ref;
	}
}

int main(int argc, char *argv[]) {
	int tam, v, op;
	
	do {
		cout << "Tamaño de la lista: ";
		cin >> tam;
		
		if (tam < 0) {
			cout << "ERROR! Ingrese solo valores positivos\n" << endl;
		}
	} while (tam < 0);
	
	int lim_inf = 0, lim_sup = 100;
	srand(time(NULL));
	
	lista *A = new lista;
	A->cabeza = NULL;
	for (int i = 0; i < tam; i++) {
		v = lim_inf + rand()%(lim_sup+1-lim_inf);
		insertaraleatorio (v, A);
	}
	cout << "\nLISTA ALEATORIA GENERADA:" << endl;
	imprimir(A);
	
	ordenar(A,tam);
	
	cout << "LISTA ORDENADA:" << endl;
	imprimir(A);
	
	do {
		op = 0;
		do {
			cout << "\nOperaciones:\n";
			cout << "1. Insertar elemento\n";
			cout << "2. Eliminar elemento\n";
			cout << "3. Salir\n";
			cout << "Operacion? ";
			cin >> op;
			
			if (op != 1 && op != 2 && op != 3) {
				cout << "ERROR! Ingrese un numero de operacion valido\n" << endl;
			}
		} while (op != 1 && op != 2 && op != 3);
		
		if (op == 1)
			insertarelem(A);
		else if (op == 2)
			eliminarelem(A);
		else
			cout << "Gracias por confiar en nosotros!";
	} while (op != 3);
	
	borrarcasillas(A->cabeza);
	delete A;
	return 0;
}

