//metodos Ash
#include "Cluster.h"
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