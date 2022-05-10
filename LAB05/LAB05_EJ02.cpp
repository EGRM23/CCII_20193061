#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//2. Cree dos vectores con valores flotantes y asígnele valores aleatorios, para esto
//	deberá de asignar memoria a cada vector. Calcule el producto punto de vectores y
//	muestre por pantalla. Una vez finalizado este proceso, retire la memoria asignada a
//	los punteros. Repita este proceso de asignación y retiro de memoria dentro de un for
//	de 1 000 000 veces.

void imprimir (float *v, int tam) {
	for (int i = 0; i < tam; i++)
		cout << v[i] << " ";
}

int main(int argc, char *argv[]) {
	
	float n = 1000000, prod;
	int tam = 3;
	int lim_inf = -5, lim_sup = 5;
	srand(time(NULL));
	
	float* v1;
	float* v2;
	v1 = new float [tam];
	v2 = new float [tam];
	
	for (int i = 0; i < n; i++) {
		
		cout << i+1 << endl;
		prod = 0;
		
		for (int j = 0; j < tam; j++) {
			v1[j] = lim_inf + rand()%(lim_sup+1-lim_inf);
			v2[j] = lim_inf + rand()%(lim_sup+1-lim_inf);
			prod = prod + v1[j]*v2[j];
		}
	 	
		cout << "v1 = [ ";
		imprimir(v1, tam);
		cout << "]" << endl;
		cout << "v2 = [ ";
		imprimir(v2, tam);
		cout << "]" << endl;
		
		cout << "Producto punto: " << prod;
		cout << endl;
		cout << endl;
	}
	
	
	delete[] v1;
	delete[] v2;
	return 0;
}

