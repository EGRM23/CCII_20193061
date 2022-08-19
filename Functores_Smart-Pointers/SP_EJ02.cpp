#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char *argv[]) {
	unique_ptr<int> ptr1(new int(40));
	unique_ptr<int> ptr2 = make_unique<int>(50);
	unique_ptr<int> ptr3;
	
	cout << "Puntero 1 con new: " << *ptr1 << endl;
	cout << "Puntero 2 con make_unique: " << *ptr2 << endl;
	ptr3 = move(ptr2);
	cout << "Puntero 2: ";
	if (ptr2 == nullptr) {
		cout<< 0 << endl;
	} else {
		cout<< *ptr2 << endl;
	}
	cout << "Puntero 3 con move: " << *ptr3 << endl;
	
	return 0;
}

