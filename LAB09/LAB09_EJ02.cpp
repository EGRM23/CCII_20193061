#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

template <typename I, typename F>
void operaciones (const I num1, const F num2) {
	cout << "Suma: " << num1 + num2 << endl;
	cout << "Resta: " << num1 - num2 << endl;
	cout << "Multiplicacion: " << num1 * num2 << endl;
	cout << "Division: " << num1 / num2 << endl;
}

int main(int argc, char *argv[]) {
	operaciones<int,float> (3,1.5);
	return 0;
}
