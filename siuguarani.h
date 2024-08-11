#ifndef SIUGUARANI_H_INCLUDED
#define SIUGUARANI_H_INCLUDED
#include "lista.h"
#include "materia.h"

struct SIUGuaraniE;
typedef struct SIUGuaraniE * SIUGuaraniPtr;

SIUGuaraniPtr crearSIUGuarani();

void mostrarSIUGuarani(SIUGuaraniPtr s);

void agregarMateriaSIUGuarani(SIUGuaraniPtr s, MateriaPtr nuevaMateria);

ListaPtr getMateriasSIUGuarani(SIUGuaraniPtr s);
void setMateriasSIUGuarani(SIUGuaraniPtr s, ListaPtr nuevasMaterias);

void liberarSIUGuarani(SIUGuaraniPtr s);

#endif // SIUGUARANI_H_INCLUDED
