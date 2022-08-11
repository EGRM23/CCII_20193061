#include <iostream>
#include <vector>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

class RegrLineal {
public:
	vector<double> operator()(vector<int> x, vector<int> y) {
		double sum1 = 0, sum2 = 0, medx = 0, medy = 0;
		double a, b;
		
		for(int i = 0; i < (int)x.size(); i++) {
			medx += x[i];
			medy += y[i];
		}
		
		medx = medx/x.size();
		medy = medy/y.size();
		
		for(int i = 0; i < (int)x.size(); i++) {
			sum1 += (x[i]-medx)*(y[i]-medy);
			sum2 += (x[i]-medx)*(x[i]-medx);
		}

		b = sum1/sum2;
		a = medy - b*medx;
		
		vector<double> result = {a,b};
		
		return result;
	}
	
	void imprimir(vector<int> x) {
		cout << "[ ";
		for(int i = 0; i < (int)x.size(); i++) {
			cout << x[i] << " ";
		}
		cout << "]\n";
	}
};
int main(int argc, char *argv[]) {
	vector<int> x = {-13,0,9,20,33,50};
	vector<int> y = {322,335,337,346,352,365};
	
	RegrLineal Ej1;
	vector<double> param = Ej1(x,y);
	
	cout << "x = ";
	Ej1.imprimir(x);
	cout << "y = ";
	Ej1.imprimir(y);
	cout << endl;
	cout << "y = " << param[0] << " + " << param[1] << "x";
	return 0;
}

