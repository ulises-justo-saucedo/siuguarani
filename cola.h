#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

struct Cola;

typedef struct Cola * ColaPtr;

NodoPtr getUltimoCola(ColaPtr Cola);
NodoPtr getPrimeroCola(ColaPtr Cola);
void setUltimoCola(ColaPtr Cola, NodoPtr nuevoUltimo);
void setPrimeroCola(ColaPtr Cola, NodoPtr nuevoPrimero);

ColaPtr crearCola();

void insertarUltimoCola(ColaPtr Cola, DatoPtr dato); ///ENCOLAR - ENQUEUE
DatoPtr eliminarPrimeroCola(ColaPtr Cola); ///DESENCOLAR - DEQUEUE

void ordenarCola(ColaPtr cola, int(*funcionComparar)(DatoPtr, DatoPtr));

ColaPtr duplicarCola(ColaPtr Cola);//tarea

void liberarCola(ColaPtr Cola);

#endif // COLA_H_INCLUDED
