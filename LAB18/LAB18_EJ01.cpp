#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

template <int R>
struct sumadig {
	enum { suma = R - (R/10)*10 + sumadig<R/10>::suma };
};

template <>
struct sumadig<0> {
	enum { suma = 0 };
};

int main(int argc, char *argv[]) {
	int s = sumadig<123>::suma;
	cout << s << endl;
	return 0;
}

