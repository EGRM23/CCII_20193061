#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

template <int R, int P>
struct Potencia {
	enum { result = R * Potencia<R,P-1>::result };
};

template <int R>
struct Potencia<R,0> {
	enum { result = 1 };
};

int main(int argc, char *argv[]) {
	int p = Potencia<2,10>::result;
	cout << p << endl;
	return 0;
}

