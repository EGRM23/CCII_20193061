#include <iostream>
#include <memory>
using namespace std;

void instancia (shared_ptr<string> ptr3) {
	shared_ptr<string> ptr4;
	ptr4 = ptr3;
	cout << "Punteros en la funci�n: " << ptr4.use_count() << endl;
}

int main() {
	shared_ptr<string> ptr1 = make_shared<string>("SESION");
	shared_ptr<string> ptr2;
	ptr2 = ptr1;
	
	instancia(ptr2);
	cout << "Punteros despu�s de la funci�n: " << ptr2.use_count() << endl;
	return 0;
}

