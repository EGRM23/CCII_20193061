#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//6. Utilizando punteros a funciones, implemente las funciones:
//	a. void sumar (int a, int b);
//	b. void restar (int a, int b);
//	c. void multiplicar (int a, int b);
//	d. void dividir (int a, int b);
//	Cree un vector de punteros a funciones e implemente un programa que permita
//	la invocación de cada función, pero a través del puntero

void resul(void(*func)(int,int), int a, int b){
	(*func)(a,b);
}

void sumar (int a, int b){
	cout << "SUMA: " << a+b << endl;
}
	
void restar (int a, int b){
	cout << "RESTA: " << a-b << endl;
}

void multiplicar (int a, int b){
	cout << "MULTIPLICACION: " << a*b << endl;
}

void dividir (int a, int b){
	cout << "DIVISION: " << (float)a/(float)b << endl;
}

int main(int argc, char *argv[]) {
	int  a, b;
	cout << "Introduzca A: ";
	cin >> a;
	cout << "Introduzca B: ";
	cin >> b;
	
	cout<<"\nResultados:\n";
	resul(sumar, a, b);
	resul(restar, a, b);
	resul(multiplicar, a, b);
	resul(dividir, a, b);
	
	return 0;
}

