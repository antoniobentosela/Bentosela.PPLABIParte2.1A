#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

void mostrarColores(eColor colores[], int tamcol)
{

    //system("cls");
    printf("-----Listado Colores-----\n\n");
    printf(" ID      Nombre\n\n");

    for(int i=0; i < tamcol; i++)
    {

        printf("%d   %10s\n",colores[i].id, colores[i].nombreColor);


    }
    printf("\n");
}
