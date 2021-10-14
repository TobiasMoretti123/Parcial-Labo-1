#include "Cliente.h"
/// \fn eCliente IngresarCliente()
/// \brief Ingresa un cliente, para que el usuario cargue cada valor de la estructura eCliente
/// \return Una estructura eCliente con sus datos cargados
eCliente IngresarCliente() {
	eCliente unCliente;
	char auxNombre[20];
	char auxCuit[20];
	char auxDireccion[20];
	char auxLocalidad[20];
	int respuestaNombre;
	int respuestaCuit;
	int respuestaDireccion;
	int respuestaLocalidad;

	respuestaNombre = utn_getName(auxNombre, 20, "Ingrese nombre de empresa: ",
			"Nombre invalido ", 4);
	respuestaCuit = utn_getCuit(auxCuit, "Ingrese cuit: ", "Cuit invalido ", 4);
	respuestaDireccion = utn_getText(auxDireccion, 20, "Ingrese direccion: ",
			"Direccion invalida ", 4);
	respuestaLocalidad = utn_getText(auxLocalidad, 20, "Ingrese localidad: ",
			"Localidad invalida ", 4);
	if (respuestaCuit == 1 && respuestaDireccion == 1 && respuestaLocalidad == 1
			&& respuestaNombre == 1) {
		unCliente.idCliente = GenerarIdCliente();
		strncpy(unCliente.nombreEmpresa, auxNombre, 20);
		strncpy(unCliente.direccion, auxDireccion, 20);
		strncpy(unCliente.localidad, auxLocalidad, 20);
		strncpy(unCliente.cuit, auxCuit, 20);
		unCliente.isEmpty = FULL;
	} else {
		printf("Error en carga de cliente\n");
	}
	return unCliente;
}
/// \fn int AltaCliente(eCliente[], int)
/// \brief Da de alta un cliente, siempre y cuando alla lugar en la lista
/// 	   e imprime por pantalla su ID unico si es creado correctamente
/// \param listaClientes La lista de clientes a ser dada de alta
/// \param tamClientes El tamaño de la lista de clientes
/// \return 0 en caso de cargarse correctamente -1 si no
int AltaCliente(eCliente listaClientes[], int tamClientes) {
	int retorno;
	int index;
	index = BuscarEspacioVacio(listaClientes, tamClientes);
	retorno = -1;
	if (index != -1) {
		listaClientes[index] = IngresarCliente();
		printf("Cliente ingresado ID: %d\n", listaClientes[index].idCliente);
		retorno = 0;
	} else {
		printf("Lista llena\n");
	}
	return retorno;
}
/// \fn int BuscarIdCliente(eCliente[], int, int)
/// \brief Busca el id de un cliente comparandolo con un id auxiliar
/// \param listaClientes La lista de clientes donde el id debe ser comparada
/// \param tamClientes El tamaño de la lista de clientes
/// \param id El id auxiliar a ser comparado
/// \return La posicion donde la comparacion fue verdadera o -1 si no fue encontrado
int BuscarIdCliente(eCliente listaClientes[], int tamClientes, int id) {
	int index;
	index = -1;
	for (int i = 0; i < tamClientes; i++) {
		if (listaClientes[i].idCliente == id) {
			index = i;
		}
	}
	return index;
}
/// \fn int BajaCliente(eCliente[], int, int)
/// \brief Borra un cliente de la lista siempre y cuando el id de ese cliente exista
/// \param listaClientes La lista de clientes a ser comparada con el id auxiliar y ser borrada
/// \param tamClientes El tamaño de la lista de clientes
/// \param id El id auxiliar a ser comparado
/// \return 0 si fue dado de baja correctamente -1 si hubo algun error o fue cancelada la baja
int BajaCliente(eCliente listaClientes[], int tamClientes, int id) {
	int retorno;
	int index;
	char respuesta[3];
	retorno = -1;
	index = BuscarIdCliente(listaClientes, tamClientes, id);
	utn_getText(respuesta, 3, "Esta seguro de borrar este ID?: ",
			"Respuesta invalida ", 4);
	strlwr(respuesta);
	if (index != -1 && strcmp(respuesta, "si") == 0) {
		listaClientes[index].isEmpty = EMPTY;
		printf("Usted dio de baja el id: %d correctamente\n",
				listaClientes[index].idCliente);
		retorno = 0;
	} else {
		printf("Usted cancelo la baja\n");
	}
	return retorno;
}
/// \fn int ModificarCliente(eCliente[], int, int)
/// \brief Modifica La direccion y la localidad de un cliente
///        siempre y cuando el id exista en la lista de clientes
/// \param listaClientes La lista de clientes donde comparar el id y ser modificada
/// \param tamClientes El tamaño de la lista de clientes
/// \param id El id auxiliar a ser comparado
/// \return 0 si se modifico correctamente -1 si hubo algun error o se cancelo la modificacion
int ModificarCliente(eCliente listaClientes[], int tamClientes, int id) {
	int retorno;
	int index;
	char respuesta[3];
	char auxDireccion[20];
	char auxLocalidad[20];
	int respuestaDireccion;
	int respuestaLocalidad;
	retorno = -1;
	index = BuscarIdCliente(listaClientes, tamClientes, id);

	strlwr(respuesta);
	if (index != -1 && listaClientes[index].isEmpty == FULL) {
		respuestaDireccion = utn_getText(auxDireccion, 20,
				"Ingrese nueva direccion: ", "Direccion invalida ", 4);
		respuestaLocalidad = utn_getText(auxLocalidad, 20,
				"Ingrese nueva localidad: ", "Localidad invalida ", 4);
		printf("Nueva direccion Nueva localidad\n");
		printf("%-15s %-15s\n", auxDireccion, auxLocalidad);
		utn_getText(respuesta, 3, "Esta seguro de modificar este ID?: ",
				"Respuesta invalida ", 4);
		retorno = 0;
	}
	if (strcmp(respuesta, "si") == 0 && respuestaDireccion == 1
			&& respuestaLocalidad == 1) {
		strncpy(listaClientes[index].direccion, auxDireccion, 20);
		strncpy(listaClientes[index].localidad, auxLocalidad, 20);
		printf("Usted modifico el id: %d correctamente\n",
				listaClientes[index].idCliente);
		retorno = 0;
	} else {
		printf("Usted cancelo la modificacion\n");
	}

	return retorno;
}
/// \fn int GenerarIdCliente()
/// \brief Genera un id unico para cada cliente comenzando del 100
/// \return El id unico o contador
int GenerarIdCliente() {
	static int contador = 99;
	contador++;
	return contador;
}
/// \fn int InicializarClientes(eCliente[], int)
/// \brief Inicializa la lista de clientes en 0 utilizando el lugar en la estructura isEmpty
/// \param listaClientes La lista a ser inicializada
/// \param tamClientes El tamaño de la lista de clientes
/// \return -1 si hubo algun error 0 si se inicializo correctamente
int InicializarClientes(eCliente listaClientes[], int tamClientes) {
	int retorno;
	retorno = -1;
	if (tamClientes > 0) {
		for (int i = 0; i < tamClientes; i++) {
			listaClientes[i].isEmpty = EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int BuscarEspacioVacio(eCliente[], int)
/// \brief Busca un espacio vacio en la lista utilizando la funcion logica isEmpty
/// \param listaClientes La lista de clientes donde debe buscarse el lugar vacio
/// \param tamClientes El tamaño de la lista de clientes
/// \return La posicion donde se encontro un lugar vacio o -1 si no se encontro lugar vacio
int BuscarEspacioVacio(eCliente listaClientes[], int tamClientes) {
	int retorno;
	retorno = -1;
	for (int i = 0; i < tamClientes; i++) {
		if (listaClientes[i].isEmpty == EMPTY) {
			retorno = i;
			break;
		}
	}
	return retorno;
}
/// \fn int ImprimirClientes(eCliente[], int)
/// \brief Imprime una lista con todos los datos del cliente
/// \param listaClientes La lista a ser impresa
/// \param tamClientes El tamaño de la lista de clientes
/// \return 0 si la lista esta vacia 1 si no lo esta
int ImprimirClientes(eCliente listaClientes[], int tamClientes) {
	int banderaListaVacia;
	banderaListaVacia = 0;
	printf("ID   NOMBRE EMPRESA      CUIT        DIRECCION       LOCALIDAD\n");
	for (int i = 0; i < tamClientes; i++) {
		if (listaClientes[i].isEmpty == FULL) {
			MostrarCliente(listaClientes[i]);
			banderaListaVacia = 1;
		}
	}
	return banderaListaVacia;
}
/// \fn void MostrarCliente(eCliente)
/// \brief Muestra un cliente
/// \param unCliente El cliente a mostrar
void MostrarCliente(eCliente unCliente) {
	printf("%-4d %-15s %-15s %-15s %-15s\n", unCliente.idCliente,
			unCliente.nombreEmpresa, unCliente.cuit, unCliente.direccion,
			unCliente.localidad);
}

