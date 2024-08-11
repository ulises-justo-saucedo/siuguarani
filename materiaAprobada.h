#ifndef MATERIAAPROBADA_H_INCLUDED
#define MATERIAAPROBADA_H_INCLUDED
#include "informacionMateria.h"

struct MateriaAprobadaE;
typedef struct MateriaAprobadaE * MateriaAprobadaPtr;

MateriaAprobadaPtr crearMateriaAprobada(int codigo, char nombre[TAM_NOMBRE_MATERIA], int nota);

void mostrarMateriaAprobada(MateriaAprobadaPtr m);

int getNotaMateriaAprobada(MateriaAprobadaPtr m);
void setNotaMateriaAprobada(MateriaAprobadaPtr m, int nuevaNota);

void liberarMateriaAprobada(MateriaAprobadaPtr m);

#endif // MATERIAAPROBADA_H_INCLUDED
