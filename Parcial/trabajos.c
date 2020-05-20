#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajos.h"

void inicializarTrabajos(eTrabajo vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        vec[i].isEmpty = 1;

    }

}

int buscarLibreTrabajo(eTrabajo vec[], int tam)
{

    int indice = -1; //va -1, porque -1 no puede ser un indice de un vector, al inicializar, indice no puede ser un indice valido del vector.

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

void listarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamserv)
{

    char descServicio[20];

    cargarDescripcionServicio(descServicio, trabajo.idServicio, servicios, tamserv);
    printf("%d     %d      %10s      %d/%d/%d\n", trabajo.id, trabajo.idBicicleta, descServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);

}

void listarTrabajos(eTrabajo trabajos[], int tamtra, eServicio servicios[], int tamserv)
{

    int flag = 0;
    system("cls");
    printf("Listado Trabajos\n\n");
    printf("id     idBicicleta   Servicio      Fecha\n");

    for(int i=0; i < tamtra; i++)
    {

        if(trabajos[i].isEmpty == 0)
        {
            listarTrabajo(trabajos[i], servicios, tamserv);
            flag=1;
        }
    }
    if(flag == 0)
    {

        printf("no hay trabajos que mostrar\n");

    }
    printf("\n");

}

int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamserv)
{

    int todoOk = 0;

    for(int i=0; i < tamserv; i++)
    {

        if(servicios[i].id == id)
        {

            strcpy(descripcion, servicios[i].descripcion);
            todoOk = 1;
        }

    }

    return todoOk;
}

int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli)
{

    int todoOk = 0;
    int indice;
    int indiceBicicleta;
    eTrabajo auxTrabajo;

    system("cls");

    printf("------Alta Trabajo------\n\n");

    indice = buscarLibreTrabajo(trabajos, tamtra);

    if(indice == -1)
    {

        printf("El sistema se encuentra completo\n\n");
        system("pause");

    }
    else
    {

        mostrarBicicletas(vec, tam, tipos, tamtip, colores, tamcol, clientes, tamcli);

        printf("Ingrese id bicicleta: ");
        scanf("%d", &auxTrabajo.idBicicleta);

        indiceBicicleta = buscarBicicleta(auxTrabajo.idBicicleta, vec, tam);

        while(indiceBicicleta == -1){

            printf("Error. No existe el id de esa bicicleta. Ingrese id bicicleta: ");
            scanf("%d", &auxTrabajo.idBicicleta);

            indiceBicicleta = buscarBicicleta(auxTrabajo.idBicicleta, vec, tam);

        }

        listarServicios(servicios, tamserv);

        printf("Ingrese id servicio: ");
        scanf("%d", &auxTrabajo.idServicio);

        while(!(auxTrabajo.idServicio <= 20003 && auxTrabajo.idServicio >= 20000)){

            printf("Id incorrecto, no existe. Reingrese el id: ");
            scanf("%d", &auxTrabajo.idServicio);

        }

        printf("Ingrese fechas de ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);

        auxTrabajo.id = idTrabajo;
        auxTrabajo.isEmpty = 0;

        trabajos[indice] = auxTrabajo;
        todoOk = 1;

        printf("\nAlta trabajo exitoso");

    }


    return todoOk;

}
