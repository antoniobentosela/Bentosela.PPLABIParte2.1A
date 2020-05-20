#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "hardcodeos.h"

void inicializarBicicletas(eBicicleta vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        vec[i].isEmpty = 1;

    }
}

void mostrarBicicleta(eBicicleta x, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli)
{

    char descTipo[20];
    char nombreColor[20];
    char nombreCliente[20];
    cargarDescripcionTipo(descTipo, x.idTipo, tipos, tamtip);
    cargarNombreColor(nombreColor,  x.idColor, colores, tamcol);
    cargarNombreCliente(nombreCliente, x.idCliente, clientes, tamcli);

    printf("%d   %10s     %10s     %10s     %d     %10s\n", x.id, x.marca, descTipo, nombreColor, x.rodado, nombreCliente);


}

void mostrarBicicletas(eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli)
{

    int flag = 0;

    system("cls");
    printf("-----Listado de Bicicletas-----\n\n");
    printf(" ID          Marca        Tipo        Color    Rodado    Nombre Cliente\n\n");

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0)
        {

            mostrarBicicleta(vec[i], tipos, tamtip, colores, tamcol, clientes, tamcli);
            flag = 1;

        }
    }

    if(flag == 0)
    {

        printf("No hay bicicletas que listar\n");
        printf("\n");

    }
}

int buscarLibre(eBicicleta vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 1)
        {

            indice = i;
            break;
        }

    }

    return indice;
}

int buscarBicicleta(int id, eBicicleta vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].id == id)
        {

            indice = i;
            break;
        }

    }

    return indice;
}

int altaBicicleta(int proximoId, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli)
{

    int todoOk = 0;
    int indice;
    eBicicleta auxBicicleta;

    system("cls");

    printf("------Alta Bicicleta------\n\n");

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {

        printf("El sistema se encuentra completo\n\n");
        system("pause");

    }
    else
    {

        auxBicicleta.id = proximoId;

        printf("Ingrese marca: ");
        fflush(stdin);
        gets(auxBicicleta.marca);

        if(strlen(auxBicicleta.marca)>=20){

            printf("Nombre de la marca de la bicicleta demasiado largo. Reingrese nombre: ");
            fflush(stdin);
            gets(auxBicicleta.marca);
        }

        mostrarTipos(tipos, tamtip);

        printf("Ingrese id del tipo: ");
        scanf("%d", &auxBicicleta.idTipo);

        while(!(auxBicicleta.idTipo <= 1003 && auxBicicleta.idTipo >= 1000)){

            printf("Id incorrecto, no existe. Reingrese el id: ");
            scanf("%d", &auxBicicleta.idTipo);

        }

        mostrarColores(colores, tamcol);

        printf("Ingrese id del color: ");
        scanf("%d", &auxBicicleta.idColor);

        while(!(auxBicicleta.idColor <= 5004 && auxBicicleta.idColor >= 5000)){

            printf("Id incorrecto, no existe. Reingrese el id: ");
            scanf("%d", &auxBicicleta.idColor);

        }

        printf("Ingrese Rodado(20, 26, 27.5 o 29): ");
        scanf("%d", &auxBicicleta.rodado);

        while(auxBicicleta.rodado != 20 && auxBicicleta.rodado != 26 && auxBicicleta.rodado != 27.5 && auxBicicleta.rodado != 29){

            printf("Error. Ingrese Rodado(20, 26, 27.5 o 29): ");
            scanf("%d", &auxBicicleta.rodado);

        }

        mostrarClientes(clientes, tamcli);

        printf("Ingrese id del color: ");
        scanf("%d", &auxBicicleta.idCliente);

        auxBicicleta.isEmpty = 0;

        vec[indice] = auxBicicleta;
        todoOk = 1;

    }

    return todoOk;
}

void modificarBicicleta(eBicicleta vec[], int tam,  eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli)
{

    int indice;
    int id;
    int idTipo;
    int rodado;
    int opcion;

    system("cls");

    printf("------Modificar Bicicleta------\n\n");

    mostrarBicicletas(vec, tam, tipos, tamtip, colores, tamcol, clientes, tamcli);

    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarBicicleta(id, vec, tam);

    if(indice == -1)
    {
        printf("\nNo existe ese id\n\n");
        system("pause");


    }
    else
    {

        mostrarBicicleta(vec[indice], tipos, tamtip, colores, tamcol, clientes, tamcli);

        printf("1.Tipo\n");
        printf("2.Rodado\n");

        printf("Que dato quiere modificar? ");
        scanf("%d", &opcion);

        if(opcion == 1)
        {
            mostrarTipos(tipos, tamtip);
            printf("Ingrese id tipo: ");
            scanf("%d", &idTipo);
            vec[indice].idTipo = idTipo;
            printf("Se ha realizado la modiicacion\n\n");

        }
        if(opcion == 2)
        {

            printf("Ingrese rodado: ");
            scanf("%d", &rodado);
            vec[indice].rodado = rodado;
            printf("Se ha realizado la modificacion\n\n");


        }
        else
        {

            printf("No es una opcion valida");


        }
    }
}

void bajaBicicleta(eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eCliente clientes[], int tamcli)
{

    int indice;
    int id;
    char confirma;

    system("cls");

    printf("------Baja Bicicleta------\n\n");

    mostrarBicicletas(vec, tam, tipos, tamtip, colores, tamcol, clientes, tamcli);

    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarBicicleta(id, vec, tam);

    if(indice == -1)
    {
        printf("\nNo existe ese id\n\n");
        system("pause");


    }
    else
    {

        mostrarBicicleta(vec[indice], tipos, tamtip, colores, tamcol, clientes, tamcli);

        printf("Confirma la eliminacion? ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {

            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja\n\n");

        }
        else
        {

            printf("Se cancelo la eliminacion\n\n");

        }
    }
}

int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamtip)
{

    int todoOk = 0;

    for(int i=0; i < tamtip; i++)
    {

        if(tipos[i].id == id)
        {

            strcpy(descripcion, tipos[i].descripcion);
            todoOk = 1;
        }

    }

    return todoOk;
}

int cargarNombreColor(char nombreColor[], int id, eColor colores[], int tamcol)
{

    int todoOk = 0;

    for(int i=0; i < tamcol; i++)
    {

        if(colores[i].id == id)
        {

            strcpy(nombreColor, colores[i].nombreColor);
            todoOk = 1;
        }

    }

    return todoOk;
}

int cargarNombreCliente(char nombreCliente[], int id, eCliente clientes[], int tamcli)
{

    int todoOk = 0;

    for(int i=0; i < tamcli; i++)
    {

        if(clientes[i].id == id)
        {

            strcpy(nombreCliente, clientes[i].nombre);
            todoOk = 1;
        }

    }

    return todoOk;
}

void mostrarClientes(eCliente clientes[], int tamcli)
{

    //system("cls");
    printf("-----Listado Clientes-----\n\n");
    printf(" ID      Nombre   Sexo\n\n");

    for(int i=0; i < tamcli; i++)
    {

        printf("%d   %10s    %c\n",clientes[i].id, clientes[i].nombre, clientes[i].sexo);


    }
    printf("\n");
}
/*
void harcodearBiciletas(eBicicleta vec[], int cant)
{

    for(int i=0; i < cant; i++)
    {

        vec[i].id = idss[i];
        strcpy(vec[i].marca, marcas[i]);
        vec[i].idColor = idColors[i];
        vec[i].idTipo = idTipos[i];
        vec[i].idCliente = idClientes[i];
        vec[i].rodado = rodados[i];
        vec[i].isEmpty = 0;

    }
}
*/
