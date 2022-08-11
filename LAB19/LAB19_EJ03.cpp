#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

class par {
public:
	int a;
	int b;
	par(int x, int y) : a(x),b(y) {}
};

class Algoritmo {
public:
	bool operator()(const par& obj1, const par& obj2) {
		return obj1.a < obj2.b;
	}
	
	void imprimir(vector<par> ref) {
		cout << "[ ";
		for(int i = 0; i < (int)ref.size(); i++) {
			cout << "[" << ref[i].a << "," << ref[i].b << "] ";
		}
		cout << "]\n";
	}
};

int main(int argc, char *argv[]) {
	srand(time(NULL));
	vector<par> ref = {};
	
	for (int i = 0; i < 20; i++)
		ref.push_back(par(1+rand()%(100-1),1+rand()%(100-1)));
	
	Algoritmo functor;
	
	cout << "vec = ";
	functor.imprimir(ref);
	
	cout << endl;
	
	cout << "Ord = ";
	sort(ref.begin(),ref.end(),functor);
	
	functor.imprimir(ref);
	
	return 0;
}

