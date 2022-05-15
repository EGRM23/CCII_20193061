#include <iostream>
#include <time.h>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

//3. Implemente un programa con clases que lea la fecha de nacimiento y la fecha de hoy
//	y muestre por pantalla el nombre y la edad de la persona.

class Persona {
private:
	string nombre;
	int d;
	int m;
	int a;
public:
	Persona();
	~Persona();
	bool EsBisiesto();
	bool Validacion();
	int DiasDelMes();
	void Edad();
	void imprimirdat();
};


Persona :: Persona () {
	cout << "Nombre: ";
	cin >> nombre;
	
	do {
		cout << "FECHA DE NACIMIENTO\n";
		cout << "Año? ";
		cin >> a;
		cout << "Mes? ";
		cin >> m;
		cout << "Dia? ";
		cin >> d;
		
		if (Validacion() == false){
			cout<<"FECHA INVALIDA! Ingrese los datos de nuevo\n";
			cout<<endl;
		} else
			break;
		
	} while (true);
}

Persona :: ~Persona() {}

bool Persona :: EsBisiesto() {
	if(a%4 == 0)
		if(a%100 == 0 && a%400 != 0)
		return false; //No es bisiesto
		else {
			return true; //Si es bisiesto
		}
	else
			return false; //No es bisiesto
}

bool Persona :: Validacion() {
	if (m > 0 && m <= 12){
		if (d > 0 && d <= 31){
			if (m == 4 || m == 6 || m == 9 || m == 11){
				if (d != 31)
					return true;
				else
					return false;
			} else if(m == 2){
				if (d == 30 || d == 31)
					return false;
				else if (EsBisiesto() == true || d == 29)
					return false;
				else
					return false;
			} else
					  return true;
		} else
			return false;
	} else
		return false;
}

int Persona :: DiasDelMes() {
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	else if (m == 2){
		if(EsBisiesto() == 1)
			return 29;
		else
			return 28;
	} else
			 return 31;
}

void Persona :: Edad() {
	int dE = 0, mE = 0, aE = 0, dA, mA, aA;
	
	time_t t = time(NULL);
	struct tm tiempoLocal = *localtime(&t);
	dA = tiempoLocal.tm_mday;
	mA = (tiempoLocal.tm_mon) + 1;
	aA = (tiempoLocal.tm_year) + 1900;
	
	if (aA == a) {
		if (mA == m)
			dE = dA - d;
		else {
			if (mA - 1 != m)
				mE = mA - m - 1;
			
			if (dA >= d) {
				mE++;
				dE = dA - d;
			} else
				dE = DiasDelMes() - d + dA;
		}
	} else {
		if (aA - 1 != a)
			aE = aA - a - 1;
		
		if (mA > m) {
			aE++;
			mE = mA - m;
			
			if (dA >= d)
				dE = dA - d;
			else {
				dE = DiasDelMes() - d + dA;
				mE--;
			}
		} else if (mA == m) {
			if (dA >= d) {
				aE++;
				dE = dA - d;
			}
			else {
				mE = 12 - m + mA - 1;
				if (dA >= d) {
					mE++;
					dE = dA - d;
				} else
					dE = DiasDelMes() - d + dA;
			}
		}
		
		if (mE == 12)
			aE++;
	}
	
	cout << "Fecha Actual: " << dA << "-" << mA << "-" << aA << endl;
	cout << "Edad: " << aE << " años, " << mE << " meses y " << dE << " días\n";
}

void Persona :: imprimirdat() {
	cout << "DATOS DE LA PERSONA\n";
	cout << "Nombre: " << nombre << endl;
	cout << "Fecha de nacimiento: " << d << "-" << m << "-" << a << endl;
	Edad();
}

int main(int argc, char *argv[]) {
	Persona pers_1;
	
	cout << endl;
	pers_1.imprimirdat();
	
	return 0;
}

