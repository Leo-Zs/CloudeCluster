#include "Servidor.h"
#include <iostream>
#include <iomanip>
using namespace std;

Servidor::Servidor() {
	id = 0;
	nombre = "";
	ip = "";
	arquitectura = "";
	siguiente = NULL;
	anterior = NULL;
	cola = NULL;
}
int Servidor::getId() {
	return id;
}
string Servidor::getNombre() {
	return nombre;
}
string Servidor::getIp() {
	return ip;
}
string Servidor::getArquitectura() {
	return arquitectura;
}
void Servidor::setNombre(string nuevoNombre) {
	nombre = nuevoNombre;
}
void Servidor::setArquitectura(string nuevaArquitectura) {
	arquitectura = nuevaArquitectura;
}

Servidor* Servidor::getSiguiente()
{
	return siguiente;
}

Servidor* Servidor::getAnterior()
{
	return anterior;
}

void Servidor::setSiguiente(Servidor* nuevo)
{
	siguiente = nuevo;
}

void Servidor::setAnterior(Servidor* nuevo)
{
	anterior = nuevo;
}

void Servidor::setId(int nuevoId)
{
	id = nuevoId;
}

void Servidor::setIp(string nuevaIp)
{
	ip = nuevaIp;
}