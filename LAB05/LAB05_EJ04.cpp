#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//4. Construya una lista enlazada que almacene tanto números como cadenas de
//	texto utilizando punteros void. Incluya una función de búsqueda de muestre
//	un dato almacenado además del tipo de dato que se encuentra almacenado
//	(int, float, char, …)

struct dato {
	void *d;
	dato *sig;
};

struct lista {
	dato *cabeza;
};

void insertar (void *v, lista *e) {
	dato *nuevo = new dato;
	nuevo->d = v;
	if (e->cabeza == NULL) {
		nuevo->sig = NULL;
		e->cabeza = nuevo;
	} else {
		nuevo->sig = e->cabeza;
		e->cabeza = nuevo;
	}
}

void imprimir (lista *e) {
	dato *temp = e->cabeza;
	
	while (temp != NULL) {
		cout << temp->d << " ";
		temp = temp->sig;
	}
	
	cout << endl;
}

void borrardatos (dato *ref) {
	if (ref != NULL) {
		borrardatos(ref->sig);
		delete ref;
	}
}

int main(int argc, char *argv[]) {
	lista *A = new lista;
	A->cabeza = NULL;
	
	insertar("dia", A);
	imprimir(A);
	
	borrardatos(A->cabeza);
	delete A;
	return 0;
}

