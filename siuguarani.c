#include <stdio.h>
#include <stdlib.h>
#include "siuguarani.h"

struct SIUGuaraniE{
    ListaPtr materias;
};

SIUGuaraniPtr crearSIUGuarani(){
    SIUGuaraniPtr s = (SIUGuaraniPtr) malloc(sizeof(struct SIUGuaraniE));
    s->materias = crearLista();
    return s;
};

void mostrarSIUGuarani(SIUGuaraniPtr s){
    printf("\t----- SIU GUARANI -----\n");
    mostrarListaGenerica(s->materias, mostrarMateria);
};

void agregarMateriaSIUGuarani(SIUGuaraniPtr s, MateriaPtr nuevaMateria){
    insertarPrimero(s->materias, nuevaMateria);
};

ListaPtr getMateriasSIUGuarani(SIUGuaraniPtr s){
    return s->materias;
};
void setMateriasSIUGuarani(SIUGuaraniPtr s, ListaPtr nuevasMaterias){
    s->materias = nuevasMaterias;
};

void liberarSIUGuarani(SIUGuaraniPtr s){
    liberarLista(s->materias);
    free(s);
};
