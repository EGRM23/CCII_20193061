#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//5. Implementar un programa con clases que haga la búsqueda de un dato almacenado en
//	una matriz de 3x3 que tiene los números de 1 al 9 ingresados aleatoriamente y debe
//	indicar la posición donde se encuentra el dato.


class matriz {
private:
	int **m;
	int f;
	int c;
public:
	matriz(int,int);
	~matriz();
	void llenaraleatorio();
	void buscar();
	void imprimir();
};

matriz :: matriz(int filas, int columnas) {
	f = filas;
	c = columnas;
	
	m = new int *[f];
	for (int i = 0; i < f; i++)
		m[i] = new int[c] {};
	
	llenaraleatorio();
}

matriz :: ~matriz() {
	for (int i = 0; i < f; i++)
		delete m[i];
	
	delete m;
}

void matriz :: llenaraleatorio() {
	int tam = f * c;
	int *dat = new int[tam];
	srand(time(NULL));
	
	for (int i = 0; i < tam; i++)
		dat[i] = i+1;
	
	int p;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			p = rand()%(tam);
			m[i][j] = dat[p];
			
			for (int k = p; k < tam-1; k++)
				dat[k] = dat[k+1];
			
			dat[tam-1] = 0;
			tam--;
		}
	}
	
	delete dat;
}

void matriz :: buscar() {
	int d = 0;
	
	do {
		cout << "Dato a buscar: ";
		cin >> d;
		
		if (d < 1 || d > 9)
			cout << "ERROR! Dato no encontrado\n";
	} while(d < 1 || d > 9);
	
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (d == m[i][j]) {
				cout << "Posicion: Fila " << i+1 << " - Columna " << j+1;
				d = 0;
				break;
			}
		}
		if (d == 0)
			break;
	}
}

void matriz :: imprimir() {
	cout << "MATRIZ\n";
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	matriz m_1(3,3);
	m_1.imprimir();
	m_1.buscar();
	
	m_1.~matriz();
	return 0;
}

