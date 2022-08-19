#include <iostream>
using namespace std;

template <class R>
class SmartPointer {
	R* ptr;
public:
	SmartPointer(R* p = NULL) { ptr = p; }
	~SmartPointer() {
		delete (ptr);
		cout << "Puntero liberado" << endl;
	}

	R& operator*() { return *ptr; } //Sobrecarga de *
	R* operator->() { return ptr; } //Sobrecarga de ->
};

int main() {
	SmartPointer<int> ptr1(new int());
	SmartPointer<double> ptr2(new double());
	*ptr1 = 20;
	cout << *ptr1 << endl;
	*ptr2 = 3.122412;
	cout << *ptr2 << endl;;
	return 0;
}

