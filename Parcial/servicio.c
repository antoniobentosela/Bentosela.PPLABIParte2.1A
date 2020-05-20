#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void listarServicios(eServicio servicios[], int tamserv){

    printf("Listado servicios\n\n");
    printf("id    descripcion    precio\n");

    for(int i=0; i < tamserv; i++){

        printf("  %d    %10s    %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);

    }

    printf("\n");
}
