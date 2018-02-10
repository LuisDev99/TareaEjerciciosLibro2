#include <iostream>
#include<string>
using namespace std;


class Cuenta {

private:
	int saldo;

public:
	Cuenta(int );
	~Cuenta();
	void abonar(int);
	void retirar(int);
	int obtenerSaldo();

};


Cuenta::Cuenta(int _saldo) {

	if (_saldo >= 0) {
		saldo = _saldo;
	}
	else {
		saldo = 0;
		cout << "Monto debe ser mayor o igual a cero" << endl;
	}
}

Cuenta::~Cuenta() {

}

void Cuenta::abonar(int cant) {
	saldo += cant;
}

void Cuenta::retirar(int cant) {
	if (cant > saldo) {
		cout << "EL monto a retirar excede al saldo actual de la cuenta" << endl;
		return;
	}
	else {
		saldo -= cant;
	}

}

int Cuenta::obtenerSaldo() {
	return saldo;
}


class Factura {

private:
	string numeroPieza, descripcionPieza;
	int cantidadCompra, precio;

public:
	Factura(string, string, int, int);
	~Factura();
	void setNumeroPieza(string);
	void setDescripcion(string);
	void setCantidadCompra(int);
	void setPrecio(int);
	string getNumeroPieza();
	string getDescripcion();
	int getCantidadCompra();
	int obtenerMontoFactura(); 
	int getPrecio();

};


Factura::Factura(string nPieza, string descripcion, int cant, int precio) {

}

Factura::~Factura() {

}

void Factura::setNumeroPieza(string pieza) {
	numeroPieza = pieza;
}

void Factura::setCantidadCompra(int cant) {
	cantidadCompra = cant;
}

void Factura::setDescripcion(string descr) {
	descripcionPieza = descr;
}

void Factura::setPrecio(int pre) {
	precio = pre;
}

int Factura::getCantidadCompra() {
	return cantidadCompra;
}

int Factura::getPrecio() {
	return precio;
}

string Factura::getDescripcion() {
	return descripcionPieza;
}

string Factura::getNumeroPieza() {
	return numeroPieza;
}

int Factura::obtenerMontoFactura() {
	if (cantidadCompra > 0 && precio > 0)
		return (cantidadCompra * precio);
	if (cantidadCompra < 0)
		cantidadCompra = 0;
	if (precio < 0)
		precio = 0;

	return 0;

}

class Fecha {

private:
	int mes, dia, año;

public:
	Fecha(int, int, int);
	~Fecha();
	void setMes(int);
	void setDia(int);
	void setAño(int);
	int getMes();
	int getDia();
	int getAño();
	void mostrarFecha();

};


Fecha::Fecha(int _dia, int _mes, int _año) {
	if (!(mes > 0 && mes <= 12))
		_mes = 1;
	dia = _dia;
	año = _año;
}

Fecha::~Fecha() {

}
void Fecha::setMes(int _mes) {
	mes = _mes;
}
void Fecha::setAño(int _año) {
	año = _año;
}
void Fecha::setDia(int _dia) {
	dia = _dia;
}

int Fecha::getDia() {
	return dia;
}

int Fecha::getAño() {
	return año;
}

int Fecha::getMes() {
	return mes;
}

void Fecha::mostrarFecha() {
	cout << dia << "/" << mes << "/" << año << endl;
}


class Paquete {

protected:
	string nombre, direccion, ciudad, estado;
	int codigoPostalEmisor, codigoPostalDestinatario;
	double costo, peso;

public:
	Paquete(string, string, string, string, double, int, int , double);
	~Paquete();
	double calcularCosto();


};


Paquete::Paquete(string n, string d, string c, string e, double _peso, int _cPE, int cPD, double _costo) {

	nombre = n;
	direccion = d;
	ciudad = c;
	estado = e;
	codigoPostalEmisor = _cPE;
	codigoPostalDestinatario = cPD;

	if (!(peso >= 0 && costo >= 0)) 
		peso = costo = 0;
	else
	{
		peso = _peso;
		costo = _costo;
	}
}

Paquete::~Paquete() {


}

double Paquete::calcularCosto() {
	return peso * costo;
}

class PaqueteDosDias : public Paquete {

private:
	int cuota;

public:
	PaqueteDosDias(string, string, string, string, double, int, int, double, int);
	double calcularCosto();

};

PaqueteDosDias::PaqueteDosDias(string n, string d, string c, string e, double _peso, int _cPE, int cPD, double _costo, int _cuota)
	: Paquete(n, d, c, e, _peso, _cPE, cPD, _costo) {
	cuota = _cuota;
}

double PaqueteDosDias::calcularCosto() {
	double c = calcularCosto();
	return c + cuota;

}

class PaqueteNocturno : public Paquete{

private:
	int cuota;
public:
	double calcularCosto();
	PaqueteNocturno(string, string, string, string, double, int, int, double, int);
	~PaqueteNocturno();
};

PaqueteNocturno::PaqueteNocturno(string n, string d, string c, string e, double _peso, int _cPE, int cPD, double _costo, int _cuota)
	: Paquete(n, d, c, e, _peso, _cPE, cPD, _costo) {

	cuota = _cuota;
}

double PaqueteNocturno::calcularCosto() {
	
	 return calcularCosto() * cuota;
}

PaqueteNocturno::~PaqueteNocturno() {

}


void ej12();
void ej13();
void ej15();
void ej9();


int main() {

	int menu;

	do {
		system("cls");
		cout << "Probar ejercicios\n" << "1. 3.12\n2. 3.13\n3. 3.15\n4. 11.9\nIngrese lo que quiere hacer: ";
		cin >> menu;

		switch (menu) {
		case 1:
			ej12();
			break;
		case 2:
			ej13();
			break;
		case 3:
			ej15();
			break;
		case 4:
			ej9();
			break;

		}



	} while (menu != 5);


	system("pause");
}

