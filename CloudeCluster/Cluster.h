//clase Ash
#ifndef CLUSTER_H
#define CLUSTER_H
#include "Servidor.h"
class Cluster
{
private:
	Servidor* primero;
	Servidor* ultimo;

public:
	Cluster();

	void registrarServidor();
	Servidor* buscarServidor(int);
	void mostrarServidores();
	void modificarServidor();
	void eliminarServidor();

	//Metodos de Tareas
	void registrarTarea();
	void resolverTarea();
	void cancelarTarea();
};
#endif // CLUSTER_H