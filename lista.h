#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
#include <stdbool.h>

struct Lista;

typedef struct Lista * ListaPtr;

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

int eliminarPrimero(ListaPtr lista);
int eliminarUltimo(ListaPtr lista);
int eliminarposicicon(ListaPtr lista);

int obtenerTamanio(ListaPtr lista);

void ordenarListaBurbujeo(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));
void ordenarListaInsercion(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));
void ordenarListaSeleccion(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));
ListaPtr ordenarListaCopia(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));
ListaPtr duplicarLista(ListaPtr lista);

NodoPtr getNodoPos(ListaPtr lista, int pos);

int busquedaSecuencial(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr));
int busquedaBinaria(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr));

bool laListaEstaOrdenada(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));

void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*funcionComparar)(DatoPtr, DatoPtr));

void mostrarListaGenerica(ListaPtr lista, void (*funcionMostrar)(DatoPtr));

void liberarLista(ListaPtr lista);

NodoPtr getPrimero(ListaPtr l);
void setPrimero(ListaPtr l, NodoPtr primero);

#endif // LISTA_H_INCLUDED
