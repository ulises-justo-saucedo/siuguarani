#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materiaAprobada.h"

struct MateriaAprobadaE{
    InformacionMateriaPtr informacion;
    int nota;
};

MateriaAprobadaPtr crearMateriaAprobada(int codigo, char nombre[TAM_NOMBRE_MATERIA], int nota){
    MateriaAprobadaPtr m = (MateriaAprobadaPtr) malloc(sizeof(struct MateriaAprobadaE));
    m->informacion = crearInformacionMateria(codigo, nombre);
    m->nota = nota;
    return m;
};

void mostrarMateriaAprobada(MateriaAprobadaPtr m){
    mostrarInformacionMateria(m->informacion);
    printf(" NOTA (%d)", m->nota);
};

int getNotaMateriaAprobada(MateriaAprobadaPtr m){
    return m->nota;
};
void setNotaMateriaAprobada(MateriaAprobadaPtr m, int nuevaNota){
    m->nota = nuevaNota;
};

void liberarMateriaAprobada(MateriaAprobadaPtr m){
    free(m);
};
