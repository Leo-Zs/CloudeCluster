#include "ColaTareas.h"
#include <iostream>

//metodos

ColaTareas::ColaTareas(){

	primero = NULL;
	ultimo = NULL;
	cantidad = 0;
}

ColaTareas::~ColaTareas(){

	while (!estaVacia()) {
		delete desencolar();
	}
}

void ColaTareas::encolar(Tarea* nueva){

	nueva->setSiguiente(NULL);

	if (estaVacia()) {
		primero = nueva;
		ultimo = nueva;

	}else {
		ultimo->setSiguiente(nueva);
		ultimo = nueva;
	}
	cantidad++;
}

Tarea* ColaTareas::desencolar(){

	if (estaVacia()){
		return NULL;
	}

	Tarea* aux = primero;
	primero = primero->getSiguiente();
	cantidad--;
	if (estaVacia()) {
		ultimo = NULL;
	}

	aux->setSiguiente(NULL);

	return aux;
}

Tarea* ColaTareas::getPrimero(){

	return primero;
}

bool ColaTareas::cancelarPorId(int id){

	if (estaVacia()){

		return false;
	}

	ColaTareas temporal;
	bool encontrado = false;

	while (!estaVacia()) {

		Tarea* actual = desencolar();

		if (!encontrado && actual->getId() == id) {
			encontrado = true;
			delete actual;
		}else {
			temporal.encolar(actual);
		}
	}

	while (!temporal.estaVacia()) {

		encolar(temporal.desencolar());
	}
	return encontrado;
}

bool ColaTareas::estaVacia() {

	return primero == NULL;
}

int ColaTareas::getCantidad() {

	return cantidad;
}

void ColaTareas::mostrarCola() {

	if (estaVacia()) {

		cout << "La cola de tareas esta vacia " << endl;

		return;
	}

	Tarea* actual = primero;
	while (actual != NULL) {

		cout<<"ID: "<< actual->getId()
			<< " Nombre: " << actual->getNombre()
			<< " Memoria: " << actual->getMemoria()
			<< " Prioridad: " << actual->getPrioridad() << endl;
		actual = actual->getSiguiente();
	}
}