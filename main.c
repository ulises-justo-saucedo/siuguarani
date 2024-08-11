#include <stdio.h>
#include <stdlib.h>
#include "materiaAprobada.h"
#include "alumno.h"
#include "materia.h"
#include "siuguarani.h"

int main()
{
    ///CREACION DE ALUMNOS CON SUS RESPECTIVAS MATERIAS APROBADAS
    AlumnoPtr a1 = crearAlumno(45072139);
    agregarMateriaAprobada(a1, 0, "Matematica I", 5);
    agregarMateriaAprobada(a1, 12, "Programacion", 7);
    agregarMateriaAprobada(a1, 90, "Matematica II", 4);

    AlumnoPtr a2 = crearAlumno(56829143);
    agregarMateriaAprobada(a2, 0, "Matematica I", 4);
    agregarMateriaAprobada(a2, 12, "Programacion", 5);
    agregarMateriaAprobada(a2, 90, "Matematica II", 5);
    agregarMateriaAprobada(a2, 92, "Matematica III", 4);

    AlumnoPtr a3 = crearAlumno(45072141);
    agregarMateriaAprobada(a3, 0, "Historia", 6);
    agregarMateriaAprobada(a3, 15, "Economia", 8);
    agregarMateriaAprobada(a3, 85, "Estadistica", 7);

    AlumnoPtr a4 = crearAlumno(45072142);
    agregarMateriaAprobada(a4, 0, "Biologia", 10);
    agregarMateriaAprobada(a4, 20, "Anatomia", 9);
    agregarMateriaAprobada(a4, 75, "Fisiologia", 6);

    AlumnoPtr a5 = crearAlumno(45072143);
    agregarMateriaAprobada(a5, 0, "Literatura", 4);
    agregarMateriaAprobada(a5, 18, "Filosofia", 4);
    agregarMateriaAprobada(a5, 85, "Psicologia", 4);

    AlumnoPtr a6 = crearAlumno(45072144);
    agregarMateriaAprobada(a6, 0, "Arte", 7);
    agregarMateriaAprobada(a6, 22, "Musica", 5);
    agregarMateriaAprobada(a6, 80, "Teatro", 9);

    AlumnoPtr a7 = crearAlumno(45072145);
    agregarMateriaAprobada(a7, 0, "Geografia", 6);
    agregarMateriaAprobada(a7, 20, "Ciencias Sociales", 9);
    agregarMateriaAprobada(a7, 90, "Antropologia", 9);

    AlumnoPtr a8 = crearAlumno(45072146);
    agregarMateriaAprobada(a8, 0, "Educacion Fisica", 9);
    agregarMateriaAprobada(a8, 16, "Nutricion", 4);
    agregarMateriaAprobada(a8, 75, "Salud Publica", 4);

    AlumnoPtr a9 = crearAlumno(45072147);
    agregarMateriaAprobada(a9, 0, "Derecho", 10);
    agregarMateriaAprobada(a9, 14, "Legislacion", 9);
    agregarMateriaAprobada(a9, 80, "Derechos Humanos", 10);

    AlumnoPtr a10 = crearAlumno(45072148);
    agregarMateriaAprobada(a10, 0, "Ingenieria Civil", 4);
    agregarMateriaAprobada(a10, 12, "Ingenieria Ambiental", 4);
    agregarMateriaAprobada(a10, 85, "Ingenieria de Software", 4);

    AlumnoPtr a11 = crearAlumno(45072149);
    agregarMateriaAprobada(a11, 0, "Medicina Interna", 9);
    agregarMateriaAprobada(a11, 10, "Cirugia", 9);
    agregarMateriaAprobada(a11, 78, "Pediatría", 9);

    AlumnoPtr a12 = crearAlumno(45072150);
    agregarMateriaAprobada(a12, 0, "Electronica", 10);
    agregarMateriaAprobada(a12, 15, "Telecomunicaciones", 10);
    agregarMateriaAprobada(a12, 85, "Redes de Computadoras", 10);
    agregarMateriaAprobada(a12, 32, "Redes y Comunicaciones", 10);

    AlumnoPtr a13 = crearAlumno(45072151);
    agregarMateriaAprobada(a13, 0, "Arquitectura", 7);
    agregarMateriaAprobada(a13, 20, "Diseño Urbano", 7);
    agregarMateriaAprobada(a13, 90, "Patrimonio Cultural", 7);

    AlumnoPtr a14 = crearAlumno(45072152);
    agregarMateriaAprobada(a14, 0, "Psiquiatria", 5);
    agregarMateriaAprobada(a14, 18, "Neurologia", 5);
    agregarMateriaAprobada(a14, 80, "Psicoterapia", 4);

    AlumnoPtr a15 = crearAlumno(45072153);
    agregarMateriaAprobada(a15, 0, "Marketing", 8);
    agregarMateriaAprobada(a15, 16, "Publicidad", 8);
    agregarMateriaAprobada(a15, 75, "Gestión Empresarial", 9);

    AlumnoPtr a16 = crearAlumno(45072154);
    agregarMateriaAprobada(a16, 0, "Ecologia", 4);
    agregarMateriaAprobada(a16, 14, "Conservacion de la Naturaleza", 5);
    agregarMateriaAprobada(a16, 80, "Desarrollo Sostenible", 9);

    AlumnoPtr a17 = crearAlumno(45072155);
    agregarMateriaAprobada(a17, 0, "Historia del Arte", 9);
    agregarMateriaAprobada(a17, 10, "Cine", 4);
    agregarMateriaAprobada(a17, 85, "Literatura Comparada", 4);

    AlumnoPtr a18 = crearAlumno(45072156);
    agregarMateriaAprobada(a18, 0, "Astronomia", 10);
    agregarMateriaAprobada(a18, 12, "Astrofisica", 9);
    agregarMateriaAprobada(a18, 90, "Cosmologia", 9);

    AlumnoPtr a19 = crearAlumno(45072157);
    agregarMateriaAprobada(a19, 0, "Biomedicina", 7);
    agregarMateriaAprobada(a19, 20, "Bioquimica", 4);
    agregarMateriaAprobada(a19, 75, "Genetica", 4);

    AlumnoPtr a20 = crearAlumno(45072158);
    agregarMateriaAprobada(a20, 0, "Ingenieria Electrica", 9);
    agregarMateriaAprobada(a20, 15, "Energias Renovables", 9);
    agregarMateriaAprobada(a20, 85, "Automatizacion Industrial", 7);

    ///CREACION DE MATERIAS CON SUS RESPECTIVOS ALUMNOS INSCRIPTOS
    MateriaPtr m = crearMateria(0, "Probabilidad y Estadistica", 10);
    agregarAlumnoInscriptoMateria(m, a1);
    agregarAlumnoInscriptoMateria(m, a2);
    agregarAlumnoInscriptoMateria(m, a3);
    agregarAlumnoInscriptoMateria(m, a4);
    agregarAlumnoInscriptoMateria(m, a5);

    MateriaPtr m2 = crearMateria(1, "Programacion", 21);
    agregarAlumnoInscriptoMateria(m2, a14);
    agregarAlumnoInscriptoMateria(m2, a15);
    agregarAlumnoInscriptoMateria(m2, a16);
    agregarAlumnoInscriptoMateria(m2, a17);
    agregarAlumnoInscriptoMateria(m2, a18);
    agregarAlumnoInscriptoMateria(m2, a19);
    agregarAlumnoInscriptoMateria(m2, a20);

    MateriaPtr m3 = crearMateria(1, "Fisica III", 3);
    agregarAlumnoInscriptoMateria(m3, a9);
    agregarAlumnoInscriptoMateria(m3, a10);
    agregarAlumnoInscriptoMateria(m3, a11);
    agregarAlumnoInscriptoMateria(m3, a12);

    MateriaPtr m4 = crearMateria(2, "Quimica", 4);

    MateriaPtr m5 = crearMateria(3, "Biologia", 2);
    agregarAlumnoInscriptoMateria(m5, a6);
    agregarAlumnoInscriptoMateria(m5, a7);
    agregarAlumnoInscriptoMateria(m5, a8);

    MateriaPtr m6 = crearMateria(4, "Historia", 3);
    agregarAlumnoInscriptoMateria(m6, a13);

    ///CREACION DEL SIU GUARANI CON LAS MATERIAS ASOCIADAS A ÉL
    SIUGuaraniPtr siu = crearSIUGuarani();
    agregarMateriaSIUGuarani(siu, m);
    agregarMateriaSIUGuarani(siu, m2);
    agregarMateriaSIUGuarani(siu, m3);
    agregarMateriaSIUGuarani(siu, m4);
    agregarMateriaSIUGuarani(siu, m5);
    agregarMateriaSIUGuarani(siu, m6);
    mostrarSIUGuarani(siu);

    return 0;
}
