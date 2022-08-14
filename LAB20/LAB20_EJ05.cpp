#include <iostream>
#include <memory>

class Point {
private:
	double x, y;
public:
	Point(double valx, double valy) : x(valx),y(valy) {}
	~Point() {}
	void print() {
		std::cout << "Valor X: " << this->x << std::endl;
		std::cout << "Valor Y: " << this->y << std::endl;
	}
};

class C1 {
private:
	std::weak_ptr<Point> pt;
public:
	C1(std::shared_ptr<Point> value) : pt(value) {}
	virtual ~C1() { std::cout << "\nC1 destructor\n"; }
	void print() {
		std::shared_ptr<Point> temp_pt = pt.lock();
		std::cout << "CLASS C1\n";
		(*temp_pt).print();
	}
};

class C2 {
private:
	std::weak_ptr<Point> pt;
public:
	C2(std::shared_ptr<Point> value) : pt(value) {}
	virtual ~C2() { std::cout << "\nC2 destructor\n"; }
	void print() {
		std::shared_ptr<Point> temp_pt = pt.lock();
		std::cout << "CLASS C2\n";
		(*temp_pt).print();
	}
};

int main() {
	std::shared_ptr<Point> pm = std::make_shared<Point>(3.19507,5.11714);
	
	C1 prueba_c1(pm);
	prueba_c1.print();
	C2 prueba_c2(pm);
	prueba_c2.print();
	
	return 0;
}

