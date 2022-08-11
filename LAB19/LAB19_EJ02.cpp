#include <iostream>
#include <vector>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

class Buscar {
	vector<int> ref = {1,3,6,9,2,2,2,5,4,5,6,8,9,2,1,2,3,4,6,3,3,3,3,5,6,7};
public:
	vector<int> operator()(int ini, int fin, int v) {
		int cont = 0;
		vector<int> result = {};
		for (int i = ini; i <= fin; i++) {
			if (ref[i] == v) {
				cont++;
				result.push_back(i);
			}
		}
		return result;
	}
	void imprimir(vector<int> x) {
		cout << "[ ";
		for(int i = 0; i < (int)x.size(); i++) {
			cout << x[i] << " ";
		}
		cout << "]\n";
	}
	void mostrar() {
		cout << "v = ";
		imprimir(this->ref);
	}
};

int main(int argc, char *argv[]) {
	int posini = 0, posfin = 5, tb = 2;
	Buscar find1;
	vector<int> pos = find1(posini,posfin,tb);
	
	find1.mostrar();
	cout << "Posicion inicial: " << posini << endl;
	cout << "Posicion final: " << posfin << endl;
	cout << "Termino buscado: " << tb << endl;
	cout << "Coincidencias = ";
	find1.imprimir(pos);
	return 0;
}