void ej12() {
	int menu, saldo = 0;
	cout << "Ingrese el saldo inicial: ";
	cin >> saldo;
	cout << endl;
	Cuenta c(saldo);
	do {
		cout << "1. Abonar\n2. Retirar\n3. Obtener saldo\n4 o mas Para Salir de este ejercicio\nIngrese lo que quiere hacer: ";
		cin >> menu;

		switch (menu) {

		case 1:
			cout << "Ingrese el monto: ";
			cin >> saldo;
			c.abonar(saldo);
			cout << endl;
			break;
		case 2:
			cout << "Ingrese el monto a retirar: ";
			cin >> saldo;
			c.retirar(saldo);
			cout << endl;
			break;
		case 3:
			cout << "Saldo actual: "+c.obtenerSaldo() << endl;
			break;
		}

	} while (menu >= 4);
	

}

void ej13() {
	system("cls");
	string numeroPieza, descripcionPieza;
	int cantidadCompra, precio;
	cout << "Llene los siguientes campos\n";
	cout << "Ingrese numero pieza: ";
	cin >> numeroPieza;
	cout << "\nIngrese la descripcion de la misma: ";
	cin >> descripcionPieza;
	cout << "\nCAntidad a comprar: ";
	cin >> cantidadCompra;
	cout << "\nEl precio: ";
	cin >> precio;
	

	Factura f(numeroPieza, descripcionPieza, cantidadCompra, precio);
	int menu;
	
	system("cls");
	cout << "1. Set Numero Pieza\n2. Set Descripcion\n3. Set Cantidad Compra\n4. Set Precio\n5. Get Numero Pieza\n6. Get Descripcion\n7. Get Cantidad Compra\n8. Get Precio\n9. Ver monto total\nIngrese la opcion ( ingrese num mayor a 9 para salir): ";
	cin >> menu;

	switch (menu)
	{
	case 1:
		cout << "Ingrese numero pieza: ";
		cin >> numeroPieza;
		f.setNumeroPieza(numeroPieza);
		break;
	case 2:
		cout << "\nIngrese la descripcion: ";
		cin >> descripcionPieza;
		f.setDescripcion(descripcionPieza);
		break;
	case 3:
		cout << "\nCAntidad a comprar: ";
		cin >> cantidadCompra;
		f.setCantidadCompra(cantidadCompra);
		break;
	case 4:
		cout << "\nEl precio: ";
		cin >> precio;
		f.setPrecio(precio);
		break;
	case 5:
		cout << f.getNumeroPieza() << endl;
		break;
	case 6:
		cout << f.getDescripcion() << endl;
		break;
	case 7:
		break;
		cout << f.getCantidadCompra() << endl;
	case 8:
		cout << f.getPrecio() << endl;
		break;
	case 9:
		cout << f.obtenerMontoFactura() << endl;
		break;
	}
}

void ej15() {
	int menu, dia, año, mes;
	system("cls");
	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el año: ";
	cin >> año;
	cout << "Ingrese el mes: ";
	cin >> mes;
	Fecha f(dia, mes, año);

	cout << "1. Set Dia\n2. Set Mes\n3. Set Año\n4. Get Dia\n5. Get Mes\n6. Get Año\n7Print fecha\nIngrese lo que quiere hacer (num > 7 para salir): ";
	cin >> menu;

	switch (menu) {
	case 1:
		cout << "Ingrese el dia: ";
		cin >> dia;
		f.setDia(dia);
		break;
	case 2:
		cout << "Ingrese el mes: ";
		cin >> mes;
		f.setMes(mes);
		break;
	case 3:
		cout << "Ingrese el año: ";
		cin >> año;
		f.setAño(año);
		break;
	case 4:
		cout << f.getDia() << endl;
		break;
	case 5:
		cout << f.getMes() << endl;
		break;
	case 6:
		cout << f.getAño() << endl;
		break;
	case 7:
		f.mostrarFecha();
		break;

	}
}

void ej9() {
	int menu;
	string nombre, direccion, ciudad, estado;
	int codigoPostalEmisor, codigoPostalDestinatario;
	double costo, peso;
	cout << "Ingrese Nombre: ";
	cin >> nombre;
	cout << "Ingrese direccion: ";
	cin >> direccion;
	cout << "Ingrese la ciudad: ";
	cin >> ciudad;
	cout << "Ingrese el estado: ";
	cin >> estado;
	cout << "Ingrese el codigo postal del emisor (int): ";
	cin >> codigoPostalEmisor;
	cout << "Ingrese el codigo postal del destinatario (int): ";
	cin >> codigoPostalDestinatario;
	cout << "Ingrese el costo: ";
	cin >> costo;
	cout << "Ingrese el peso: ";
	cin >> peso;

	Paquete v(nombre, direccion, ciudad, estado, peso, codigoPostalEmisor, codigoPostalDestinatario, costo);
	PaqueteNocturno n(nombre, direccion, ciudad, estado, peso, codigoPostalEmisor, codigoPostalDestinatario, costo, 200);
	PaqueteDosDias d(nombre, direccion, ciudad, estado, peso, codigoPostalEmisor, codigoPostalDestinatario, costo, 200);

	system("cls");

	cout << "Imprimiendo **" << endl;
	cout << "Costo: " << v.calcularCosto() << endl;
	cout << "LA CUOTA SE HIZO HARDCODED, Que vale 200" << endl;
	cout << "Costo por envio nocturno: " << n.calcularCosto() << endl;
	cout << "Costo por envio dos dias: " << d.calcularCosto() << endl;


}
