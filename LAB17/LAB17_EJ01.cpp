#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

template <typename R>
R suma(R n1, R n2) {
	return n1 + n2;
}

template <typename R>
R resta(R n1, R n2) {
	return n1 - n2;
}

template <typename R>
R multiplicacion(R n1, R n2) {
	return n1 * n2;
}

template <typename R>
R division(R n1, R n2) {
	return n1 / n2;
}


int main(int argc, char *argv[]) {
	int n1 = 20, n2 = 15;
	cout << "Para " << n1 << " y " << n2 << endl;
	cout << "Suma: " << suma<int>(n1,n2) << endl;
	cout << "Resta: " << resta<int>(n1,n2) << endl;
	cout << "Multiplicacion: " << multiplicacion<int>(n1,n2) << endl;
	cout << "Division: " << division<int>(n1,n2) << endl;
	cout << endl;
	
	float f1 = 17.6, f2 = 5.3;
	cout << "Para " << f1 << " y " << f2 << endl;
	cout << "Suma: " << suma<float>(f1,f2) << endl;
	cout << "Resta: " << resta<float>(f1,f2) << endl;
	cout << "Multiplicacion: " << multiplicacion<float>(f1,f2) << endl;
	cout << "Division: " << division<float>(f1,f2) << endl;
	cout << endl;
	
	double d1 = 23.22222222, d2 = 8.146646;
	cout << "Para " << d1 << " y " << d2 << endl;
	cout << "Suma: " << suma<double>(d1,d2) << endl;
	cout << "Resta: " << resta<double>(d1,d2) << endl;
	cout << "Multiplicacion: " << multiplicacion<double>(d1,d2) << endl;
	cout << "Division: " << division<double>(d1,d2) << endl;
	cout << endl;
	
	return 0;
}

