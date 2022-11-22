#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

/*ejercicio #3 de la segunda guia (structuras)*/
struct candidatos
{
    string nombre;  // nombre del candidato
    string partido; // partido politico
    int votosobt;   // votos obtnidos
};

struct datos_estado
{
    string estado;  // nombre estado
    int numvot;     // numero de votantes
    int votvalid;   // votos validos
    int votnulos;   // votos nulos
    int nrocentros; // numero de centros de votacion
    int nromesas;   // numero de mesas
    int cantcandi;  // cantidad de candidatos
    struct candidatos ca[10];
};

int validar(int min, int max)
{
    int input;
    bool check = false;

    do
    {
        if (max == 2147483647)
        {
            printf("ingrese un numero mayor o igual a %i: ", min);
        }
        else
        {
            printf("Ingrese un numero entre %i y %i:", min, max);
        }
        scanf("%i", &input);
        if (input < min || input > max)
        {
            puts("error! numero fuera de rango");
        }
        else
        {
            check = true;
        }

    } while (check == false);

    return input;
}

void cargar(struct datos_estado elec[24], int cantestado)
{
    // cargando datos de los estados

    puts("Cantidad de estados:");
    scanf("%i", &cantestado);

    for (int i = 0; i < cantestado; i++)
    {
        puts("Nombre de estado:");
        scanf("%s", &elec[i].estado);

        puts("Numero de votantes:");
        elec[i].numvot = validar(1, 2147483647);
        puts("Cant votos validos:");
        elec[i].votvalid = validar(0, 2147483647);
        puts("Cant votos nulos:");
        elec[i].votnulos = validar(0, 2147483647);
        puts("numero de centros de votacion:");
        elec[i].nrocentros = validar(1, 2147483647);
        puts("numero de mesas:");
        elec[i].nromesas = validar(1, 2147483647);

        // cargndo cadidatos
        puts("Cantidad de candidatos:");
        elec[i].cantcandi = validar(2, 10);
        printf("cantidad de candidatos introducido: %i\n", elec[i].cantcandi);
        if (elec[i].cantcandi==2){elec[i].cantcandi=elec[i].cantcandi+1;}
        for (int j = 0; j < (elec[i].cantcandi); j++)
        {
            fflush(stdin);

            printf("Nombre del candidato %i:", j + 1);
            scanf("%s", &elec[i].ca[j].nombre);
            fflush(stdin);
            printf("Partido politico:");
            scanf("%s", &elec[i].ca[j].partido);
            fflush(stdin);
            printf("Cant votos obtenidos:");
            elec[i].ca[j].votosobt = validar(2, 2147483647);
        }
    }
}

void mostrar(struct datos_estado elec[24], int cantestado)
{
    // mostrando datos de los estados

    for (int i = 0; i < cantestado; i++)
    {
        puts("Nombre de estado:");
        printf("%s \n", &elec[i].estado);
        puts("Numero de votantes:");
        printf("%i \n", elec[i].numvot);
        puts("Cant votos validos:");
        printf("%i \n", elec[i].votvalid);
        puts("Cant votos nulos:");
        printf("%i \n", elec[i].votnulos);
        puts("numero de centros de votacion:");
        printf("%i \n", elec[i].nrocentros);
        puts("numero de mesas:");
        printf("%i \n", elec[i].nromesas);

        // mostrando cadidatos
        puts("Cantidad de candidatos:");
        elec[i].cantcandi = validar(2, 10);
        for (int j = 0; j < elec[i].cantcandi; j++)
        {
            printf("Nombre del candidato %i:", j);
            printf("%s", elec[i].ca[j].nombre);
            printf("Partido politico:");
            printf("%s", elec[i].ca[j].partido);
            printf("Cant votos obtenidos:");
            printf("%i", elec[i].ca[j].votosobt);
        }
    }
}

int main()
{
    int cantestado; // cantidad de estados
    struct datos_estado elec[24];

    cargar(elec, cantestado);
    mostrar(elec, cantestado);
}