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

void MenuDeOpciones(eCliente listaClientes[], eLocalidad listaLocalidad[],
		eTipo listaTipos[], int tamTipos, int tamLocalidad,
		ePedido listaPedidos[], eAuxiliar listaAuxiliar[], int tamPedidos,
		int tamAuxiliar, int tamClientes, int opciones);
int ImprimirPedidosPendientes(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes);
void MostrarClientePedido(eCliente unCliente, eAuxiliar unAuxiliar,
		ePedido unPedido);
int ImprimirPedidosProcesados(eCliente listaClientes[], ePedido listaPedidos[],
		eTipo listaTipos[], int tamPedidos, int tamClientes, int tamTipos);
void MostrarPedidosProcesados(eCliente unCliente, eTipo unTipo,
		ePedido unPedido);
int ImprimirCantidadPendientes(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes);
int ImprimirLocalidades(eCliente listaClientes[], ePedido listaPedidos[],
		eLocalidad listaLocalidad[], int tamLocalidad, int tamClientes,
		int tamPedidos);
int CantidadPedientesPorLocalidad(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes);
int KilosPromedioPorCliente(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes, int cantidadClientes);
int ClienteConMasPedidos(eCliente listaClientes[], eLocalidad listaLocalidad[],
		int tamLocalidad, ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		int tamPedidos, int tamAuxiliar, int tamClientes, int *masCantidad);
int ClienteConMasPedidosProcesados(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes, int *masCantidad);
int ClienteConMasPedidosPendientes(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes, int *masCantidad);

#endif /* INFORMES_H_ */
