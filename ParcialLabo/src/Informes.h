#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INFORMES_H_
#define INFORMES_H_
#define EMPTY 0
#define FULL 1
#define PENDIENTE 0
#define COMPLETADO 1
#include "Pedido.h"
#include "Cliente.h"
#include "utn.h"
#include "validaciones.h"

void MenuDeOpciones(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], eTipo listaTipos[], int tamPedidos,
		int tamAuxiliar, int tamClientes, int tamTipos, int opciones);
int ImprimirPedidosPendientes(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes);
void MostrarClientePedido(eCliente unCliente, eAuxiliar unAuxiliar,
		ePedido unPedido);
int ImprimirPedidosProcesados(eCliente listaClientes[], ePedido listaPedidos[],
		eTipo listaTipos[], int tamPedidos, int tamClientes, int tamTipos);
void MostrarPedidosProcesados(eCliente unCliente, eTipo unTipo,
		ePedido unPedido);
int ImprimirCantidadPendientes(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes);
int ImprimirLocalidades(eCliente listaClientes[], int tamClientes);
int CantidadPedientesPorLocalidad(eCliente listaClientes[],
		ePedido listaPedidos[], eAuxiliar listaAuxiliar[], int tamPedidos,
		int tamAuxiliar, int tamClientes);
int KilosPromedioPorCliente(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes, int cantidadClientes);

#endif /* INFORMES_H_ */
