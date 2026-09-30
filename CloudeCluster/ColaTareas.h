#pragma once
//clase vane
#ifndef COLATAREAS_H
#define COLATAREAS_H
#include "Tarea.h"
class ColaTareas
{

private:

	Tarea* primero;
	Tarea* ultimo;
	int cantidad;

public:

	ColaTareas();
	~ColaTareas();

	void encolar(Tarea*);
	Tarea* desencolar();
	Tarea* getPrimero();
	bool cancelarPorId(int);
	bool estaVacia();
	int getCantidad();
	void mostrarCola();

};
#endif // COLATAREAS_H

