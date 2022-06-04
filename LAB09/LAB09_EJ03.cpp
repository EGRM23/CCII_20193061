#include <iostream>

using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

template <typename C, typename S>
void corinst (const C nom, const S apellido) {
	string correo = "@unsa.edu.pe";
	correo = nom + apellido + correo;
	cout << "Correo Institucional: " << correo;
}

int main(int argc, char *argv[]) {
	corinst<char,string> ('e',"ruiz");
	return 0;
}

