#include "Informes.h"
/// \fn void MenuDeOpciones(eCliente[], ePedido[], eAuxiliar[], eTipo[], int, int, int, int, int)
/// \brief Menu con las distintas opciones del proyecto
/// \param listaClientes La lista de clientes donde utilizar las funciones
/// \param listaPedidos la lista de pedidos donde utilizar las funciones
/// \param listaAuxiliar la lista de auxiliares donde utilizar las funciones
/// \param listaTipos la lista de tipos donde utilizar las funciones
/// \param tamPedidos el tamaño de la lista de pedidos
/// \param tamAuxiliar el tamaño de la lista de auxiliares
/// \param tamClientes el tamaño de la lista de clientes
/// \param tamTipos el tamaño de la lista de tipos
/// \param opciones La cantidad de opciones que tiene el menu
void MenuDeOpciones(eCliente listaClientes[], eLocalidad listaLocalidad[],
		eTipo listaTipos[], int tamTipos, int tamLocalidad,
		ePedido listaPedidos[], eAuxiliar listaAuxiliar[], int tamPedidos,
		int tamAuxiliar, int tamClientes, int opciones) {
	int respuesta;
	int respuestaFuncion;
	int banderaClienteIngresado;
	int banderaPedidoIngresado;
	int auxId;
	int cantidadCliente;
	int masCantidad;
	int opcion2;
	banderaClienteIngresado = 0;
	banderaPedidoIngresado = 0;
	cantidadCliente = 0;
	InicializarClientes(listaClientes, tamClientes);
	InicializarPedidos(listaPedidos, listaAuxiliar, tamPedidos, tamAuxiliar);
	do {
		utn_getInt(&respuesta, 20,
				"1)Alta de cliente\n2)Modificar datos de cliente\n3)Baja de cliente\n4)Crear pedido de recolección\n5)Procesar residuos\n6)Imprimir Clientes\n7)Imprimir Pedidos pendientes\n8)Imprimir Pedidos procesados\n9)Pedidos pendientes por localidad\n10)Promedio kilos por cliente\n11)Clientes con mas pedidos\n12)Salir\nIngrese una opcion: ",
				"Opcion invalida ", 1, opciones, 4, 0);
		switch (respuesta) {
		case 1:
			respuestaFuncion = AltaCliente(listaClientes, listaLocalidad,
					tamLocalidad, tamClientes);
			if (respuestaFuncion == 0) {
				banderaClienteIngresado = 1;
				cantidadCliente = cantidadCliente + 1;
			} else {
				printf("Error en la carga de cliete\n");
			}
			break;
		case 2:
			if (banderaClienteIngresado == 1) {
				ImprimirClientes(listaClientes, listaLocalidad, tamLocalidad,
						tamClientes);
				utn_getInt(&auxId, 20,
						"De la lista ingrese el id que desee modificar: ",
						"Id invalido ", 100, 100000, 4, 0);
				respuestaFuncion = ModificarCliente(listaClientes,
						listaLocalidad, tamLocalidad, tamClientes, auxId);
				if (respuestaFuncion == -1) {
					printf(
							"Usted cancelo la modificacion o su ID no fue encontrado\n");
				}
			} else {
				printf(
						"No puede modificar un cliente si aun no ingreso alguno\n");
			}
			break;
		case 3:
			if (banderaClienteIngresado == 1) {
				ImprimirClientes(listaClientes, listaLocalidad, tamLocalidad,
						tamClientes);
				utn_getInt(&auxId, 20,
						"De la lista ingrese el id que desee dar de baja: ",
						"Id invalido ", 100, 100000, 4, 0);
				respuestaFuncion = BajaCliente(listaClientes, tamClientes,
						auxId);
				if (respuestaFuncion == -1) {
					printf("Usted cancelo la baja o el ID no fue encontrado\n");
				} else {
					cantidadCliente = cantidadCliente - 1;
				}
			} else {
				printf(
						"No puede dar de baja un cliente sin haber ingresado alguno");
			}
			break;
		case 4:
			if (banderaClienteIngresado == 1) {
				ImprimirClientes(listaClientes, listaLocalidad, tamLocalidad,
						tamClientes);
				utn_getInt(&auxId, 20, "Ingrese ID cliente: ", "Id invalido ",
						100, 100000, 4, 0);
				respuestaFuncion = BuscarIdCliente(listaClientes, tamClientes,
						auxId);
				if (respuestaFuncion != -1) {
					CrearPedido(listaPedidos, listaAuxiliar, tamPedidos,
							tamAuxiliar, auxId);
					banderaPedidoIngresado = 1;
				}
			} else {
				printf(
						"Usted no puede crear un pedido sin haber ingresado un cliente");
			}
			break;
		case 5:
			if (banderaClienteIngresado == 1 && banderaPedidoIngresado == 1) {
				ImprimirPedidos(listaPedidos, listaAuxiliar, tamPedidos,
						tamAuxiliar);
				utn_getInt(&auxId, 20, "Ingrese ID pedido: ", "Id invalido ",
						1000, 100000, 4, 0);
				ProcesarResiduos(listaPedidos, listaAuxiliar, listaTipos,
						tamTipos, tamPedidos, tamAuxiliar, auxId);

			} else {
				printf(
						"No puede procesar residuos si aun no ingreso un pedido");
			}
			break;
		case 6:
			if (banderaClienteIngresado == 1 && banderaPedidoIngresado == 1) {
				respuestaFuncion = ImprimirCantidadPendientes(listaClientes,
						listaLocalidad, tamLocalidad, listaPedidos,
						listaAuxiliar, tamPedidos, tamAuxiliar, tamClientes);
				if (respuestaFuncion == 0) {
					printf("Lista de clientes vacia\n");
				}
			} else {
				printf(
						"No puede imprimir cantidad de pedidos pendientes si no ingreso ningun pedido o cliente\n");
			}

			break;
		case 7:
			if (banderaClienteIngresado == 1 && banderaPedidoIngresado == 1) {
				respuestaFuncion = ImprimirPedidosPendientes(listaClientes,
						listaPedidos, listaAuxiliar, tamPedidos, tamAuxiliar,
						tamClientes);
				if (respuestaFuncion == 0) {
					printf("Lista vacia\n");
				}
			} else {
				printf(
						"No puede imprimir pedidos pendiente si no ingreso ningun pedido o cliente\n");
			}
			break;
		case 8:
			if (banderaClienteIngresado == 1 && banderaPedidoIngresado == 1) {
				respuestaFuncion = ImprimirPedidosProcesados(listaClientes,
						listaPedidos, listaTipos, tamPedidos, tamClientes,
						tamTipos);
				if (respuestaFuncion == 0) {
					printf("Lista de clientes vacia\n");
				}
			} else {
				printf(
						"No puede imprimir clientes procesados si no ingreso ningun cliente o pedido\n");
			}
			break;
		case 9:
			if (banderaClienteIngresado == 1 && banderaPedidoIngresado == 1) {
				respuestaFuncion = CantidadPedientesPorLocalidad(listaClientes,
						listaLocalidad, tamLocalidad, listaPedidos,
						listaAuxiliar, tamPedidos, tamAuxiliar, tamClientes);
				if (respuesta == -1) {
					printf("No se encontro esa localidad");
				}
			} else {
				printf(
						"No puede calcular cantidad de pendientes por localidad si no ingreso algun cliente o pedido\n");
			}
			break;
		case 10:
			if (banderaClienteIngresado == 1 && banderaPedidoIngresado == 1) {
				respuestaFuncion = KilosPromedioPorCliente(listaClientes,
						listaPedidos, listaAuxiliar, tamPedidos, tamAuxiliar,
						tamClientes, cantidadCliente);
				if (respuestaFuncion == -1) {
					printf("Error a calcular promedio\n");
				}
			} else {
				printf(
						"No puede calcular el promedio si no ingreso algun cliente o pedido\n");
			}
			break;
		case 11:
			utn_getInt(&opcion2, 20,
					"1)Cliente con mas pedidos pendientes\n2)Cliente con mas pedidos procesados\n3)Cliente con mas pedidos\nIngrese una opcion: ",
					"Opcion invalida ", 1, 3, 4, 0);
			switch (opcion2) {
			case 1:
				respuestaFuncion = ClienteConMasPedidosPendientes(listaClientes,
						listaLocalidad, tamLocalidad, listaPedidos,
						listaAuxiliar, tamPedidos, tamAuxiliar, tamClientes,
						&masCantidad);
				break;
			case 2:
				respuestaFuncion = ClienteConMasPedidosProcesados(listaClientes,
						listaLocalidad, tamLocalidad, listaPedidos,
						listaAuxiliar, tamPedidos, tamAuxiliar, tamClientes,
						&masCantidad);
				break;
			case 3:
				respuestaFuncion = ClienteConMasPedidos(listaClientes,
						listaLocalidad, tamLocalidad, listaPedidos,
						listaAuxiliar, tamPedidos, tamAuxiliar, tamClientes,
						&masCantidad);
				break;
			}
			break;
		case 12:
			printf("Gracias por usar nuestro servicio\n");
			break;
		}
	} while (respuesta != opciones);
}
/// \fn int ImprimirPedidosPendientes(eCliente[], ePedido[], eAuxiliar[], int, int, int)
/// \brief  Imprime una lista de pedido que esten pendientes mostrando el cuit y la direccion del cliente
///         junto con los kilos de dicho pedido
/// \param listaClientes La lista de clientes a ser impresa
/// \param listaPedidos La lista de pedidos a ser impresa
/// \param listaAuxiliar La lista de auxiliares a ser impresa
/// \param tamPedidos el tamaño de la lista de pedidos
/// \param tamAuxiliar el tamaño de la lista de auxiliares
/// \param tamClientes el tamaño de la lista de clientes
/// \return 0 si la lista esta vacia 1 si no lo esta
int ImprimirPedidosPendientes(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes) {
	int banderaListaVacia;
	banderaListaVacia = 0;
	printf("   CUIT         DIRECCION       KILOS\n");
	for (int i = 0; i < tamClientes; i++) {
		for (int j = 0; j < tamPedidos; j++) {
			for (int k = 0; k < tamAuxiliar; k++) {
				if (listaClientes[i].isEmpty == FULL
						&& listaPedidos[i].estado == PENDIENTE) {
					MostrarClientePedido(listaClientes[i], listaAuxiliar[k],
							listaPedidos[j]);
					banderaListaVacia = 1;
				}
			}
		}
	}
	return banderaListaVacia;
}
/// \fn void MostrarClientePedido(eCliente, eAuxiliar, ePedido)
/// \brief Muestra un cliente con su pedido
/// \param unCliente El cliente a ser mostrado
/// \param unAuxiliar El auxiliar a ser mostrado
/// \param unPedido el pedido a ser mostrado
void MostrarClientePedido(eCliente unCliente, eAuxiliar unAuxiliar,
		ePedido unPedido) {
	if (unCliente.idCliente == unPedido.idCliente
			&& unPedido.idPedido == unAuxiliar.idPedido) {
		printf("%-15s %-15s %-7.2f\n", unCliente.cuit, unCliente.direccion,
				unAuxiliar.kilos);
	}
}
/// \fn int ImprimirPedidosProcesados(eCliente[], ePedido[], eTipo[], int, int, int)
/// \brief Imprime una lista de pedidos procesados con el cuit y direccion de cliente
///        junto con los kilos de cada tipo
/// \param listaClientes La lista de clientes a ser impresa
/// \param listaPedidos La lista de pedidos a ser impresa
/// \param listaTipos La lista de tipos a ser impresa
/// \param tamPedidos El tamaño de la lista de pedidos
/// \param tamClientes El tamaño de la lista de clientes
/// \param tamTipos El tamaño de la lista de tipos
/// \return 0 si la lista esta vacia 1 si no lo esta
int ImprimirPedidosProcesados(eCliente listaClientes[], ePedido listaPedidos[],
		eTipo listaTipos[], int tamPedidos, int tamClientes, int tamTipos) {
	int banderaListaVacia;
	banderaListaVacia = 0;
	printf("   CUIT         DIRECCION       KILOS   TIPO\n");
	for (int i = 0; i < tamClientes; i++) {
		if (listaClientes[i].isEmpty == FULL
				&& listaPedidos[i].estado == COMPLETADO) {
			printf("%-15s %-15s\n", listaClientes[i].cuit,
					listaClientes[i].direccion);
		}
		for (int j = 0; j < tamPedidos; j++) {
			for (int k = 0; k < tamTipos; k++) {
				if (listaPedidos[j].isEmpty == FULL) {
					MostrarPedidosProcesados(listaClientes[i], listaTipos[k],
							listaPedidos[j]);
					banderaListaVacia = 1;
				}
			}
		}
	}
	return banderaListaVacia;
}
/// \fn void MostrarPedidosProcesados(eCliente, eTipo, ePedido)
/// \brief Muestra el pedido procesado
/// \param unCliente el cliente a ser mostrado
/// \param unTipo el tipo a ser mostrado
/// \param unPedido el pedido a ser mostrado
void MostrarPedidosProcesados(eCliente unCliente, eTipo unTipo,
		ePedido unPedido) {
	if (unPedido.idCliente == unCliente.idCliente
			&& unPedido.idPedido == unTipo.idPedido) {
		printf("\t\t\t\t%-7.2f %-15s\n", unTipo.kilos, unTipo.descripcion);
	}
}
/// \fn int ImprimirCantidadPendientes(eCliente[], ePedido[], eAuxiliar[], int, int, int)
/// \brief Imprime una lista con todos los datos del cliente y la cantidad de pedidos pendientes del mismo
/// \param listaClientes La lista de clientes a ser impresa
/// \param listaPedidos La lista de pedidos a ser impresa
/// \param listaAuxiliar La lista de auxiliares a ser impresa
/// \param tamPedidos el tamaño de la lista de pedidos
/// \param tamAuxiliar el tamaño de la lista de auxiliares
/// \param tamClientes el tamaño de la lista de clientes
/// \return 0 si la lista esta vacia 1 si no lo esta
int ImprimirCantidadPendientes(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes) {
	int banderaListaVacia;
	banderaListaVacia = 0;
	printf(
			"NOMBRE EMPRESA      CUIT        DIRECCION       LOCALIDAD       CANTIDAD\n");
	for (int i = 0; i < tamClientes; i++) {
		if (listaClientes[i].isEmpty == FULL
				&& listaPedidos[i].estado == PENDIENTE) {
			printf("%-15s %-15s %-15s %-15s %-3d\n",
					listaClientes[i].nombreEmpresa, listaClientes[i].cuit,
					listaClientes[i].direccion,
					listaClientes[i].unaLocalidad.descripcion,
					listaAuxiliar[i].cantidad++);
		}
	}
	return banderaListaVacia;
}
/// \fn int CantidadPedientesPorLocalidad(eCliente[], ePedido[], eAuxiliar[], int, int, int)
/// \brief Imprime una lista de localidades, luego de que el usuario igrese alguna
///        calcula los pedidos pendientes de la misma
/// \param listaClientes La lista de clientes a ser impresa
/// \param listaPedidos La lista de pedidos a ser impresa
/// \param listaAuxiliar La lista de auxiliares a ser impresa
/// \param tamPedidos el tamaño de la lista de pedidos
/// \param tamAuxiliar el tamaño de la lista de auxiliares
/// \param tamClientes el tamaño de la lista de clientes
/// \return 0 si la lista esta vacia 1 si no lo esta
int CantidadPedientesPorLocalidad(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes) {
	int retorno;
	char auxLocalidad[20];
	int respuestaLocalidad;
	retorno = -1;
	ImprimirLocalidades(listaClientes, listaPedidos, listaLocalidad,
			tamLocalidad, tamClientes, tamPedidos);
	respuestaLocalidad = utn_getText(auxLocalidad, 20,
			"Ingrese una localidad: ", "Localidad invalida ", 4);
	if (respuestaLocalidad == 1) {
		for (int i = 0; i < tamClientes; i++) {
			if (listaClientes[i].isEmpty == FULL
					&& listaPedidos[i].estado == PENDIENTE
					&& strcmp(auxLocalidad,
							listaClientes[i].unaLocalidad.descripcion) == 0) {
				printf("Pedidos pendientes para: %-15s %-3d\n",
						listaClientes[i].unaLocalidad.descripcion,
						listaAuxiliar[i].cantidad++);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/// \fn int ImprimirLocalidades(eCliente[], int)
/// \brief Imprime una lista con las localidades de los clientes
/// \param listaClientes Lista de clientes a ser impresa
/// \param tamClientes El tamaño de la lista de clientes
/// \return 0 si la lista esta vacia 1 si no lo esta
int ImprimirLocalidades(eCliente listaClientes[], ePedido listaPedidos[],
		eLocalidad listaLocalidad[], int tamLocalidad, int tamClientes,
		int tamPedidos) {
	int banderaListaVacia;
	banderaListaVacia = 0;
	for (int i = 0; i < tamClientes; i++) {
		if (listaClientes[i].isEmpty == FULL
				&& listaPedidos[i].estado == PENDIENTE) {
			printf("%-15s\n", listaClientes[i].unaLocalidad.descripcion);
		}
	}
	return banderaListaVacia;
}
/// \fn int KilosPromedioPorCliente(eCliente[], ePedido[], eAuxiliar[], int, int, int, int)
/// \brief Cacula el promedio de todos los kilos por todos los clientes
/// \param listaClientes La lista de clientes a ser impresa
/// \param listaPedidos La lista de pedidos a ser impresa
/// \param listaAuxiliar La lista de auxiliares a ser impresa
/// \param tamPedidos el tamaño de la lista de pedidos
/// \param tamAuxiliar el tamaño de la lista de auxiliares
/// \param tamClientes el tamaño de la lista de clientes
/// \return 0 si la lista esta vacia 1 si no lo esta
int KilosPromedioPorCliente(eCliente listaClientes[], ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes, int cantidadClientes) {
	int retorno;
	float acumuladorKilos;
	float promedio;
	retorno = -1;
	acumuladorKilos = 0;
	if (cantidadClientes != 0) {
		for (int i = 0; i < tamClientes; i++) {
			if (listaClientes[i].isEmpty == FULL
					&& listaAuxiliar[i].isEmpty == FULL) {
				acumuladorKilos += listaAuxiliar[i].kilos;
				listaAuxiliar[i].cantidad = cantidadClientes;
			}
		}
		promedio = acumuladorKilos / cantidadClientes;
		printf("Kilos totales por cliente: %-7.2f\n", promedio);
		retorno = 0;
	}
	return retorno;
}
int ClienteConMasPedidos(eCliente listaClientes[], eLocalidad listaLocalidad[],
		int tamLocalidad, ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		int tamPedidos, int tamAuxiliar, int tamClientes, int *masCantidad) {
	int retorno;
	retorno = -1;
	for (int i = 0; i < tamClientes; i++) {
		for (int j = 0; j < tamAuxiliar; j++) {
			if (listaClientes[i].isEmpty == FULL
					&& listaAuxiliar[i].isEmpty == FULL) {
				*masCantidad = listaAuxiliar[i].cantidad++;
				if (*masCantidad < listaAuxiliar[i].cantidad) {
					*masCantidad = listaAuxiliar[i].cantidad++;
					printf("a)\n");
					ImprimirClientes(listaClientes, listaLocalidad,
							tamLocalidad, tamClientes);
					break;
				}
			}
		}
	}
	return retorno;
}
int ClienteConMasPedidosPendientes(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes, int *masCantidad) {
	int retorno;
	retorno = -1;
	for (int i = 0; i < tamClientes; i++) {
		for (int j = 0; j < tamAuxiliar; j++) {
			if (listaClientes[i].isEmpty == FULL
					&& listaAuxiliar[i].isEmpty == FULL
					&& listaPedidos[i].estado == PENDIENTE) {
				*masCantidad = listaAuxiliar[i].cantidad++;
				if (*masCantidad < listaAuxiliar[i].cantidad) {
					*masCantidad = listaAuxiliar[i].cantidad++;
					printf("b)\n");
					ImprimirClientes(listaClientes, listaLocalidad,
							tamLocalidad, tamClientes);
					break;
				}
			}
		}
	}
	return retorno;
}
int ClienteConMasPedidosProcesados(eCliente listaClientes[],
		eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedidos[],
		eAuxiliar listaAuxiliar[], int tamPedidos, int tamAuxiliar,
		int tamClientes, int *masCantidad) {
	int retorno;
	retorno = -1;
	for (int i = 0; i < tamClientes; i++) {
		for (int j = 0; j < tamAuxiliar; j++) {
			if (listaClientes[i].isEmpty == FULL
					&& listaAuxiliar[i].isEmpty == FULL
					&& listaPedidos[i].estado == COMPLETADO) {
				*masCantidad = listaAuxiliar[i].cantidad++;
				if (*masCantidad < listaAuxiliar[i].cantidad) {
					*masCantidad = listaAuxiliar[i].cantidad++;
					printf("c)\n");
					ImprimirClientes(listaClientes, listaLocalidad,
							tamLocalidad, tamClientes);
					break;
				}
			}
		}
	}
	return retorno;
}

