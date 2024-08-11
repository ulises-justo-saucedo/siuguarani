#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#include "nodo.h"
struct Lista{
    NodoPtr primero;
};

ListaPtr crearLista(){
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));
    lista->primero = NULL;
    return lista;
};

void insertarPrimero(ListaPtr lista, DatoPtr dato){
    NodoPtr nuevoNodo = crearNodo(dato, NULL);
    if(lista->primero != NULL){
        setSiguiente(nuevoNodo, lista->primero);
    }
    lista->primero = nuevoNodo;
};

void insertarUltimo(ListaPtr lista, DatoPtr dato){
    NodoPtr actual = lista->primero;
    while(getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }
    setSiguiente(actual, crearNodo(dato, NULL));
}; //tarea

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){
    bool posicionEsValida = true;
    if(posicion < 0){
        posicionEsValida = false;
        printf("ERROR: No se puede insertar el dato en una posicion negativa");
    }
    if(posicion > obtenerTamanio(lista)+1){
        posicionEsValida = false;
        printf("ERROR: No se púede insertar el dato en una posicion inexistente");
    }
    if(posicion == 0){
        posicionEsValida = false;
        insertarPrimero(lista, dato);
    }
    if(posicion == obtenerTamanio(lista) + 1){
        posicionEsValida = false;
        insertarUltimo(lista, dato);
    }
    if(posicionEsValida){
        int i = 0;
        NodoPtr nodoPrimero = lista->primero;
        while(i != posicion - 1){
            nodoPrimero = getSiguiente(nodoPrimero);
            i++;
        }
        NodoPtr nodoSegundo = getSiguiente(nodoPrimero);
        NodoPtr nuevoNodo = crearNodo(dato, nodoSegundo);
        setSiguiente(nodoPrimero, nuevoNodo);
    }
}; //tarea

DatoPtr obtenerPrimero(ListaPtr lista){
    return getDato(lista->primero);
}; //tarea
DatoPtr obtenerUltimo(ListaPtr lista){
    NodoPtr ultimo = lista->primero;
    while(getSiguiente(ultimo) != NULL){
        ultimo = getSiguiente(ultimo);
    }
    return getDato(ultimo);
}; //tarea
DatoPtr obtenerPosicion(ListaPtr lista, int posicion){
    bool posicionEsValida = true;
    DatoPtr dato = NULL;
    if(posicion <= 0){
        posicionEsValida = false;
        printf("ERROR: No puede obtenerse un dato de una posicion negativa");
    }
    if(posicion >= obtenerTamanio(lista) + 1){
        posicionEsValida = false;
        printf("ERROR: No puede obtenerse un dato de una posicion inexistente");
    }
    if(posicion == 1){
        posicionEsValida = false;
        dato = obtenerPrimero(lista);
    }
    if(posicion == obtenerTamanio(lista)){
        posicionEsValida = false;
        dato = obtenerUltimo(lista);
    }
    if(posicionEsValida){
        NodoPtr nodoSolicitado = lista->primero;
        for(int i = 0 ; i < posicion ; i++){
            nodoSolicitado = getSiguiente(nodoSolicitado);
        }
        dato = getDato(nodoSolicitado);
    }
    return dato;
}; //tarea

int eliminarPrimero(ListaPtr lista){
    NodoPtr primerNodo = lista->primero;
    lista->primero = getSiguiente(primerNodo);
    liberarNodo(primerNodo);
    return 0;
};

int eliminarUltimo(ListaPtr lista){
    int t = obtenerTamanio(lista);
    int i = 1;
    NodoPtr penultimoNodo = lista->primero;
    while(i != t - 1){
        penultimoNodo = getSiguiente(penultimoNodo);
        i++;
    }
    liberarNodo(getSiguiente(penultimoNodo));
    setSiguiente(penultimoNodo, NULL);
    return 0;
}; //tarea

