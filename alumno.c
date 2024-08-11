#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "lista.h"
#include "materiaAprobada.h"

struct AlumnoE{
    int dni;
    float promedio;
    ListaPtr materiasAprobadas;
    int cantidadMateriasAprobadas;
};

AlumnoPtr crearAlumno(int dni){
    AlumnoPtr a = (AlumnoPtr) malloc(sizeof(struct AlumnoE));
    a->dni = dni;
    a->materiasAprobadas = crearLista();
    a->promedio = 0;
    a->cantidadMateriasAprobadas = 0;
    return a;
};

void mostrarAlumno(AlumnoPtr a){
    printf("\t-----------------------------\n");
    printf("\tALUMNO %d # PROMEDIO %.2f\n", a->dni, a->promedio);
    printf("\tMATERIAS APROBADAS (%d): \n", a->cantidadMateriasAprobadas);
    mostrarListaGenerica(a->materiasAprobadas, mostrarMateriaAprobada);
    printf("\t-----------------------------\n");
};

void agregarMateriaAprobada(AlumnoPtr a, int codigo, char nombre[TAM_NOMBRE_MATERIA], int nota){
    MateriaAprobadaPtr m = crearMateriaAprobada(codigo, nombre, nota);
    insertarPrimero(a->materiasAprobadas, m);
    a->cantidadMateriasAprobadas++;
    calcularPromedio(a);
};

void calcularPromedio(AlumnoPtr a){
    int sumaTotalDeNotas = 0;
    for(int i = 0 ; i < a->cantidadMateriasAprobadas ; i++){
        sumaTotalDeNotas += getNotaMateriaAprobada(getDato(getNodoPos(a->materiasAprobadas, i)));
    }
    a->promedio = sumaTotalDeNotas / a->cantidadMateriasAprobadas;
};

///Comparación sobre el 1er parametro
bool compararAlumnos(AlumnoPtr a1, AlumnoPtr a2){
    bool mayor = false;
    if(a1->cantidadMateriasAprobadas < a2->cantidadMateriasAprobadas){
        if(a1->promedio < a2->promedio){
            mayor = true;
        }
    }
    return mayor;
};

int getDniAlumno(AlumnoPtr a){
    return a->dni;
};
void setDniAlumno(AlumnoPtr a, int nuevoDni){
    a->dni = nuevoDni;
};

float getPromedioAlumno(AlumnoPtr a){
    return a->promedio;
};
void setPromedioAlumno(AlumnoPtr a, float nuevoPromedio){
    a->promedio = nuevoPromedio;
};

int getCantidadMateriasAprobadasAlumno(AlumnoPtr a){
    return a->cantidadMateriasAprobadas;
};
void setCantidadMateriasAprobadasAlumno(AlumnoPtr a, int nuevaCantidad){
    a->cantidadMateriasAprobadas = nuevaCantidad;
};

void liberarAlumno(AlumnoPtr a){
    free(a);
};
