//Dulce Clase
#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
using namespace std;
class ColaTareas; 
typedef class Servidor
{
private:
	int id;
	string nombre;
	string ip;
	string arquitectura;

	Servidor* siguiente;
	Servidor* anterior;
	ColaTareas* cola;

public:
	Servidor();//constructor

	int getId();
	string getIp();
	string getNombre();
	string getArquitectura();

	//Set los metodos que se pueden modificar
	void setNombre(string);
	void setArquitectura(string);
};
#endif // SERVIDOR_H