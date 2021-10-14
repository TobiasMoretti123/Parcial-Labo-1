#include "Informes.h"
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {
	int idCliente;
	char nombreEmpresa[20];
	char cuit[20];
	char direccion[20];
	char localidad[20];
	int isEmpty;

} eCliente;

int GenerarIdCliente();
eCliente IngresarCliente();
int AltaCliente(eCliente listaClientes[], int tamClientes);
int InicializarClientes(eCliente listaClientes[], int tamClientes);
int BuscarEspacioVacio(eCliente listaClientes[], int tamClientes);
int ImprimirClientes(eCliente listaClientes[], int tamClientes);
void MostrarCliente(eCliente unCliente);
int BuscarIdCliente(eCliente listaClientes[], int tamClientes, int id);
int BajaCliente(eCliente listaClientes[], int tamClientes, int id);
int ModificarCliente(eCliente listaClientes[], int tamClientes, int id);

#endif /* CLIENTE_H_ */
