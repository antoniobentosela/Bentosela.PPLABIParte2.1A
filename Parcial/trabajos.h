#include "bicicleta.h"
#include "servicio.h"

#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFechaIngreso;

typedef struct
{
   int id;
   int idBicicleta;
   int idServicio;
   eFechaIngreso fecha;
   int isEmpty;

}eTrabajo;

#endif // TRABAJOS_H_INCLUDED

void inicializarTrabajos(eTrabajo vec[], int tam);
int buscarLibreTrabajo(eTrabajo vec[], int tam);
void listarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamserv);
void listarTrabajos(eTrabajo trabajo[], int tamtra, eServicio servicios[], int tamserv);
int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamserv);
int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
