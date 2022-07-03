#include <iostream>
using namespace std;

class persona {
private:
	string nombre;
	int edad;
public:
	persona() {}
	persona(string n, int e) {
		nombre = n;
		edad = e;
	}
	void operator=(persona &p2) {
		nombre = p2.nombre;
		edad = p2.edad;
	}
	bool operator>=(persona &p2) {return edad>=p2.edad;}
	bool operator<=(persona &p2) {return edad<=p2.edad;}
	void imprimir() {
		cout << nombre << " Edad: " << edad << endl;
	}
};

template <typename R>
R ubicar(R lista[], bool(*criterio)(R,R) , int ini, int fin) {
	while (ini < fin) {
		while (criterio(lista[fin], lista[ini]) && ini < fin)
			fin--;
		
		swap(lista[fin],lista[ini]);
		
		while (criterio(lista[fin], lista[ini]) && ini < fin)
			ini++;
		
		swap(lista[ini],lista[fin]);
	}
	return ini;
}

template <typename R>
void quickSort(R lista[], bool(*criterio)(R,R), int ini, int fin) {
	int u;
	if (ini < fin) {
		u = ubicar(lista, criterio, ini, fin);
		quickSort(lista, criterio, ini, u - 1);
		quickSort(lista, criterio, u + 1, fin);
	}
}

template <typename R>
void mezcla(R lista[], bool(*criterio)(R,R), int ini, int med, int fin) {
	
	//Creamos una lista auxiliar para almacenar ahí la lista ordenada
	R* listaAux = NULL;
	listaAux = new R[fin-ini+1];
	
	int izq, der, ia;
	izq = ini;
	der = med+1;
	ia = 0;
	
	//Empezamos a comparar los numeros extremos de ambas mitades
	while (izq <= med && der <= fin) {
		if (criterio(lista[der], lista[izq])) {
			listaAux[ia] = lista[izq];
			izq++;
		} else {
			listaAux[ia] = lista[der];
			der++;
		}
		ia++;
	}
	
	for (int i = izq ; i <= med ; i++) {
		listaAux[ia]=lista[i];
		ia++;
	}
	
	for (int i = der ; i <= fin ; i++) {
		listaAux[ia]=lista[i];
		ia++;
	}
	
	for (int i = 0 ; i < ia ; i++)
		lista[ini+i]=listaAux[i];
	
	listaAux = NULL;
	delete [] listaAux;
}

template <typename R>
void mergeSort(R lista[], bool(*criterio)(R,R), int ini, int fin) {
	if (ini < fin) {
		int med = (ini+fin) / 2;
		mergeSort(lista, criterio, ini, med);
		mergeSort(lista, criterio, med + 1, fin);
		mezcla(lista, criterio, ini, med, fin);
	}
}

template <typename R>
void insertSort(R lista[], bool(*criterio)(R,R),  int tam, int aux = 0) {
	R actual;
	int j;
	for(int i = 1 ; i < tam ; i++) {
		actual = lista[i];
		
		j = i-1;
		
		while (j >= 0 && criterio(lista[j], actual)) {
			lista[j+1] = lista[j];
			j--;
		}
		
		lista[j+1] = actual ;
	}
}

template <typename R>
void printLista(R lista[], const int tam) {
	for (int i = 0; i < tam; i++)
		cout << lista[i] << " ";
	cout << endl << endl;
}

template <typename R>
bool ascendente(R v1, R v2) {
	if (v1 >= v2)
		return true;
	else
		return false;
}

template <typename R>
bool descendente(R v1, R v2) {
	if (v1 <= v2)
		return true;
	else
		return false;
}

template <typename R>
void duplicar(R arr1[], R arr2[], int tam) {
	for (int i = 0; i < tam; i++)
		arr2[i] = arr1[i];
}

int main(int argc, char *argv[]) {
	int tam;
	
	int listaint[] = {1,10,3,8,5,6,7,4,9,2};
	tam = sizeof(listaint) / sizeof(listaint[0]);
	cout << "Lista de ejemplo: \n";
	printLista<int>(listaint, tam);
	int auxint[10];
	
	duplicar(listaint, auxint, tam);
	quickSort<int>(auxint, ascendente, 0, tam-1);
	cout << "Lista ordenada: \n";
	printLista<int>(auxint, tam);
	
	duplicar(listaint, auxint, tam);
	quickSort<int>(auxint, descendente, 0, tam-1);
	cout << "Lista ordenada: \n";
	printLista<int>(auxint, tam);
	
	char listachar[] = {'a','j','c','h','e','f','g','d','i','b'};
	tam = sizeof(listachar) / sizeof(listachar[0]);
	cout << "Lista de ejemplo: \n";
	printLista<char>(listachar, tam);
	char auxchar[10];
	
	duplicar(listachar, auxchar, tam);
	mergeSort<char>(auxchar, ascendente, 0, tam-1);
	cout << "Lista ordenada: \n";
	printLista<char>(auxchar, tam);
	
	duplicar(listachar, auxchar, tam);
	mergeSort<char>(auxchar, descendente, 0, tam-1);
	cout << "Lista ordenada: \n";
	printLista<char>(auxchar, tam);
	
	persona listapersona[] = {persona("Juan", 20),persona("Carlos", 14),
		persona("Sofia", 25),persona("Sandro", 19),persona("Jeronimo", 22)};
	tam = 5;
	cout << "Lista de ejemplo: \n";
	for (int i = 0; i < 5; i++) {
		listapersona[i].imprimir();
	}
	persona auxpersona[] = {persona("Juan", 20),persona("Carlos", 14),
		persona("Sofia", 25),persona("Sandro", 19),persona("Jeronimo", 22)};
	
	cout << endl;
	
	insertSort<persona>(listapersona, ascendente, tam);
	cout << "Lista ordenada: \n";
	for (int i = 0; i < 5; i++) {
		listapersona[i].imprimir();
	}
	
	cout << endl;
	
	insertSort<persona>(auxpersona, descendente, tam);
	cout << "Lista ordenada: \n";
	for (int i = 0; i < 5; i++) {
		auxpersona[i].imprimir();
	}

	return 0;
}

