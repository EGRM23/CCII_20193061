#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//1. Implemente un programa con clases que calcule el área de un rectángulo y
//   perímetro.

class Rectangulo {
private:
	int an;
	int alt;
public:
	Rectangulo (int, int);
	~Rectangulo();
	int area();
	int perimetro();
	void imprimirdat();
};

Rectangulo :: Rectangulo(int ancho, int altura) {
	an = ancho;
	alt = altura;
}

Rectangulo :: ~Rectangulo() {}

int Rectangulo :: area() {
	return an*alt;
}

int Rectangulo :: perimetro() {
	return 2 * (an + alt);
}

void Rectangulo :: imprimirdat() {
	cout << "Ancho: " << an << endl;
	cout << "Altura: " << alt << endl;
}
int main(int argc, char *argv[]) {
	Rectangulo r = Rectangulo(4, 5);
	r.imprimirdat();
	
	cout << endl;
	cout << "AREA: " << r.area() << endl;
	cout << "PERIMETRO: " << r.perimetro() << endl;
	return 0;
}

