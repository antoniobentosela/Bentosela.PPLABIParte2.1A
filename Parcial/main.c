#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "trabajos.h"
#include "hardcodeos.h"

#define TAM 10
#define TAMTIP 4
#define TAMCOL 5
#define TAMSERV 4
#define TAMTRA 10
#define TAMCLI 10




int menu();

int menuInformes();
void informar(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv,  eCliente clientes[], int tamcli);
void informarBiciletaColor(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
void informarBiciletaTipo(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
void informarBicicletasMenorRodado(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
void informarBicicletasXTipo(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
void informarCantidadColorTipo(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
void colorMasElegido(eBicicleta vec[], int tam, eColor colores[], int tamcol);
float obtenerTotalColores(int idColor, eBicicleta vec[], int tam, eColor colores[], int tamcol);
void informarTrabajoBicicleta(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
void informarPrecioTrabajos(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);
void informarBicicletaServicio(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli);

int main()
{

    char seguir = 's';
    char confirma;
    int todoOk = 0;
    int proximoId = 100;
    int proximoIdTrabajo = 30000;
    eBicicleta lista[TAM];
    eTipo tipos[TAMTIP] = {{1000, "Rutera"}, {1001, "Carrera"},{1002, "Mountain"},{1003, "BMX"}};
    eColor colores[TAMCOL] = {{5000, "Gris"}, {5001, "Negro"},{5002, "Blanco"},{5003, "Azul"},{5004, "Rojo"}};
    eTrabajo trabajos[TAMTRA];
    eServicio servicios[TAMSERV] = {{20000, "Limpieza", 250}, {20001, "Parche", 300}, {20002, "Centrado", 400}, {20003, "Cadena", 350}};
    eCliente clientes[TAMCLI] = {{50000, "Antonio", 'm'}, {50001, "Marta", 'f'}, {50002, "Nicolas", 'm'}, {50003, "Sofia", 'f'}};

    inicializarBicicletas(lista, TAM);
    inicializarTrabajos(trabajos, TAMTRA);

    eBicicleta x = {100, "Nike", 5000, 1001, 50002, 20};
    eBicicleta x1 = {101, "RX", 5001, 1002, 50001, 22};
    eBicicleta x2 = {102, "TZZ", 5001, 1002, 50000, 20};
    eBicicleta x3 = {103, "BTS", 5003, 1003, 50002, 20};
    lista[0] = x;
    lista[1] = x1;
    lista[2] = x2;
    lista[3] = x3;

    eTrabajo b = {30000, 100, 20000, {12, 7, 1997}};
    eTrabajo b1 = {30001, 100, 20002, {13, 9, 1998}};
    eTrabajo b2 = {30002, 103, 20003, {12, 10, 2000}};
    eTrabajo b3 = {30003, 102, 20003, {14, 11, 1990}};
    trabajos[0] = b;
    trabajos[1] = b1;
    trabajos[2] = b2;
    trabajos[3] = b3;

    proximoId += 4;
    proximoIdTrabajo +=4;

    do
    {

        switch(menu())
        {

        case 1:
            if(altaBicicleta(proximoId, lista, TAM, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLI))
            {

                proximoId ++;
                todoOk = 1;

            };
            break;
        case 2:
            modificarBicicleta(lista, TAM, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLI);
            break;
        case 3:
            bajaBicicleta(lista, TAM, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLI);
            break;
        case 4:
            system("cls");
            mostrarTipos(tipos, TAMTIP);
            break;
        case 5:
            system("cls");
            mostrarColores(colores, TAMCOL);
            break;
        case 6:
            mostrarBicicletas(lista, TAM, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLI);
            break;
        case 7:
            if(todoOk == 0){

                printf("No hay bicicletas en el sistema\n\n");
            }
            else if(altaTrabajo(proximoIdTrabajo, trabajos, TAMTRA, lista, TAM, tipos, TAMTIP, colores, TAMCOL, servicios, TAMSERV, clientes, TAMCLI))
            {

                proximoIdTrabajo ++;

            };
            break;
        case 8:
            listarTrabajos(trabajos, TAMTRA, servicios, TAMSERV);
            break;

        case 9:
            informar(trabajos, TAMTRA, lista, TAM, tipos, TAMTIP, colores, TAMCOL, servicios, TAMSERV, clientes, TAMCLI);
        break;

        case 10:
            printf("Confirma salida?:\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {

                seguir = 'n';

            }
            break;
        }

        system("pause");

    }
    while(seguir == 's');

    return 0;



    return 0;
}


int menu()
{

    int opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1- Alta Bicicleta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Listar Tipos\n");
    printf("5- Listar Colores\n");
    printf("6- Listar Bicicleta\n");
    printf("7- Alta trabajo\n");
    printf("8- Listar trabajos\n");
    printf("9- Informar\n");
    printf("10- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int menuInformes()
{

    char opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("a- Informar Bicicleta Color\n");
    printf("b- Informar Bicicleta Tipo\n");
    printf("c- Informar Bicicletas con menor rodado\n");
    printf("d- Informar Bicicletas por tipo\n");
    printf("e- Informar Cantidad bicicletas tipo y color\n");
    printf("f- Informar Color mas elegido\n");
    printf("g- Informar Trabajos de una bicicleta\n");
    printf("h- Informar Total precio servicio\n");
    printf("i- Informar Servicios de una bicicleta\n");
    printf("j- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;

}

void informar(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv,  eCliente clientes[], int tamcli)
{

    char seguir = 's';
    char confirma;

    do
    {
        switch(menuInformes())
        {

        case 'a':
            informarBiciletaColor(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        case 'b':
            informarBiciletaTipo(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        case 'c':
            informarBicicletasMenorRodado(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        case 'd':
            informarBicicletasXTipo(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        case 'e':
            informarCantidadColorTipo(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        case 'f':
            colorMasElegido(vec, tam, colores, tamcol);
            break;
        case 'g':
            informarTrabajoBicicleta(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        case 'h':
            informarPrecioTrabajos(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        case 'i':
            informarBicicletaServicio(trabajos, tamtra, vec, tam, tipos, tamtip, colores, tamcol, servicios, tamserv, clientes, tamcli);
            break;
        //case 'j':


           // break;

       // case 'k':


            //break;
        case 'j':
            printf("Confirma salida?:\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {

                seguir = 'n';

            }
            break;
        }

        system("pause");

    }
    while(seguir == 's');

}

void informarBiciletaColor(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli){

    int flag = 0;
    int color;

    system("cls");
    mostrarColores(colores, tamcol);

    printf("Ingrese id color: ");
    scanf("%d", &color);

    printf(" \n\n");

    printf(" ID          Marca        Tipo        Color    Rodado    Nombre Cliente\n\n");
    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idColor == color)
        {

            mostrarBicicleta(vec[i], tipos, tamtip, colores, tamcol, clientes, tamcli);
            flag = 1;

        }
    }

    if(flag == 0)
    {

        printf("No hay bicicletas que listar\n");

    }

}

void informarBiciletaTipo(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli){

    int flag = 0;
    int tipo;

    system("cls");
    mostrarTipos(tipos, tamtip);

    printf("Ingrese id tipo: ");
    scanf("%d", &tipo);

    printf(" \n\n");

    printf(" ID          Marca        Tipo        Color    Rodado    Nombre Cliente\n\n");
    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idTipo == tipo)
        {

            mostrarBicicleta(vec[i], tipos, tamtip, colores, tamcol, clientes, tamcli);
            flag = 1;

        }
    }

    if(flag == 0)
    {

        printf("No hay bicicletas que listar\n");

    }

}

void informarBicicletasMenorRodado(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli){

    //int flag = 0;
    system("cls");
    printf("-----Menores Rodados------\n\n");
    printf(" ID          Marca        Tipo        Color    Rodado    Nombre Cliente\n\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].rodado == 20){

            mostrarBicicleta(vec[i], tipos, tamtip, colores, tamcol, clientes, tamcli);

        }


    }

}

void informarBicicletasXTipo(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli)
{
    int flag = 0;

    system("cls");

    for(int i=0; i < tamtip; i++)
    {
        flag = 0;
        printf("\nTipo %s\n\n", tipos[i].descripcion);

        for(int j = 0; j < tam; j++)
        {

            if(vec[j].isEmpty == 0 && tipos[i].id == vec[j].idTipo)
            {
                mostrarBicicleta(vec[i], tipos, tamtip, colores, tamcol, clientes, tamcli);
                flag = 1;
            }

        }
        if(flag == 0)
        {

            printf("No hay bicicletas de ese tipo\n");

        }

    }
}

void informarCantidadColorTipo(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli){

    int color;
    int tipo;
    int contador = 0;


    mostrarColores(colores, tamcol);

    printf("Ingrese id color: ");
    scanf("%d", &color);

    mostrarTipos(tipos, tamtip);

    printf("Ingrese id tipo: ");
    scanf("%d", &tipo);

    for(int i=0; i < tam; i++){

        if(vec[i].idColor == color && vec[i].idTipo == tipo){

            contador ++;

        }

    }

    system("cls");
    printf("Hay %d bicibletas de ese color y ese tipo\n\n", contador);

}


float obtenerTotalColores(int idColor, eBicicleta vec[], int tam, eColor colores[], int tamcol)
{

    int totalColores = 0;

    for(int i = 0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idColor == idColor)
        {

            totalColores += vec[i].idColor;

        }

    }

    return totalColores;

}

void colorMasElegido(eBicicleta vec[], int tam, eColor colores[], int tamcol)
{

    float totalColores[tamcol];
    float mayorTotal = 0;
    int flag = 0;

    system("cls");

    printf("Color que mas se elige\n\n");

    for(int c=0; c < tamcol; c++)
    {
        totalColores[c] = obtenerTotalColores(colores[c].id, vec, tam, colores, tamcol);

    }


    for(int c = 0; c < tamcol; c++)
    {

        if(totalColores[c] > mayorTotal || flag == 0)
        {

            mayorTotal = totalColores[c];
            flag = 1;


        }
    }

    printf("El color mas elegido es: ");

    for(int c = 0; c < tamcol; c++)
    {

        if(totalColores[c] == mayorTotal)
        {

            printf("%s\n\n", colores[c].nombreColor);

        }
    }
}

void informarTrabajoBicicleta(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli){

    int id;

    mostrarBicicletas(vec, tam, tipos, tamtip, colores, tamcol, clientes, tamcli);

    printf("Ingrese id de la Bicicleta ");
    scanf("%d", &id);

    for(int i = 0; i < tamtra; i++){

        if(trabajos[i].idBicicleta == id){

            listarTrabajo(trabajos[i], servicios, tamserv);

        }
    }



}

void informarPrecioTrabajos(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli){

    int id;
    float total = 0;

    mostrarBicicletas(vec, tam, tipos, tamtip, colores, tamcol, clientes, tamcli);

    printf("Ingrese id de la Bicicleta ");
    scanf("%d", &id);

    for(int i = 0; i < tamtra; i++){

        if(trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == id){

            total += servicios[i].precio;

        }

    }

    printf("Esa bicicleta debe pagar: $%.2f\n\n", total);
}

void informarBicicletaServicio(eTrabajo trabajos[], int tamtra, eBicicleta vec[], int tam, eTipo tipos[], int tamtip, eColor colores[], int tamcol, eServicio servicios[], int tamserv, eCliente clientes[], int tamcli){

    int id;
    int flag = 0;

    listarServicios(servicios, tamserv);

    printf("Ingrese id del servicio: ");
    scanf("%d", &id);

    system("cls");

    printf(" ID          Marca        Tipo        Color    Rodado    Nombre Cliente\n\n");

    for(int i = 0; i < tam; i++){

        if(trabajos[i].idServicio == id){

        mostrarBicicleta(vec[i], tipos, tamtip, colores, tamcol, clientes, tamcli);
        printf("Fecha: %d/%d/%d\n\n", trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
        printf("-----------------------------------");
        flag = 1;
        }
    }

    if(flag == 0){

        printf("No hay bicicletas con ese servicio\n\n");

    }
}
