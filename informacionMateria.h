#ifndef INFORMACIONMATERIA_H_INCLUDED
#define INFORMACIONMATERIA_H_INCLUDED
#define TAM_NOMBRE_MATERIA 100

struct InformacionMateriaE;
typedef struct InformacionMateriaE * InformacionMateriaPtr;

InformacionMateriaPtr crearInformacionMateria(int codigo, char nombre[TAM_NOMBRE_MATERIA]);

void mostrarInformacionMateria(InformacionMateriaPtr i);

int getCodigoInformacionMateria(InformacionMateriaPtr i);
void setCodigoInformacionMateria(InformacionMateriaPtr i, int nuevoCodigo);

char* getNombreInformacionMateria(InformacionMateriaPtr i);
void setNombreInformacionMateria(InformacionMateriaPtr i, char nuevoNombre[TAM_NOMBRE_MATERIA]);

void liberarInformacionMateria(InformacionMateriaPtr i);

#endif // INFORMACIONMATERIA_H_INCLUDED
