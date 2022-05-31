#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
// 20193061

class Color {
protected:
	int R;
	int G;
	int B;
public:
	Color() {
		R = 0;
		G = 0;
		B = 0; 
	}
	Color(int r, int g, int b) {
		R = r;
		G = g;
		B = b;
	}
	~Color() {}
	void mostrarColor() {
		cout << "RGB(" << R << "," << G << "," << B << ")";
	}
};

class Material {
protected:
	string mtrl;
public:
	Material(string m) {
		mtrl = m;
	}
	~Material() {}
};

class Objeto : public Color, public Material {
public:
	Objeto(int r, int g, int b, string m) : Color(r,g,b), Material(m) {}
	~Objeto() {}
	void descripcion() {
		cout << " Objeto de color ";
		mostrarColor();
		cout << " y material de " << mtrl << ".";
	}
};
int main(int argc, char *argv[]) {
	Objeto o1(4,5,6,"metal");
	o1.descripcion();
	return 0;
}

