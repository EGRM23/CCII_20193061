#include <iostream>
#include <string.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//2. Se conoce de un alumno de la Universidad Nacional de San Agustín: CUI, nombre
//	completo y tres notas parciales (nota1, nota2, nota3). El programa con clases debe
//	imprimir: CUI, el primer nombre, el promedio de las tres notas e indique con un
//	mensaje si el alumno aprobó (nota final >= 10.5) o no aprobó (nota final < 10.5) la
//	asignatura de Ciencias de la Computación II.

class Alumno {
private:
	string CUI;
	string nombres;
	string apellidos;
	string curso;
	int *notas;
	int cantnot;
public:
	Alumno(string, string, string, string, int*, int);
	~Alumno();
	float notafin();
	bool aprobacion();
	void imprimirdat();
};

Alumno :: Alumno(string cod, string n, string a, string c, int *notes, int tam) {
	CUI = cod;
	nombres = n;
	apellidos = a;
	curso = c;
	notas = notes;
	cantnot = tam;
}

Alumno :: ~Alumno() {}

float Alumno :: notafin() {
	int promedio = 0;
	for (int i = 0; i < cantnot; i++)
		promedio += notas[i];
	
	return (float) promedio / 3;
}

bool Alumno :: aprobacion() {
	if (notafin() >= 10.5)
		return true;
	else
		return false;
}

void Alumno :: imprimirdat () {
	cout << "DATOS DEL ESTUDIANTE\n" << endl;
	cout << "CUI: " << CUI << endl;
	cout << "NOMBRE: ";
	
	for (char letra : nombres) {
		if (letra == ' ') {
			cout << endl;
			break;
		} else
			cout << letra;
	}
	
	cout << "CURSO: " << curso << endl;
	cout << "NOTA FINAL: " <<  notafin() << endl;
	cout << "ESTADO: ";
	if (aprobacion() == true)
		cout << "APROBADO";
	else
		cout << "DESAPROBADO";
}

int main(int argc, char *argv[]) {
	int notas[] = {10,15,3,4,5};
	int tam = sizeof(notas) / sizeof(notas[0]);
	Alumno est_1 = Alumno("20193061", "Eduardo German", "Ruiz Mamani", "Ciencias de la Computación II", notas, tam);
	
	est_1.imprimirdat();
	return 0;
}

