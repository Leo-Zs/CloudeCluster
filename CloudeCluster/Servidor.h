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
	~Servidor();
	int getId();
	string getIp();
	string getNombre();
	string getArquitectura();
	
	ColaTareas* getCola();//permite ver la cola de servidor
	Servidor* getSiguiente();
	Servidor* getAnterior();

	//Set los metodos que se pueden modificar
	void setNombre(string);
	void setArquitectura(string);
	void setSiguiente(Servidor*);
	void setAnterior(Servidor*);
	void setId(int);
	void setIp(string);
};
#endif // SERVIDOR_H