int eliminarPosicion(ListaPtr lista, int posicion){
    bool posicionEsValida = true;
    if(posicion <= 0){
        posicionEsValida = false;
        printf("ERROR: No puede eliminarse un nodo de posicion negativa");
    }
    if(posicion >= obtenerTamanio(lista) + 1){
        posicionEsValida = false;
        printf("ERROR: No puede eliminarse un nodo de posicion inexistente");
    }
    if(posicion == 1){
        posicionEsValida = false;
        eliminarPrimero(lista);
    }
    if(posicion == obtenerTamanio(lista)){
        posicionEsValida = false;
        eliminarUltimo(lista);
    }
    if(posicionEsValida){
        NodoPtr nodoAnteriorAlSolicitado = lista->primero;
        for(int i = 0 ; i < posicion - 1 ; i++){
            nodoAnteriorAlSolicitado = getSiguiente(nodoAnteriorAlSolicitado);
        }
        NodoPtr nodoSolicitado = getSiguiente(nodoAnteriorAlSolicitado);
        setSiguiente(getSiguiente(nodoAnteriorAlSolicitado), getSiguiente(nodoSolicitado));
        setSiguiente(nodoSolicitado, NULL);
        liberarNodo(nodoSolicitado);
    }
    return 0;
}; //tarea

int obtenerTamanio(ListaPtr lista){
    int t = 0;
    NodoPtr actual = lista->primero;
    while(actual != NULL){
        t++;
        actual = getSiguiente(actual);
    }
    return t;
}; //tarea

///-----------------------------------------------
void ordenarListaBurbujeo(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){
    NodoPtr actual;
    DatoPtr aux;
    int t = obtenerTamanio(lista);
    for(int i = 0 ; i < t ; i++){
        actual = lista->primero;
        for(int j = 0 ; j < t - 1 ; j++){
            if((*funcionComparar)(getDato(actual), getDato(getSiguiente(actual)))){
                aux = getDato(actual);
                setDato(actual, getDato(getSiguiente(actual)));
                setDato(getSiguiente(actual), aux);
            }
            actual = getSiguiente(actual);
        }
    }
};
NodoPtr getNodoPos(ListaPtr lista, int pos){
    NodoPtr actual = lista->primero;
    for(int i = 0 ; i < pos ; i++){
        actual = getSiguiente(actual);
    }
    return actual;
};

void ordenarListaInsercion(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){
    DatoPtr actual;
    NodoPtr aux;
    int j;
    for(int i = 1 ; i < obtenerTamanio(lista) ; i++){
        actual = getDato(getNodoPos(lista, i));
        j = i - 1;
        aux = getNodoPos(lista, j);
        while(j >= 0 && (*funcionComparar)(getDato(aux), actual) == 1){
            setDato(getSiguiente(aux), getDato(aux));
            setDato(aux, actual);
            j--;
            aux = getNodoPos(lista, j);
        }
    }
};
void ordenarListaSeleccion(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){
    NodoPtr actual = lista->primero;
    NodoPtr otros;
    NodoPtr minimo;
    NodoPtr aux = crearNodoVacio();
    int t = obtenerTamanio(lista);
    while(actual != NULL){
        minimo = actual;
        otros = getSiguiente(actual);
        while(otros != NULL){
            if((*funcionComparar)(getDato(minimo), getDato(otros)) == 1) minimo = otros;
            otros = getSiguiente(otros);
        }
        setDato(aux, getDato(actual));
        setDato(actual, getDato(minimo));
        setDato(minimo, getDato(aux));
        actual = getSiguiente(actual);
    }
    liberarNodo(aux);
};

ListaPtr ordenarListaCopia(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){
    ListaPtr duplicada = duplicarLista(lista);
    ordenarListaInsercion(duplicada, funcionComparar);
    return duplicada;
};
///-----------------------------------------------
ListaPtr duplicarLista(ListaPtr lista){
    ListaPtr duplicada = crearLista();
    NodoPtr nodoListaOriginal = lista->primero;
    NodoPtr nodoListaDuplicada = crearNodoVacio();
    int t = obtenerTamanio(lista);
    for(int i = 0 ; i < t ; i++){
        NodoPtr nodo = crearNodoVacio();
        if(i == 0){
            setDato(nodo, getDato(nodoListaOriginal));
            setSiguiente(nodo, NULL);
            setSiguiente(nodoListaDuplicada, nodo);
            nodoListaDuplicada = nodo;
            duplicada->primero = nodoListaDuplicada;
        }else{
            setDato(nodo, getDato(nodoListaOriginal));
            setSiguiente(nodo, NULL);
            setSiguiente(nodoListaDuplicada, nodo);
            nodoListaDuplicada = nodo;
        }
        nodoListaOriginal = getSiguiente(nodoListaOriginal);
    }
    return duplicada;
};//tarea

