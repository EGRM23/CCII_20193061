#include <iostream>
#include <vector>
using namespace std;

class Carro {
private:
	string puertas;
	string llantas;
	string timon;
	string asientos;
	string motor;
	string espejos;
	string vidrios;
public:
	void setcolorpuertas(string c) {puertas = c;}
	void setcolorllantas(string c) {llantas = c;}
	void setcolortimon(string c) {timon = c;}
	void setcolorasientos(string c) {asientos = c;}
	void setcolormotor(string c) {motor = c;}
	void setcolorespejos(string c) {espejos = c;}
	void setcolorvidrios(string c) {vidrios = c;}
	
	void ListaPartes()const {
		cout << "Puertas: " << this->puertas;
		cout << "\nLlantas: " << this->llantas;
		cout << "\nTimon: " << this->timon;
		cout << "\nAsientos: " << this->asientos;
		cout << "\nMotor: " << this->motor;
		cout << "\nEspejos: " << this->espejos;
		cout << "\nVidrios: " << this->vidrios;
	}
};

class ICarroBuilder {
public:
	virtual ~ICarroBuilder() {}
	virtual void ProducirPuertas() const = 0;
	virtual void ProducirLlantas() const = 0;
	virtual void ProducirTimon() const = 0;
	virtual void ProducirAsientos() const = 0;
	virtual void ProducirMotor() const = 0;
	virtual void ProducirEspejos() const = 0;
	virtual void ProducirVidrios() const = 0;
};

class BuilderCarroEspecifico : public ICarroBuilder {
private:
	Carro* product;
public:
	BuilderCarroEspecifico() {
		this->Reset();
	}
	~BuilderCarroEspecifico() {
		delete product;
	}
	void Reset() {
		this->product = new Carro();
	}
	void ProducirPuertas()const override{
		int c;
		string colores[] = {"Rojo","Azul","Amarillo","Negro","Blanco"};
		cout << "Puertas ¿Qué color desea?\n";
		for (int i = 0; i < 5; i++) {
			cout << i+1 << " " << colores[i] << endl;
		}
		cout << "Opcion? ";
		cin >> c;
		this->product->setcolorpuertas(colores[c-1]);
		cout << endl;
	}
	void ProducirLlantas()const override {
		int c;
		string colores[] = {"Negro","Blanco","Gris"};
		cout << "Llantas ¿Qué color desea?\n";
		for (int i = 0; i < 3; i++) {
			cout << i+1 << " " << colores[i] << endl;
		}
		cout << "Opcion? ";
		cin >> c;
		this->product->setcolorllantas(colores[c-1]);
		cout << endl;
	}
	void ProducirTimon()const override {
		int c;
		string colores[] = {"Negro","Blanco","Marrón"};
		cout << "Timon ¿Qué color desea?\n";
		for (int i = 0; i < 3; i++) {
			cout << i+1 << " " << colores[i] << endl;
		}
		cout << "Opcion? ";
		cin >> c;
		this->product->setcolortimon(colores[c-1]);
		cout << endl;
	}
	void ProducirAsientos()const override {
		int c;
		string colores[] = {"Negro","Blanco","Marrón"};
		cout << "Asientos ¿Qué color desea?\n";
		for (int i = 0; i < 3; i++) {
			cout << i+1 << " " << colores[i] << endl;
		}
		cout << "Opcion? ";
		cin >> c;
		this->product->setcolorasientos(colores[c-1]);
		cout << endl;
	}
	void ProducirMotor()const override {
		int c;
		string colores[] = {"Negro","Plateado","Blanco"};
		cout << "Motor ¿Qué color desea?\n";
		for (int i = 0; i < 3; i++) {
			cout << i+1 << " " << colores[i] << endl;
		}
		cout << "Opcion? ";
		cin >> c;
		this->product->setcolormotor(colores[c-1]);
		cout << endl;
	}
	void ProducirEspejos()const override {
		int c;
		string colores[] = {"Rojo","Azul","Amarillo","Negro","Blanco"};
		cout << "Espejos ¿Qué color desea?\n";
		for (int i = 0; i < 5; i++) {
			cout << i+1 << " " << colores[i] << endl;
		}
		cout << "Opcion? ";
		cin >> c;
		this->product->setcolorespejos(colores[c-1]);
		cout << endl;
	}
	void ProducirVidrios()const override {
		int c;
		string colores[] = {"Transparentes","Polarizado","Rosado","Celeste"};
		cout << "Vidrios ¿Qué color desea?\n";
		for (int i = 0; i < 4; i++) {
			cout << i+1 << " " << colores[i] << endl;
		}
		cout << "Opcion? ";
		cin >> c;
		this->product->setcolorvidrios(colores[c-1]);
		cout << endl;
	}
	Carro* getCarro() {
		Carro* resultado = this->product;
		this->Reset();
		return resultado;
	}
};

class Director {
private:
	ICarroBuilder* builder;
public:
	void set_builder(ICarroBuilder* builder) {
		this->builder = builder;
	}
	void construct() {
		this->builder->ProducirPuertas();
		this->builder->ProducirLlantas();
		this->builder->ProducirTimon();
		this->builder->ProducirAsientos();
		this->builder->ProducirMotor();
		this->builder->ProducirEspejos();
		this->builder->ProducirVidrios();
	}
};

void ClienteCode(Director& director)
{
	BuilderCarroEspecifico* builder = new BuilderCarroEspecifico();
	director.set_builder(builder);
	cout << "Carro básico:\n";
	director.construct();
	Carro* c = builder->getCarro();
	c->ListaPartes();
	delete c;
	delete builder;
}

int main() {
	Director* director = new Director();
	ClienteCode(*director);
	delete director;
	return 0;
}

