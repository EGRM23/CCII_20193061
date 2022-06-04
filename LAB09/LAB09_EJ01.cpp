#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

template <typename R>
class dat {
	private:
		R d1, d2, d3;
	public:
		dat(const R dato1, const R dato2, const R dato3) : d1(dato1), d2(dato2), d3(dato3) {}
		~dat() {}

		R getmayor() {
			R mayor;
			
			if (d1 > d2)
				mayor = d1;
			else
				mayor = d2;
			
			if (d3 > mayor)
				mayor = d3;
			
			return mayor;
		}
		
		R getmenor() {
			R menor;
			
			if (d1 < d2)
				menor = d1;
			else
				menor = d2;
			
			if (d3 < menor)
				menor = d3;
			
			return menor;
		}
};

int main(int argc, char *argv[]) {
	dat<int> dat1(3,4,5);
	cout << "Mayor dat1: " << dat1.getmayor() << endl;
	cout << "Menor dat1: " << dat1.getmenor() << endl;
	
	dat<float> dat2(6.43,7.54,6.76);
	cout << "Mayor dat2: " << dat2.getmayor() << endl;
	cout << "Menor dat2: " << dat2.getmenor() << endl;
	return 0;
}

