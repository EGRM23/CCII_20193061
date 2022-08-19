#include <iostream>
using namespace std;

class compara {
public:
	virtual ~compara() {};
	virtual int operator()(const int n1, const int n2) const = 0;
	virtual int operator()(const int n1, const int n2, const int n3) const = 0;
};

class mayor : public compara {
public:
	int operator()(const int n1, const int n2) const override {
		if (n1 > n2)
			return n1;
		else
			return n2;
	}
	int operator()(const int n1, const int n2, const int n3) const override {
		if (n1 >= n2 && n1 >= n3)
			return n1;
		else if (n2 >= n1 && n2 >= n3)
			return n2;
		else
			return n3;
	}
};

class menor : public compara {
public:
	int operator()(const int n1, const int n2) const override {
		if (n1 < n2)
			return n1;
		else
			return n2;
	}
	int operator()(const int n1, const int n2, const int n3) const override {
		if (n1 <= n2 && n1 <= n3)
			return n1;
		else if (n2 <= n1 && n2 <= n3)
			return n2;
		else
			return n3;
	}
};

int main() {
	int n1 = 23, n2 = 16, n3 = 31;
	compara *Comp;
	Comp = new mayor;
	cout << "Mayor de 2: " << (*Comp)(n1,n2) << endl;
	cout << "Mayor de 3: " << (*Comp)(n1,n2,n3) << endl;
	delete Comp;
	Comp = new menor;
	cout << "Menor de 2: " << (*Comp)(n1,n3) << endl;
	cout << "Menor de 3: " << (*Comp)(n1,n2,n3) << endl;
	delete Comp;
	return 0;
}

