#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include "informacionMateria.h"
#include "lista.h"
#include "cola.h"
#include "materia.h"
#include "nodo.h"
#include "alumno.h"

struct MateriaE;
typedef struct MateriaE * MateriaPtr;

MateriaPtr crearMateria(int codigo, char nombre[TAM_NOMBRE_MATERIA], int cupo);

void mostrarMateria(MateriaPtr m);

void agregarAlumnoInscriptoMateria(MateriaPtr m, AlumnoPtr a);

ListaPtr getAlumnosInscriptosMateria(MateriaPtr m);
void setAlumnosInscriptosMateria(MateriaPtr m, ListaPtr nuevosAlumnosInscriptos);

ColaPtr getAlumnosEnEspera(MateriaPtr m);
void setAlumnosEnEspera(MateriaPtr m, ColaPtr nuevosAlumnosEnEspera);

int getCupoMateria(MateriaPtr m);
void setCupoMateria(MateriaPtr m, int nuevoCupo);

void liberarMateria(MateriaPtr m);

#endif // MATERIA_H_INCLUDED
