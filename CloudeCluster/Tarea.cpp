//metodos
#include "Tarea.h"

static int contadorId = 0;// el pdf pide el id se otorgue de manera automatica
Tarea::Tarea() {
	id = ++contadorId;
	memoria = 0;
	prioridad = 'N';
	nombre = "";
	siguiente = NULL;

}

int Tarea::getId() {
	return id;

}
double Tarea::getMemoria() {
	return memoria;

}
char Tarea::getPrioridad() {
	return prioridad;

}
string Tarea::getNombre() {
	return nombre;
}
Tarea* Tarea::getSiguiente() {
	return siguiente;

}
void Tarea::setMemoria(double memoria) {
	this->memoria = memoria;
}
void Tarea::setPrioridad(char prioridad) {
	this->prioridad = prioridad;
}
void Tarea::setNombre(string nombre) {
	this->nombre = nombre;
}
void Tarea::setSiguiente(Tarea*siguiente) {
	this->siguiente = siguiente;
}


