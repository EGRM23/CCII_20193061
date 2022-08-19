#include <iostream>
using namespace std;

//Creamos la función suma
class suma {
public:
	//Recargamos el operador ( ) para que reciba 2 enteros
	//y devuelva un entero
	int operator()(int s1, int s2) {
		//Retornamos la suma de los valores
		return s1 + s2;
	}
};

int main() {
	//Creamos las variables
	int v1 = 10, v2 = 15;
	
	//Creamos el objeto de tipo suma que usaremos
	suma sum_var;
	
	//Usamos el operador ( ) sobrecargado de la función
	cout << sum_var(v1,v2);
	return 0;
}

