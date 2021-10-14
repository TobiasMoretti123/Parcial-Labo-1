#include "Pedido.h"
/// \fn int CrearPedido(ePedido[], eAuxiliar[], int, int, int)
/// \brief luego de que el usuario ingrese un id valida
///        crea un pedido y pregunta por los kilos totales de dicho pedido
///        siempre y cuando alla lugar para pedidos
/// \param listaPedidos La lista de pedidos a ser creada
/// \param listaAuxiliar La lista de auxiliares para guardar la cantidad de kilos y cantidad de pedidos
/// \param tamPedidos El tamaño de la lista de pedidos
/// \param tamAuxiliar El tamaño de la lista de auxiliares
/// \param id El id auxiliar que ingresa el usuario
/// \return -1 si no encontro el cliente 0 si el pedido fue ingresado correctamente
int CrearPedido(ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		int tamPedidos, int tamAuxiliar, int id) {
	int retorno;
	int index;
	float auxKilos;
	int cantidadPedidos;
	int respuestaKilos;
	cantidadPedidos = 1;
	retorno = -1;
	index = BuscarEspacioVacioPedidos(listaPedidos, tamPedidos);
	respuestaKilos = utn_getFloat(&auxKilos, 20,
			"Ingrese cantidad de kilos totales a recolectar: ",
			"Cantidad invalida ", 0, 200000, 4, 0);
	if (index != -1 && respuestaKilos == 1) {
		listaPedidos[index].idPedido = GenerarIdPedido();
		listaPedidos[index].idCliente = id;
		listaPedidos[index].estado = PENDIENTE;
		listaAuxiliar[index].idPedido = listaPedidos[index].idPedido;
		listaAuxiliar[index].kilos = auxKilos;
		listaAuxiliar[index].cantidad = cantidadPedidos;
		listaPedidos[index].isEmpty = FULL;
		listaAuxiliar[index].isEmpty = FULL;
		retorno = 0;
	}
	return retorno;
}
/// \fn int GenerarIdPedido()
/// \brief Genera un id unico para el pedido empezando del 1000
/// \return El id generado o contador
int GenerarIdPedido() {
	static int contador = 999;
	contador++;
	return contador;
}
/// \fn int InicializarPedidos(ePedido[], eAuxiliar[], int, int)
/// \brief Inicializa la lista de pedidos y su auxiliar utilizando la funcion logica isEmpty
/// \param listaPedidos la lista de pedidos a ser inicializada
/// \param listaAuxiliar la lista de auxiliares a ser inicializada
/// \param tamPedidos El tamaño de la lista de pedidos
/// \param tamAuxiliar El tamaño de la lista de auxiliares
/// \return
int InicializarPedidos(ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		int tamPedidos, int tamAuxiliar) {
	int retorno;
	retorno = -1;
	if (tamPedidos > 0) {
		for (int i = 0; i < tamPedidos; i++) {
			listaPedidos[i].isEmpty = EMPTY;
			listaAuxiliar[i].isEmpty = EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int BuscarEspacioVacioPedidos(ePedido[], int)
/// \brief Busca un espacio vacio en la lista de pedidos utilizando la funcion logica isEmpty
/// \param listaPedidos La lista de pedidos a ser buscada
/// \param tamPedidos El tamaño de la lista de pedidos
/// \return La posicion donde se encontro el espacio vacio o -1 si no se encontro
int BuscarEspacioVacioPedidos(ePedido listaPedidos[], int tamPedidos) {
	int retorno;
	retorno = -1;
	for (int i = 0; i < tamPedidos; i++) {
		if (listaPedidos[i].isEmpty == EMPTY) {
			retorno = i;
			break;
		}
	}
	return retorno;
}
/// \fn int ImprimirPedidos(ePedido[], eAuxiliar[], int, int)
/// \brief Imprime el pedido junto a su auxiliar
/// \param listaPedido la lista de pedidos a ser impresa
/// \param listaAuxiliar la lista de auxiliares a ser impresa
/// \param tamPedidos El tamaño de la lista de pedidos
/// \param tamAuxiliar El tamaño de la lista de auxiliares
/// \return 0 si la lista esta vacia 1 si no lo esta
int ImprimirPedidos(ePedido listaPedido[], eAuxiliar listaAuxiliar[],
		int tamPedidos, int tamAuxiliar) {
	int banderaListaVacia;
	banderaListaVacia = 0;
	printf("ID   CANTIDAD KILOS\n");
	for (int i = 0; i < tamPedidos; i++) {
		for (int j = 0; j < tamAuxiliar; j++) {
			if (listaPedido[i].isEmpty == FULL
					&& listaAuxiliar[j].isEmpty == FULL
					&& listaPedido[i].estado == PENDIENTE) {
				MostrarPedidos(listaPedido[i], listaAuxiliar[j]);
				banderaListaVacia = 1;
			}
		}
	}
	return banderaListaVacia;
}
/// \fn void MostrarPedidos(ePedido, eAuxiliar)
/// \brief Muestra un pedido con su auxiliar
/// \param unPedido pedido a mostrar
/// \param unAuxiliar auxiliar a mostrar
void MostrarPedidos(ePedido unPedido, eAuxiliar unAuxiliar) {
	if (unAuxiliar.idPedido == unPedido.idPedido) {
		printf("%-4d %-7.2f\n", unPedido.idPedido, unAuxiliar.kilos);
	}
}
/// \fn int ProcesarResiduos(ePedido[], eAuxiliar[], eTipo[], int, int, int, int)
/// \brief Procesa el pedido preguntando por su id, luego el usuario ingresa una cantidad de kilos y de que tipo
///        finalmente marca el pedido como completado
/// \param listaPedidos La lista de pedidos a ser procesada
/// \param listaAuxiliar La lista de auxiliares a ser procesada
/// \param listaTipos la lista de tipos a ser procesada
/// \param tamTipo El tamaño de la lista de tipos
/// \param tamPedidos El tamaño de la lista de pedidos
/// \param tamAuxiliar El tamaño de la lista de auxiliares
/// \param id el id que ingresa el usuario para comparar
/// \return -1 si hubo algun error o no encontro el usuario 0 si se proceso correctamente
int ProcesarResiduos(ePedido listaPedidos[], eAuxiliar listaAuxiliar[],
		eTipo listaTipos[], int tamTipo, int tamPedidos, int tamAuxiliar,
		int id) {
	int retorno;
	int index;
	int respuesta;
	float auxKilos;
	retorno = -1;
	index = BuscarIdPedidos(listaPedidos, tamPedidos, id);
	if (index != -1 && listaPedidos[index].estado == PENDIENTE) {
		for (int i = 0; i < tamTipo; i++) {
			utn_getFloat(&auxKilos, 20, "Ingrese cantidad de kilos: ",
					"Cantidad invalida ", 0, listaAuxiliar[index].kilos, 4, 0);
			utn_getInt(&respuesta, 2,
					"Ingrese de que tipo 1.HDPE 2.LDPE 3.PP: ",
					"Tipo invalido ", 1, 3, 4, 0);
			if (listaTipos[i].idTipo == respuesta) {
				listaTipos[i].kilos += auxKilos;
				listaTipos[i].idPedido = id;
				listaPedidos[index].estado = COMPLETADO;
				retorno = 0;
			}
		}
		printf("El resto a sido desechado\n");
	}
	return retorno;
}
/// \fn int BuscarIdPedidos(ePedido[], int, int)
/// \brief Busca el id de pedidos comparandolo con un id auxiliar
/// \param listaPedidos La lista a ser buscada
/// \param tamPedidos El tamaño de la lista
/// \param id el id auxiliar a ser comparado
/// \return -1 si no lo encontro o la posicion donde fue encontrada
int BuscarIdPedidos(ePedido listaPedidos[], int tamPedidos, int id) {
	int index;
	index = -1;
	for (int i = 0; i < tamPedidos; i++) {
		if (listaPedidos[i].idPedido == id) {
			index = i;
		}
	}
	return index;
}

