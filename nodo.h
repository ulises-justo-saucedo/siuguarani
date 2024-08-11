#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);
NodoPtr crearNodoVacio();
void liberarNodo(NodoPtr nodo);
DatoPtr getDato(NodoPtr n);
NodoPtr getSiguiente(NodoPtr n);
void setDato(NodoPtr n, DatoPtr nuevoDato);
void setSiguiente(NodoPtr n, NodoPtr siguiente);

#endif // NODO_H_INCLUDED
