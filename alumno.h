#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdbool.h>
#include "materiaAprobada.h"

struct AlumnoE;
typedef struct AlumnoE * AlumnoPtr;

AlumnoPtr crearAlumno(int dni);

void mostrarAlumno(AlumnoPtr a);

void agregarMateriaAprobada(AlumnoPtr a, int codigo, char nombre[TAM_NOMBRE_MATERIA], int nota);

void calcularPromedio(AlumnoPtr a);

bool compararAlumnos(AlumnoPtr a1, AlumnoPtr a2);

int getDniAlumno(AlumnoPtr a);
void setDniAlumno(AlumnoPtr a, int nuevoDni);

float getPromedioAlumno(AlumnoPtr a);
void setPromedioAlumno(AlumnoPtr a, float nuevoPromedio);

int getCantidadMateriasAprobadasAlumno(AlumnoPtr a);
void setCantidadMateriasAprobadasAlumno(AlumnoPtr a, int nuevaCantidad);

void liberarAlumno(AlumnoPtr a);

#endif // ALUMNO_H_INCLUDED
