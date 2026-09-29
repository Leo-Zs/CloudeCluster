#include <iostream>
#include "Cluster.h"
using namespace std;

int main()
{
	Cluster cluster;
	int opcion;
    do
    {
        cout << "====CLOUDE CLUSTER===="<<endl;
        cout << "1.Registrar Servidor" << endl;
        cout << "2.Mostrar Servidores" << endl;
        cout << "3.Modificar Servidor" << endl;
        cout << "4.Eliminar Servidor" << endl;
        cout << "5.Registrar Tarea en Servidor" << endl; 
        cout << "6.Resolver Tarea de Servidor" << endl;
        cout << "7.Cancelar Tarea" << endl;
        cout << "8.Salir" << endl;  
        cout << "Escoja una Opcion: " << endl;
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:

            cluster.registrarServidor();
            break;
        case 2:

            cluster.mostrarServidores();
            break;
        case 3:

            cluster.modificarServidor();
            break;
        case 4:

            cluster.eliminarServidor();
            break;
        case 5:
            cluster.registrarTarea();
            break;
		case 6:
            cluster.resolverTarea();
			break;
        case 7: 
            //cluster.cancelarTarea();
            break;
		case 8:
			cout << "Saliendo del programa";
			break;
        default:
            cout << "\n\n Opcion No Valida \n\n";
        }
    } while (opcion != 8);
    return 0;
}


