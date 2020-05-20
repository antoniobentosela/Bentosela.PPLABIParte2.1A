#include "tipos.h"
#include "color.h"
#include "hardcodeos.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
   int id;
   char nombre[20];
   char sexo;

}eCliente;

typedef struct
{
    int id;
    char marca[20];
    int idColor;
    int idTipo;
    int idCliente;
    int rodado;
    int isEmpty;

} eBicicleta;

#endif // BICICLETA_H_INCLUDED

void inicializarBicicletas(eBicicleta vec[], int tam);
void mostrarBicicleta(eBicicleta x, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);
void mostrarBicicletas(eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);
int buscarLibre(eBicicleta vec[], int tam);
int buscarBicicleta(int id, eBicicleta vec[], int tam);
int altaBicicleta(int proximoId, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);
void modificarBicicleta(eBicicleta vec[], int tam,  eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);
void bajaBicicleta(eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli);
void mostrarClientes(eCliente clientes[], int tamcli);
void harcodearBicicletas(eBicicleta vec[], int cant);

int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamtip);
int cargarNombreColor(char nombreColor[], int id, eColor colores[], int tamcol);
int cargarNombreCliente(char nombreCliente[], int id, eCliente clientes[], int tamcli);
