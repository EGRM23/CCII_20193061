#include <iostream>
#include <memory>

class C1 {
private:
	std::shared_ptr<double> d;
public:
	C1(std::shared_ptr<double> value) : d(value) {}
	virtual ~C1() { std::cout << "\nC1 destructor\n"; }
	void print() const { std::cout << "C1 Valor " << *d << std::endl; }
};

class C2 {
private:
	std::shared_ptr<double> d;
public:
	C2(std::shared_ptr<double> value) : d(value) {}
	virtual ~C2() { std::cout << "\nC2 destructor\n"; }
	void print() const { std::cout << "C2 Valor " << *d << std::endl; }
};

int main() {
	std::shared_ptr<double> dm = std::make_shared<double>(4.232);
	
	C1 prueba_c1(dm);
	prueba_c1.print();
	C2 prueba_c2(dm);
	prueba_c2.print();
	
	return 0;
}
