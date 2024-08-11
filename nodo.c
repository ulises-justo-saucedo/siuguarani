#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo {
    DatoPtr dato;
    struct Nodo * siguiente;
};

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->siguiente = siguiente;
    return nodo;
};

NodoPtr crearNodoVacio(){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));
    return nodo;
};

void liberarNodo(NodoPtr nodo){
    free(nodo);
};

DatoPtr getDato(NodoPtr n){
    return n->dato;
};

NodoPtr getSiguiente(NodoPtr n){
    return n->siguiente;
};

void setDato(NodoPtr n, DatoPtr nuevoDato){
    n->dato = nuevoDato;
};

void setSiguiente(NodoPtr n, NodoPtr siguiente){
    n->siguiente = siguiente;
};
