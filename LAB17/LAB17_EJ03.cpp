#include <iostream>

template <class T>
class Contenedor {
	T elemento;
	public :
	Contenedor (T arg ) {
		elemento = arg;
	}
	T add() { return ++elemento; }
};
//La clase contenedor recibe un valor de tipo T y lo guarda en su
//atributo elemento, por otro lado el método add aumenta el valor
//de elemento en 1 unidad

template <>
class Contenedor<char> {
	char elemento;
	public :
	Contenedor ( char arg ) {
		elemento = arg ;
	}
	char uppercase() {
	if ((elemento >= 'a') && (elemento <= 'z')) {
		elemento += 'A'-'a'; }
	return elemento ;
	}
};
//Esta parte implementa la clase en caso de que la clase Contenedor
//se cree con tipo char, ahí también recibe el valor y lo guarda en
//elemento, la diferencia es que ahora no existe la función add, 
//existe una función que vuelve a mayúscula la variable elemento

int main() {
	Contenedor<int> cint (5);
	Contenedor<char> cchar('t');
	std::cout << cint.add() << std::endl;
	std::cout << cchar.uppercase() << std::endl;
	//El código si funciona
	return 0;
}

