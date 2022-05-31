#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
// 20193061

class Persona {
protected:
	int edad;
	string nombre;
public:
	Persona(int e, string n) {
		edad = e;
		nombre = n;
	}
	~Persona() {};
	void setedad(int e) {
		edad = e;
	}
	void setnombre(string n) {
		nombre = n;
	}
	void imprimir() {
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
	}
};

class Alumno : public Persona {
public:
	Alumno(int e, string n) : Persona(e,n) {};
	~Alumno() {};
};

int main(int argc, char *argv[]) {
	Alumno a(12,"Jose");
	a.imprimir();
	a.setedad(15);
	a.setnombre("Chayanne");
	a.imprimir();
	return 0;
}

