#include <iostream>
using namespace std;

//EDUAROD GERMAN RUIZ MAMANI
//20193061

class producto {
private:
	string codigo;
	string nombre;
	float precio;
	int stock;
	bool estado;
public:
	producto(string cod, string nom, float pr, int stc, bool est) {
		codigo = cod;
		nombre = nom;
		precio = pr;
		stock = stc;
		estado = est;
	}
	
	inline string getCodigo(){return codigo;}
	inline string getNombre(){return nombre;}
	inline bool getEstado(){return estado;}
	
	void setEstado() {
		estado = false;
	}
	
	void imprimir () {
		cout << "Código: " << codigo;
		cout << " Nombre: " << nombre;
		cout << " Precio: S/." << precio;
		cout << " Stock: " << stock << endl;
	}
};

void darAlta(producto** inventario, int &proddisp, int &prodexist) {
	string nom;
	float pre;
	int st;
	cout << "Nombre: ";
	cin >> nom;
	cout << "Precio: S/.";
	cin >> pre;
	cout << "Stock: ";
	cin >> st;
	inventario[prodexist] = new producto("cor22su", nom, pre, st, true);
	proddisp++;
	prodexist++;
}

void darBaja(producto** inventario, int &proddisp) {
	int pos = 0;
	do {
		cout << "Posicion del prodicto a eliminar: ";
		cin >> pos;
		
		if (pos <= 0 || pos > proddisp) {
			cout << "ERROR! No existe producto disponible en la posicion indicada\n";
		}
	} while (pos <= 0 || pos > proddisp);
	
	inventario[pos-1]->setEstado();
	proddisp--;
}

void buscar(producto** inventario) {
	int bus;
	do {
		cout << "BUSCAR POR\n";
		cout << "1. Nombre\n";
		cout << "2. Código\n";
		cout << "Tipo de búsqueda: ";
		cin >> bus;
		
		if (bus != 1 && bus != 2) {
			cout << "ERROR! Ingrese un valor válido";
		}
	} while (bus != 1 && bus != 2);
	
	string n;
	int aux = 0;
	if (bus == 1) {
		cout << "Nombre: ";
		getline(cin >> ws,n);
		
		for(int i = 0; i < 15; i++) {
			if(inventario[i]->getNombre() == n && inventario[i]->getEstado() == true){
				inventario[i]->imprimir();
				aux = 1;
				break;
			}
		}

		if(aux == 0) {
			cout<<"No se encontro producto"<<endl;
		}
	} else {
		cout << "Código: ";
		getline(cin >> ws,n);
		
		for(int i = 0; i < 15; i++) {
			if(inventario[i]->getCodigo() == n && inventario[i]->getEstado() == true){
				inventario[i]->imprimir();
				aux = 1;
				break;
			}
		}
		
		if(aux == 0) {
			cout<<"No se encontro producto"<<endl;
		}
	}
	
}

void modificar() {
}

void menu(producto** inventario, int &proddisp, int &prodexist) {
	int op = 0;
	
	do {
		int pos = 0;
		cout << "INVENTARIO\n";
		for (int i = 0; i < proddisp; i++) {
			if (inventario[pos]->getEstado() == true) {
				cout << i+1 << ". ";
				inventario[pos]->imprimir();
			} else {
				i--;
			}
			pos++;
		}
		
		cout << "MENU\n";
		cout << "1. Dar de alta un producto nuevo\n";
		cout << "2. Dar de baja (sin stock)\n";
		cout << "3. Buscar producto\n";
		cout << "4. Modificar datos de producto\n";
		cout << "5. Salir\n";
		
		do {
			cout << "Operacion a realizar: ";
			cin >> op;
			
			if (op < 1 || op > 5) {
				cout << "ERROR! Ingrese una operacion válida\n";
			}
		} while (op < 1 || op > 5);
		
		switch (op) {
			case 1:
				darAlta(inventario, proddisp, prodexist);
				break;
			case 2:
				darBaja(inventario, proddisp);
				break;
			case 3:
				buscar(inventario);
				break;
			case 4:
				modificar();
				break;
		};
		
		cout << endl;
	} while (op != 5);
}

int main(int argc, char *argv[]) {
	producto** inventario = new producto*[15];
	inventario[0] = new producto("pan22su", "pantalon", 45.90, 16, true);
	inventario[1] = new producto("pol21su", "polo", 19.90, 13, true);
	inventario[2] = new producto("cam22su", "camisa", 24.90, 20, true);
	inventario[3] = new producto("pol22su", "polera", 39.90, 15, true);
	inventario[4] = new producto("cas21su", "casaca", 39.90, 13, true);
	inventario[5] = new producto("cha21su", "chalina", 14.90, 0, true);
	inventario[6] = new producto("med21ep", "medias", 6.90, 6, true);
	inventario[7] = new producto("pij22ec", "pijama", 19.90, 12, true);
	inventario[8] = new producto("zap22ep", "zapatos", 54.90, 11, true);
	inventario[9] = new producto("len22su", "lentes", 23.90, 5, true);
	
	int proddispon = 10, prodexist = 10;
	
	menu(inventario, proddispon, prodexist);
	
	for (int i = 0; i < prodexist; i++) {
		delete inventario[i];
	}
	
	delete [] inventario;
	return 0;
}

