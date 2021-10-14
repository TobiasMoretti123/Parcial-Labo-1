#include "Informes.h"
#define PENDIENTE 0
#define COMPLETADO 1
#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct {
	int idPedido;
	int cantidad;
	float kilos;
	int isEmpty;
} eAuxiliar;

typedef struct {
	int idPedido;
	int idCliente;
	int estado;
	int isEmpty;
} ePedido;

typedef struct{
	int idTipo;
	int idPedido;
	char descripcion[20];
	float kilos;
}eTipo;

int CrearPedido(ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		int tamPedidos, int tamAuxiliar, int id);
int GenerarIdPedido();
int BuscarEspacioVacioPedidos(ePedido listaPedidos[], int tamPedidos);
int InicializarPedidos(ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		int tamPedidos, int tamAuxiliar);
void IngresarKilos(eTipo unTipo, int id, float maximo);
int ProcesarResiduos(ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		eTipo listaTipos[], int tamTipo, int tamPedidos, int tamAuxiliar,
		int id);
int BuscarIdPedidos(ePedido listaPedidos[], int tamPedidos, int id);
int ImprimirPedidos(ePedido listaPedido[],eAuxiliar listaAuxiliar[],int tamPedidos, int tamAuxiliar);
void MostrarPedidos(ePedido unPedido, eAuxiliar unAuxiliar);


#endif /* PEDIDO_H_ */
