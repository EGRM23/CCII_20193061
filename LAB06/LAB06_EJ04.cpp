#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//4. Implemente una aplicación con clases donde una clase contiene un arreglo en el que
//	se pueden almacenar como máximo 5 datos. Debe tener un nuevo dato para
//	almacenarlo, debe existir un método que verifique que el arreglo tenga espacio
//	disponible para guardar el dato. En caso contrario se debe mostrar un mensaje
//	indicando que el arreglo está lleno. Asimismo, debe tener un método para retirar un
//	dato del arreglo, este método debe verificar que, si haya algo para sacar del arreglo,
//	es decir que el arreglo no vaya a estar vacío, en cuyo caso debe desplegar un mensaje
//	diciendo que no hay nada para sacar de arreglo.

class datos {
private:
	int arr[5] = {};
	int tam;
public:
	datos();
	~datos();
	void insertar();
	void eliminar();
	void imprimirdat();
	void menu();
};

datos :: datos() {
	tam = 0;
}

datos :: ~datos() {}

void datos :: insertar() {
	if (tam == 5)
		cout << "\nERROR! El arreglo está lleno, no se pueden ingresar más datos\n";
	else {
		cout << "Numero a insertar: ";
		cin >> arr[tam];
		tam++;
	}
}

void datos :: eliminar() {
	if (tam == 0)
		cout << "\nERROR! El arreglo está vacio, no hay dato a eliminar\n";
	else {
		int p;
		do {
			cout << "Posicion del numero que quiere eliminar: ";
			cin >> p;
			if (p > tam || p < 1)
				cout << "ERROR! La posicion indicada está fuera del rango del arreglo\n";
		} while(p > tam || p < 1);
		
		for (int i = p-1; i < tam; i++) {
			if (i == tam-1)
				arr[i] = 0;
			else 
				arr[i] = arr[i+1];
		}

		tam--;
	}
}

void datos :: imprimirdat() {
	cout << "Datos = [ ";
	for (int i = 0; i < tam; i++)
		cout << arr[i] << " ";
	cout << "]\n";
}

void datos :: menu() {
	int op = 0;
	imprimirdat();
	cout << endl;
	
	do {
		do {
			cout << "Operaciones\n";
			cout << "1. Insertar dato\n";
			cout << "2. Eliminar dato\n";
			cout << "3. Salir\n";
			cout << "Numero de operacion: ";
			cin >> op;
			
			if (op != 1 && op != 2 && op != 3)
				cout << "ERROR! Ingrese un numero de operacion valido\n" << endl;
		} while(op != 1 && op != 2 && op != 3);
		
		if (op == 3) {
			cout << "\n	Gracias por confiar en nosotros!";
			break;
		}
		
		switch (op) {
			case 1:
				insertar();
				cout << endl;
				break;
			case 2:
				eliminar();
				cout << endl;
				break;
		}
		
		imprimirdat();
	} while (true);
}

int main(int argc, char *argv[]) {
	datos d;
	d.menu();
	
	return 0;
}

