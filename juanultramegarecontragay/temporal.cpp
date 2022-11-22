#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct duracion
{
    int min, seg;
};

struct inicio
{
    int mes, ano;
};

struct colaborador
{
    string nomcolab; // nombre del colaborador
    string pais;
    string genero;
    int numc; // numero de canciones que realizaron juntos
};

struct disquera
{
    string nomd; // nombre de la disquera
    string asen; // cuidad de asentamiento
    float monto; // monto por el contrato del disco
};

struct canciones
{
    string nomc;         // nombre de la cancion
    struct duracion dur; // duracion en min y seg
    string autor;
    string genero; // genero musical
};

struct album
{
    int musicant;
    string titulo;     // titulo del album
    struct inicio emi; // mes y ano de emision del disco
    struct canciones music[20];
    struct disquera disq;
    struct colaborador feat; // att:rafa
};

struct disco
{   int albcant;
    string nomr;  // nombre real
    string nomar; // nombre artistico
    string pais;  // pais de origen
    int edad;
    struct inicio fecha; // fecha en la que inicio su carrera musical
    struct album rele[10];
};

float validar(float max, float min)
{
    float input = 0;
    bool valid = false;

    do
    {
        printf("Ingrese un valor entre %g y %g:", min, max);
        scanf("%f", &input);
        if (input < min || input > max)
        {
            puts("Error");
        }
        else
        {
            valid = true;
        }

    } while (valid == false);

    return input;
}

void cargar(struct disco art[50],int merwe)
{   
    puts("introduzca la cantidad de artistas: ");
    merwe=validar(50,1);
    for (int i = 0; i < merwe; i++)
    {
        // cargando disco art
        puts("Nombre real:");
        scanf("%s", art[i].nomr);
        fflush(stdin);
        puts("Nombre de artista:");
        scanf("%s", art[i].nomar);
        fflush(stdin);
        puts("Pais de origen:");
        scanf("%s", art[i].pais);
        fflush(stdin);
        puts("Edad:");
        art[i].edad=validar(100,18);
        puts("Fecha de inicio de su carrera:");
        puts("Ano:");
        art[i].fecha.ano=validar(2022,0);
        puts("Mes:");
        art[i].fecha.mes=validar(12,1);

        puts("Numero de albumes del artista:");
        art[i].albcant = validar(10, 1);
        for (int j = 0; j < art[i].albcant; j++)
        {
            puts("Titulo del album:");
            scanf("%s", art[i].rele[j].titulo);
            fflush(stdin);
            puts("mes y ano de emision del disco");
            puts("Ano:");
            art[i].rele[j].emi.ano=validar(2022,0);
            puts("Mes:");
            art[i].rele[j].emi.mes=validar(12,1);

            puts("Cantidad de canicones:");
            art[i].rele[j].musicant= validar(20, 5);
            for (int k = 0; k < art[i].rele[j].musicant; k++)
            {
                puts("Nombre de la cancion");
                scanf("%s", art[i].rele[j].music[k].nomc);
                fflush(stdin);
                puts("Duracion de la cancion:");
                puts("Min:");
                art[i].rele[j].music[k].dur.min=validar(59,0);
                puts("Seg:");
                art[i].rele[j].music[k].dur.seg=validar(59,0);
                puts("Nombre del autor:");
                scanf("%s", art[i].rele[j].music[k].autor);
                fflush(stdin);
                puts("Genero musical:");
                scanf("%s", art[i].rele[j].music[k].genero);
            fflush(stdin);}


            puts("Nombre de la diquera:");
            scanf("%s", art[i].rele[j].disq.nomd);
            fflush(stdin);
            puts("Ciudad de asentamiento:");
            scanf("%s", art[i].rele[j].disq.asen);
            fflush(stdin);
            puts("Monto por el contrato del disco:");
            art[i].rele[j].disq.monto = validar(3.40282e+038,0.1);

            puts("Nombre del colaborador:");
            scanf("%s", art[i].rele[j].feat.nomcolab);
            fflush(stdin);
            puts("Pais:");
            scanf("%s", art[i].rele[j].feat.pais);
            fflush(stdin);
            puts("Genero:");
            scanf("%s", art[i].rele[j].feat.genero);
            fflush(stdin);
            puts("Numero de canciones que realizaron juntos:");
            art[i].rele[j].feat.numc = validar(20, 0);
        }
    }
}