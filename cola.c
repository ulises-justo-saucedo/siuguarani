#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "nodo.h"
#include "cola.h"
#include "lista.h"
#include "alumno.h"
struct Cola{
    NodoPtr primero;
    NodoPtr ultimo;
};

NodoPtr getUltimoCola(ColaPtr cola){
    return cola->ultimo;
};
NodoPtr getPrimeroCola(ColaPtr cola){
    return cola->primero;
};
void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo){
    cola->ultimo = nuevoUltimo;
};
void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero){
    cola->primero = nuevoPrimero;
};

ColaPtr crearCola(){
    ColaPtr c = (ColaPtr) malloc(sizeof(struct Cola));
    c->primero = NULL;
    c->ultimo = NULL;
    return c;
};

void insertarUltimoCola(ColaPtr cola, DatoPtr dato){
    NodoPtr n = crearNodo(dato, NULL);
    if(cola->primero == NULL && cola->ultimo == NULL){
        cola->primero = n;
        cola->ultimo = n;
    }else if(cola->primero == cola->ultimo){
        setSiguiente(cola->primero, n);
        cola->ultimo = n;
    }else{
        setSiguiente(cola->ultimo, n);
        cola->ultimo = n;
    }
}; ///ENCOLAR - ENQUEUE

DatoPtr eliminarPrimeroCola(ColaPtr cola){
    DatoPtr datoLiberado = NULL;
    if(cola->primero == cola->ultimo && cola->primero != NULL){
        NodoPtr aux = cola->primero;
        datoLiberado = getDato(aux);
        cola->primero = NULL;
        cola->ultimo = NULL;
        liberarNodo(aux);
    }else if(cola->primero != NULL){
        NodoPtr aux = cola->primero;
        datoLiberado = getDato(aux);
        cola->primero = getSiguiente(cola->primero);
        liberarNodo(aux);
    }
    return datoLiberado;
}; ///DESENCOLAR - DEQUEUE

void ordenarCola(ColaPtr cola, int(*funcionComparar)(DatoPtr, DatoPtr)){
    ListaPtr listaAux = crearLista();
    DatoPtr datoDesencolado = eliminarPrimeroCola(cola);
    while(datoDesencolado != NULL){
        insertarPrimero(listaAux, datoDesencolado);
        datoDesencolado = eliminarPrimeroCola(cola);
    }
    ordenarListaBurbujeo(listaAux, funcionComparar);
    NodoPtr actual = getPrimero(listaAux);
    while(actual != NULL){
        insertarUltimoCola(cola, getDato(actual));
        actual = getSiguiente(actual);
    }
    liberarLista(listaAux);
};

ColaPtr duplicarCola(ColaPtr cola){
    ColaPtr auxiliar = crearCola();
    ColaPtr duplicada = crearCola();
    while(cola->primero != NULL){
        insertarUltimoCola(auxiliar, eliminarPrimeroCola(cola));
    }
    while(auxiliar->primero != NULL){
        DatoPtr dato = eliminarPrimeroCola(auxiliar);
        insertarUltimoCola(cola, dato);
        insertarUltimoCola(duplicada, dato);
    }
    liberarCola(auxiliar);
    return duplicada;
};//tarea

void liberarCola(ColaPtr cola){
    while(cola->primero != NULL){
        eliminarPrimeroCola(cola);
    }
    free(cola);
};
