#include <iostream>
using namespace std;

class contador {
private:
	int cuenta;
public:
	contador() { cuenta = 0; }
public:
	int operator()(int aum) {
		return (cuenta += aum);
	}
};
int main() {
	//Usaremos 2 contadores
	contador c1, c2;
	cout << "C1: " << c1(50) << endl;
	cout << "C2: " << c2(20) << endl;
	cout << "C1: " << c1(37) << endl;
	cout << "C2: " << c2(43) << endl;
	return 0;
}

