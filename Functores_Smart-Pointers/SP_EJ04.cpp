#include <iostream>
#include <memory>
using namespace std;

weak_ptr<int> instancia () {
	shared_ptr<int> ptr = make_shared<int>(1234);
	weak_ptr<int> ptr2 = ptr;
	
	if ( ptr2.expired() == true ) {
		cout << "Ptr func: EL OBJETO REFERENCIADO YA HA SIDO ELIMINADO\n";
	} else {
		cout << "Ptr func: EL OBJETO REFERENCIADO ESTA ACTIVO\n";
	}
	
	return ptr2;
}

int main(int argc, char *argv[]) {
	shared_ptr<int> ptr = make_shared<int>(123);
	weak_ptr<int> ptr2 = ptr;
	
	if ( ptr2.expired() == true ) {
		cout << "Ptr main: EL OBJETO REFERENCIADO YA HA SIDO ELIMINADO\n";
	} else {
		cout << "Ptr main: EL OBJETO REFERENCIADO ESTA ACTIVO\n";
	}
	
	if ( instancia().expired() == true ) {
		cout << "Ptr func: EL OBJETO REFERENCIADO YA HA SIDO ELIMINADO\n";
	} else {
		cout << "Ptr func: EL OBJETO REFERENCIADO ESTA ACTIVO\n";
	}
	
	return 0;
}

