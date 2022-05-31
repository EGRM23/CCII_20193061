#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
// 20193061

class Multimedia {
protected:
	string tipo;
	string codigo;
	int cantidad;
public:
	Multimedia(string t, string c, int cant) {
		tipo = t;
		codigo = c;
		cantidad = cant;
	}
	
	~Multimedia() {}
	
	void mostrarM() {
		cout << "MULTIMEDIA:\n";
		cout << "Tipo: " << tipo << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Cantidad: " << cantidad << endl;
	}
};

class Disco : public Multimedia{
protected:
	string modelo;
public:
	Disco(string t, string c, int cant, string m) : Multimedia(t,c,cant) {
		modelo = m;
	}
	
	~Disco() {}
	
	void mostrarD() {
		cout << "DISCO:\n";
		cout << "Modelo: " << modelo << endl;
		cout << "CARACTERISTICAS ";
		mostrarM();
	}
};

int main(int argc, char *argv[]) {
	Disco d1("Portable","edu4ger56",23,"WW");
	d1.mostrarD();
	return 0;
}

