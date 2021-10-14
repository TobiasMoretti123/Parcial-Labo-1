#include "Informes.h"
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {
	int idCliente;
	char nombreEmpresa[20];
	char cuit[20];
	char direccion[20];
	int idLocalidad;
	int isEmpty;

} eCliente;
typedef struct{
	int idLocalidad;
	char descripcion[20];
} eLocalidad;

int GenerarIdCliente();
eCliente IngresarCliente(eLocalidad unaLocalidad);
int AltaCliente(eCliente listaClientes[],eLocalidad listaLocalidad[],int tamLocalidad, int tamClientes);
int InicializarClientes(eCliente listaClientes[], int tamClientes);
int BuscarEspacioVacio(eCliente listaClientes[], int tamClientes);
int ImprimirClientes(eCliente listaClientes[],eLocalidad listaLocalidad[],int tamLocalidad, int tamClientes);
void MostrarCliente(eCliente unCliente, eLocalidad unaLocalidad);
int BuscarIdCliente(eCliente listaClientes[], int tamClientes, int id);
int BajaCliente(eCliente listaClientes[], int tamClientes, int id);
int ModificarCliente(eCliente listaClientes[],eLocalidad listaLocalidad[],int tamLocalidad, int tamClientes, int id);

#endif /* CLIENTE_H_ */
