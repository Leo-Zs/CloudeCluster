//metodos Ash
#include "Cluster.h"
#include "ColaTareas.h"
#include<iostream>
#include <string>

using namespace std;

Cluster::Cluster()
{
	primero = NULL;
	ultimo = NULL;
}

Servidor* Cluster::buscarServidor(int id)
{
	if (primero == NULL)
	{
		return NULL;
	}
	Servidor* actual = primero;
	do
	{
		if (actual->getId() == id)
		{
			return actual;
		}
		actual = actual->getSiguiente();

	} while (actual != primero);

	return NULL;
}

void Cluster::registrarServidor()
{
	int id;
	string nombre;
	string ip;
	string arquitectura;

	cout << "Contamos solo con 8 servidores, digite el ID del servidor debe estar entre 1 y 8: ";
	cin >> id;

	if (id < 1 || id > 8)
	{
		cout << "El ID debe estar entre 1 y 8 " << endl;
		return;
	}

	if (buscarServidor(id) != NULL)
	{
		cout << "Ya existe un servidor con ese ID" << endl;
		return;
	}
	cout << "Digite el nombre del servidor: ";
	cin >> nombre;

	cout << "Digite la IP del servidor: ";
	cin >> ip;

	if (primero != NULL)
	{
		Servidor* actual = primero;

		do 
		{
			if (actual->getIp() == ip)
			{
				cout << "Ya existe un servidor con esa IP " << endl;
				return;
			}
			actual = actual->getSiguiente();
		} while (actual != primero);
	}
	cout << "Digite la arquitectura del servidor: ";
	cin >> arquitectura;

	Servidor* nuevo = new Servidor();

	nuevo->setId(id);
	nuevo->setNombre(nombre);
	nuevo->setIp(ip);
	nuevo->setArquitectura(arquitectura);

	if (primero == NULL)
	{
		primero = nuevo;
		ultimo = nuevo;

		nuevo->setSiguiente(nuevo);
		nuevo->setAnterior(nuevo);
	}
	else
	{
		nuevo->setAnterior(ultimo);
		nuevo->setSiguiente(primero);

		ultimo->setSiguiente(nuevo);
		primero->setAnterior(nuevo);

		ultimo = nuevo;
	}
	cout << "Servidor registrado correctamente" << endl;
}

void Cluster::mostrarServidores()
{
	if (primero == NULL)
	{
		cout<<"No hay servidores registrados" << endl;
		return;
	}
	Servidor* actual = primero;
	cout << endl;
	cout << "Servidores" << endl;
	do {
		cout << "ID: " << actual->getId() << endl;
		cout << "Nombre: " << actual->getNombre() << endl;
		cout << "IP: " << actual->getIp() << endl;
		cout << "Arquitectura: " << actual->getArquitectura() << endl;

		cout << "Tareas pendientes: " << actual->getCola()->getCantidad() << endl;
		if (!actual->getCola()->estaVacia())
		{
			cout << "Tareas: " << endl;
			actual->getCola()->mostrarCola();
		}
		else
		{
			cout << "No tiene tareas pendientes." << endl;
		}

		actual = actual->getSiguiente();
	} while (actual != primero);
}

void Cluster::modificarServidor()
{
	int id;
	string nombre;
	string arquitectura;

	if (primero == NULL)
	{
		cout << "No hay servidores registrados" << endl;
		return;
	}

	cout << "Digite el ID del servidor que desea modificar: ";
	cin >> id;

	Servidor* servidor = buscarServidor(id);

	if (servidor == NULL)
	{
		cout << "No existe un servidor con ese ID." << endl;
		return;
	}
	
	cout << "Nombre actual del servidor: " << servidor->getNombre() << endl;

	cout << "Digite el nuevo nombre del servidor: ";
	cin >> nombre;

	cout << "Arquitectura actual del servidor: "
		<< servidor->getArquitectura() << endl;

	cout << "Digite la nueva arquitectura del servidor: ";
	cin >> arquitectura;

	servidor->setNombre(nombre);
	servidor->setArquitectura(arquitectura);

	cout << "Servidor modificado correctamente." << endl;
}

