#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
// 20193061

class operacionBase {
private:
	int operador;
public:
	void setOperador(int op) {
		operador = op;
	}
	
	int getOperador() {return operador;}
};

class operacionFactorial : public operacionBase {
private:
	int operador;
public:
	void setOperador(int op) {operacionBase :: setOperador(op);}
	
	int getOperador() {return operacionBase :: getOperador();}
	
	int devolverFactorial() {
		int n = getOperador();
		
		for (int i = n-1; i > 0; i--)
			n *= i;
		
		return n;
	}
};
int main(int argc, char *argv[]) {
	operacionFactorial of1;
	of1.setOperador(5);
	cout << "Operador: " << of1.getOperador() << endl;
	cout << "Factorial: " << of1.devolverFactorial();
	return 0;
}