int busquedaSecuencial(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr)){
    bool datoEncontrado = false;
    int i = 0;
    NodoPtr nodo = lista->primero;
    int posicionEncontrada = -1;
    int t = obtenerTamanio(lista);
    while(!datoEncontrado && i < t){
        if((*funcionComparar)(getDato(nodo), datoBuscado) == 2){
            datoEncontrado = true;
            posicionEncontrada = i;
        }
        i++;
        nodo = getSiguiente(nodo);
    }
    return posicionEncontrada;
};
int busquedaBinaria(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr)){
    int pos = -1;
    if(laListaEstaOrdenada(lista, funcionComparar)){
        NodoPtr actual = lista->primero;
        int bordeInferior, bordeSuperior, mitad, i;
        bordeInferior = 0;
        bordeSuperior = obtenerTamanio(lista);
        i = 0;
        bool encontrado = false;
        while(!encontrado && bordeInferior <= bordeSuperior){
            mitad = (bordeSuperior + bordeInferior) / 2;
            switch((*funcionComparar)(getDato(actual), datoBuscado)){
            case 0:
                encontrado = true;
                pos = i;
                break;
            case 1:
                bordeSuperior = mitad;
                mitad = (bordeSuperior + bordeInferior) / 2;
                break;
            case -1:
                bordeInferior = mitad;
                mitad = (bordeSuperior + bordeInferior) / 2;
                break;
            }
            i++;
            actual = getSiguiente(actual);
        }
    }
    return pos;
};

bool laListaEstaOrdenada(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){
    bool estaOrdenada = true;
    int i = 0;
    NodoPtr actual = lista->primero;
    int t = obtenerTamanio(lista);
    while(estaOrdenada && i < t - 1){
        if((*funcionComparar)(getDato(actual), getDato(getSiguiente(actual))) == 1){
        //if(getDato(actual) > getDato(getSiguiente(actual))){
            estaOrdenada = false;
        }
        actual = getSiguiente(actual);
        i++;
    }
    return estaOrdenada;
};

void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*funcionComparar)(DatoPtr, DatoPtr)){
    bool estaOrdenada = laListaEstaOrdenada(lista, funcionComparar);
    if(estaOrdenada){
        bool insertado = false;
        if((*funcionComparar)(obtenerPrimero(lista), dato) == 1){
        //if(obtenerPrimero(lista) > dato){
            insertarPrimero(lista, dato);
            insertado = true;
        }
        if((*funcionComparar)(dato, obtenerUltimo(lista)) == 1){
        //if(obtenerUltimo(lista) < dato){
            insertarUltimo(lista, dato);
            insertado = true;
        }
        if(!insertado){
            NodoPtr nodo = lista->primero;
            int j = 0;
            while(!insertado){
                if((*funcionComparar)(getDato(nodo), dato) == 1){
                //if(getDato(nodo) > dato){
                    insertarPosicion(lista, dato, j);
                    insertado = true;
                }
                nodo = getSiguiente(nodo);
                j++;
            }
        }
    }else{
        printf("ERROR: No se puede insertar de manera ordenada el dato en una lista desordenada");
    }
};

void mostrarListaGenerica(ListaPtr lista, void (*funcionMostrar)(DatoPtr)){
    ///printf("--- Mostrando lista de TAM = %d ---\n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;
    while(actual != NULL){
        (*funcionMostrar)(getDato(actual));
        actual = getSiguiente(actual);
        printf("\n");
    }
};

void liberarLista(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    NodoPtr aux;
    while (actual!=NULL){
        aux = actual;
        free(actual);
        actual = getSiguiente(aux);
    };
    free(lista);
}

NodoPtr getPrimero(ListaPtr l){
    return l->primero;
};

void setPrimero(ListaPtr l, NodoPtr primero){
    l->primero = primero;
};
