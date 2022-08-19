#include <iostream>
using namespace std;

class clasesuma {
public:
	int operator()(const int n1, const int n2) {
		return n1 + n2;
	}
};

int funcsuma (const int n1, const int n2) {
	return n1 + n2;
}

template <typename OperRealz>
int matenum (int n1, int n2, OperRealz opm) {
	return opm(n1,n2);
}

int main() {
	int n1 = 15, n2 = 43;
	clasesuma sum;
	cout << "Con funcion: " << matenum(n1,n2,funcsuma) << endl;
	cout << "Con clase: " << matenum(n1,n2,sum) << endl;
	return 0;
}

