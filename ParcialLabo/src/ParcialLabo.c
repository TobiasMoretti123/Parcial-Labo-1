/*
 Tobias Nahuel Moretti
 DNI: 41668744
 Una empresa de recolecci�n y reciclado de pl�sticos requiere un sistema que les permita administrar sus clientes y pedidos de recolecci�n. El programa contar� con el siguiente men�:
 1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit direcci�n y localidad. Se generar� un ID �nico para este cliente que se imprimir� por pantalla si el alta es correcta.
 2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitir� cambiar la direcci�n y la localidad.
 3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntar� si se quiere confirmar la eliminaci�n.
 4) Crear pedido de recolecci�n: Se imprimir�n los clientes por pantalla y se pedir� que se ingrese el ID de un cliente existente y la cantidad de kilos totales que se recolectar�n del cliente. Se generar� un ID para el pedido y el mismo quedar� en estado �Pendiente� hasta que se obtengan los residuos del cliente y se trasladen a la empresa.
 5) Procesar residuos: Se elegir� esta opci�n cuando los residuos que volvieron a la empresa se hayan procesado y separado en los diferentes tipos de pl�stico que la empresa puede reciclar. Se imprimir�n los pedidos por pantalla y se pedir� seleccionar el ID de uno de ellos. Luego deber�n ingresarse la cantidad de kilos de pl�stico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que se recolectaron. Por �ltimo, se marcar� al pedido como �Completado�.
 6) Imprimir Clientes: Se imprimir� una lista de clientes con todos sus datos junto con la cantidad de �pedidos de recolecci�n� que posee en estado �Pendiente�.
 7) Imprimir Pedidos pendientes: Se imprimir� una lista de los pedidos que se encuentren en estado �Pendiente� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos a recolectar.
 8) Imprimir Pedidos procesados: Se imprimir� una lista de los pedidos que se encuentren en estado �Completado� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos reciclados de cada tipo de pl�stico.
 9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
 10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Informes.h"
#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMAUXILIAR 1000
#define TAMLOCALIDAD 100
#define TAMTIPOS 3
#define OPCIONES 11

int main(void) {
	setbuf(stdout, NULL);
	eCliente listaClientes[TAMCLIENTES];
	eLocalidad listaLocalidades[TAMLOCALIDAD];
	ePedido listaPedidos[TAMPEDIDOS];
	eAuxiliar listaAuxiliar[TAMAUXILIAR];
	eTipo listaTipos[TAMTIPOS] = { { 1, 0, "HDPE", 0 }, { 2, 0, "LDPE", 0 }, {
			3, 0, "PP", 0 } };
	MenuDeOpciones(listaClientes, listaLocalidades, listaTipos, TAMTIPOS,
	TAMLOCALIDAD, listaPedidos, listaAuxiliar, TAMPEDIDOS, TAMAUXILIAR,
	TAMCLIENTES, OPCIONES);

	return EXIT_SUCCESS;
}
