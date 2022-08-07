#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

const string molde = "0123456789ABCDEF";

template <int num, int base>
struct Convertidor {
	enum { nuevonum = num/base, dig = num%base };
	string result = Convertidor<nuevonum,base>().result + molde[dig];
};

template <int base>
struct Convertidor<0,base> {
	string result = "";
};

int main(int argc, char *argv[]) {
	string cad = Convertidor<256+15,16>().result;
	cout << cad << endl;
	return 0;
}

