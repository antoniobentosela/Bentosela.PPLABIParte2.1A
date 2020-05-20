#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
   int id;
   char descripcion[20];

} eTipo;

#endif // TIPOS_H_INCLUDED

void mostrarTipos(eTipo tipos[], int tamtip);
