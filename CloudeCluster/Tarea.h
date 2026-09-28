#pragma once
#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>
#include <string>
using namespace std;

typedef class Tarea// !TAREA_H
{
private:
	int id;
	double memoria;
	char prioridad;
	string nombre;
	Tarea* siguiente;

public:
	Tarea();
	int getId();
	double getMemoria();
	char getPrioridad();
	string getNombre();

	Tarea* getSiguiente();

	void setMemoria(double);
	void setPrioridad(char);
	void setNombre(string);
	void setSiguiente(Tarea*);



};

#endif 
//clase kris