void Cluster::eliminarServidor() 
{
	int id;

	if (primero == NULL)
	{
		cout << "No hay servidores registrados" << endl;
		return;
	}

	cout << "Digite el ID del servidor que desea eliminar: ";
	cin >> id;

	Servidor* servidor = buscarServidor(id);

	if (servidor == NULL)
	{
		cout << "No existe un servidor con ese ID." << endl;
		return;
	}
	if (!servidor->getCola()->estaVacia())
	{
		cout << "No se puede eliminar el servidor porque tiene tareas pendientes." << endl;
		return;
	}

	if (primero == ultimo)
	{
		primero = NULL;
		ultimo = NULL;
	}
	else
	{
		if (servidor == primero)
		{
			primero = primero->getSiguiente();

			primero->setAnterior(ultimo);
			ultimo->setSiguiente(primero);
		}
		else if (servidor == ultimo)
		{
			ultimo = ultimo->getAnterior();

			ultimo->setSiguiente(primero);
			primero->setAnterior(ultimo);
		}
		else
		{
			Servidor* anterior = servidor->getAnterior();
			Servidor* siguiente = servidor->getSiguiente();

			anterior->setSiguiente(siguiente);
			siguiente->setAnterior(anterior);
		}
	}
	delete servidor;
	cout << "Servidor eliminado correctamente." << endl;
}
void Cluster::registrarTarea() {

	if (primero == NULL) {
		cout << "No hay servidores registrados" << endl;
		return;
	}
	string nombre;
	double memoria;
	char prioridad;

	cout << "Escriba el nombre de la tarea: ";
	cin.ignore();
	getline(cin, nombre);

	do {
		cout << "Escriba la memoria requerida de la tarea en GB:";
		cin >> memoria;

		if (memoria <= 0) {
			cout << "La memoria debe ser mayor a 0";

		}
	} while (memoria <= 0);

	do {
		cout << "Escriba la prioridad de su tarea (N es normal // C= Critica):";
		cin >> prioridad;
		if(prioridad != 'N' && prioridad != 'C') {
			cout << "Prioridad inválida. Por favor, ingrese 'N' para normal o 'C' para crítica.";
		}
	} while (prioridad != 'N' && prioridad != 'C');

	Tarea* nuevaTarea = new Tarea();
	nuevaTarea->setNombre(nombre);
	nuevaTarea->setMemoria(memoria);
	nuevaTarea->setPrioridad(prioridad);

	Servidor* servidorElegido = NULL;
	if (prioridad == 'C' || memoria > 32) {
		Servidor* actual = primero;

		do {
			if (actual->getArquitectura() == "High-Performance") {
				if (servidorElegido == NULL || actual->getCola()->getCantidad() <
					servidorElegido->getCola()->getCantidad()) {
					servidorElegido = actual;
				}


			}
			actual = actual->getSiguiente();
		} while (actual != primero);
	}
	else {
		Servidor* actual = primero;
		do {
			if (servidorElegido == NULL || actual->getCola()->getCantidad() < 
				servidorElegido->getCola()->getCantidad()) {
				servidorElegido = actual;
			}
			actual = actual->getSiguiente();
		} while (actual != primero);
	}
	if (servidorElegido == NULL) {
		cout << "No hay un servidor disponible para la tarea...";
		delete nuevaTarea;
		return;
	}
	servidorElegido->getCola()->encolar(nuevaTarea);
	cout << endl;
	cout << "La tarea se registro correctamente" << endl;
	cout << "El ID de Tarea es:" << nuevaTarea->getId() << endl;
	cout << "El servidor asignado a la tarea es:" <<servidorElegido->getId() << endl;
}
void Cluster::resolverTarea() {

	if (primero == NULL) {
		cout << "No hay servidores registrados" << endl;
		return;
	}
	int idServidor;
	cout << "Digite el ID del servidor para resolver la tarea de su respectiva Cola: ";
	cin >> idServidor;

	Servidor* servidor = buscarServidor(idServidor);
	if (servidor == NULL) {
		cout << "No existe servidor con ese ID...";
		return;
	}
	if (servidor->getCola()->estaVacia())
	{
		cout << "El servidor no tiene tareas pendientes." << endl;
		return;
	}
	Tarea*tarea = servidor->getCola()->getPrimero();

	cout << endl;
	cout << "Estado actual del servidor con las tareas " << endl;
	cout << "Servidor: " << servidor->getNombre() << endl;
	cout << "IP: " << servidor->getIp() << endl;
	cout << "ID de tarea: " << tarea->getId() << endl;
	cout << "Nombre: " << tarea->getNombre() << endl;
	cout << "Memoria: " << tarea->getMemoria() << " GB" << endl;
	cout << "Prioridad: " << tarea->getPrioridad() << endl;
	cout << "Tareas pendientes: " << servidor->getCola()->getCantidad() << endl;

	tarea = servidor->getCola()->desencolar();

	cout << endl;
	cout << "==Estado actualizado de la tareas del servidor==" << endl;
	cout << "La tarea se resolvio correctamente" << endl;
	cout << "Servidor: " << servidor->getNombre() << endl;
	cout << "IP: " << servidor->getIp() << endl;
	cout << "Nombre de la Tarea:" << tarea->getNombre() << endl;
	cout << "Tareas pendientes: " << servidor->getCola()->getCantidad() << endl;

	delete tarea;
}

void Cluster::cancelarTarea() {

	int idServidor;
	int idTarea;

	cout << "Digite el ID del servidor: ";
	cin >> idServidor;

	Servidor* servidor = buscarServidor(idServidor);

	if(servidor == NULL) {
		cout << "No existe un servidor con ese ID..." << endl;
		return;
	}

	if (servidor->getCola()->estaVacia()) {
		cout << "El servidor no tiene tareas pendientes " << endl;
		return;

	}

	cout << "Digite el ID de la tarea que desea eliminar: ";
	cin >> idTarea;

	if (servidor->getCola()->cancelarPorId(idTarea)) {
		cout << "La tarea se eliminó correctamente" << endl;
	}else{
		cout << "No se encontró una tarea con ese ID en el servidor" << endl;
	}

}
