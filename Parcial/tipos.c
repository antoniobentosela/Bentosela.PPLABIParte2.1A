#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

void mostrarTipos(eTipo tipos[], int tamtip)
{

    //system("cls");
    printf("-----Listado Tipos-----\n\n");
    printf(" ID      Descripcion\n\n");

    for(int i=0; i < tamtip; i++)
    {

        printf("%d   %10s\n",tipos[i].id, tipos[i].descripcion);


    }
    printf("\n");
}
