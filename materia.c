#include <stdio.h>
#include <stdlib.h>
#include "materia.h"
#include "alumno.h"

struct MateriaE{
    InformacionMateriaPtr informacion;
    int cupo;
    ListaPtr alumnosInscriptos;
    ColaPtr alumnosEnEspera;
};

MateriaPtr crearMateria(int codigo, char nombre[TAM_NOMBRE_MATERIA], int cupo){
    MateriaPtr m = (MateriaPtr) malloc(sizeof(struct MateriaE));
    m->informacion = crearInformacionMateria(codigo, nombre);
    m->cupo = cupo;
    m->alumnosInscriptos = crearLista();
    m->alumnosEnEspera = crearCola();
    return m;
};

void mostrarMateria(MateriaPtr m){
    printf("\t===========================\n");
    mostrarInformacionMateria(m->informacion);
    printf("\n\tCUPO: %d\n", m->cupo);
    printf("\tALUMNOS INSCRIPTOS: \n");
    if(getPrimero(m->alumnosInscriptos) != NULL){
        mostrarListaGenerica(m->alumnosInscriptos, mostrarAlumno);
    }else{
        printf("\tNo hay alumnos inscriptos.\n");
    }
    printf("\tPROXIMO ALUMNO EN ESPERA DE INSCRIBIRSE: \n");
    if(getPrimeroCola(m->alumnosEnEspera) != NULL){
        mostrarAlumno(getDato(getPrimeroCola(m->alumnosEnEspera)));
    }else{
        printf("\tNo hay alumnos en la cola de espera.\n");
    }
    printf("\t===========================\n");
};

void agregarAlumnoInscriptoMateria(MateriaPtr m, AlumnoPtr a){
    if(m->cupo != 0){
        insertarPrimero(m->alumnosInscriptos, a);
        m->cupo--;
    }else{
        insertarUltimoCola(m->alumnosEnEspera, a);
        ordenarCola(m->alumnosEnEspera, compararAlumnos);
    }
}

ListaPtr getAlumnosInscriptosMateria(MateriaPtr m){
    return m->alumnosInscriptos;
};
void setAlumnosInscriptosMateria(MateriaPtr m, ListaPtr nuevosAlumnosInscriptos){
    m->alumnosInscriptos = nuevosAlumnosInscriptos;
};

ColaPtr getAlumnosEnEspera(MateriaPtr m){
    return m->alumnosEnEspera;
};
void setAlumnosEnEspera(MateriaPtr m, ColaPtr nuevosAlumnosEnEspera){
    m->alumnosEnEspera = nuevosAlumnosEnEspera;
};

int getCupoMateria(MateriaPtr m){
    return m->cupo;
};
void setCupoMateria(MateriaPtr m, int nuevoCupo){
    m->cupo = nuevoCupo;
};

void liberarMateria(MateriaPtr m){
    liberarInformacionMateria(m->informacion);
    liberarLista(m->alumnosInscriptos);
    liberarCola(m->alumnosEnEspera);
    free(m);
};
