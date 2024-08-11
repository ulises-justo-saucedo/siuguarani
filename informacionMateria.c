#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informacionMateria.h"

struct InformacionMateriaE{
    int codigo;
    char nombre[TAM_NOMBRE_MATERIA];
};

InformacionMateriaPtr crearInformacionMateria(int codigo, char nombre[TAM_NOMBRE_MATERIA]){
    InformacionMateriaPtr i = (InformacionMateriaPtr) malloc(sizeof(struct InformacionMateriaE));
    i->codigo = codigo;
    strcpy(i->nombre, nombre);
    return i;
};

void mostrarInformacionMateria(InformacionMateriaPtr i){
    printf("\t%s#%d", i->nombre, i->codigo);
};

int getCodigoInformacionMateria(InformacionMateriaPtr i){
    return i->codigo;
};
void setCodigoInformacionMateria(InformacionMateriaPtr i, int nuevoCodigo){
    i->codigo = nuevoCodigo;
};

char* getNombreInformacionMateria(InformacionMateriaPtr i){
    return i->nombre;
};
void setNombreInformacionMateria(InformacionMateriaPtr i, char nuevoNombre[TAM_NOMBRE_MATERIA]){
    strcpy(i->nombre, nuevoNombre);
};

void liberarInformacionMateria(InformacionMateriaPtr i){
    free(i);
};
