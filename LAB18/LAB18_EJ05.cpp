#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

template <int num>
struct Convertidor {
	enum { result = num%2 + Convertidor<num/2>::result*10 };
};

template <>
struct Convertidor<0> {
	enum { result = 0 };
};
int main(int argc, char *argv[]) {
	int v = Convertidor<64+4+1>::result;
	cout << v << endl;
	return 0;
}

