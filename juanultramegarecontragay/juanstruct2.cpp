#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

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
    int musicant;      // cantidad de canciones
    string titulo;     // titulo del album
    struct inicio emi; // mes y ano de emision del disco
    struct canciones music[20];
    struct disquera disq;
    struct colaborador feat;
    bool col {false};
};

struct disco
{
    int albcant;    // cantidad de albunes
    string nomr;    // nombre real
    char nomar[20]; // nombre artistico
    string pais;    // pais de origen
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

void cargar(struct disco art[50], int artcant)
{
    puts("introduzca la cantidad de artistas: ");
    artcant = validar(50, 1);
    for (int i = 0; i < artcant; i++)
    {
        // cargando disco art
        printf("---------artista [%i] de [%i]---------", i, artcant);
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
        art[i].edad = validar(100, 18);
        puts("Fecha de inicio de su carrera:");
        puts("Ano:");
        art[i].fecha.ano = validar(2022, 0);
        puts("Mes:");
        art[i].fecha.mes = validar(12, 1);

        puts("Numero de albumes del artista:");
        art[i].albcant = validar(10, 1);
        for (int j = 0; j < art[i].albcant; j++)
        {
            printf("---------album [%i] de [%i]---------", j, art[i].albcant);
            puts("Titulo del album:");
            scanf("%s", art[i].rele[j].titulo);
            fflush(stdin);
            puts("mes y ano de emision del disco");
            puts("Ano:");
            art[i].rele[j].emi.ano = validar(2022, 0);
            puts("Mes:");
            art[i].rele[j].emi.mes = validar(12, 1);

            puts("Cantidad de canicones:");
            art[i].rele[j].musicant = validar(20, 5);
            for (int k = 0; k < art[i].rele[j].musicant; k++)
            {
                printf("---------cancion [%i] de [%i]---------", k, art[i].rele[j].musicant);
                puts("Nombre de la cancion");
                scanf("%s", art[i].rele[j].music[k].nomc);
                fflush(stdin);
                puts("Duracion de la cancion:");
                puts("Min:");
                art[i].rele[j].music[k].dur.min = validar(59, 0);
                puts("Seg:");
                art[i].rele[j].music[k].dur.seg = validar(59, 0);
                puts("Nombre del autor:");
                scanf("%s", art[i].rele[j].music[k].autor);
                fflush(stdin);
                puts("Genero musical:");
                scanf("%s", &art[i].rele[j].music[k].genero);
                fflush(stdin);
            }

            puts("Nombre de la disquera:");
            scanf("%s", art[i].rele[j].disq.nomd);
            fflush(stdin);
            puts("Ciudad de asentamiento:");
            scanf("%s", art[i].rele[j].disq.asen);
            fflush(stdin);
            puts("Monto por el contrato del disco:");
            art[i].rele[j].disq.monto = validar(3.40282e+038, 0.1);
            

            printf("tuvo colaborador?\n");
            scanf("%b",art[i].rele[j].col);
            if(art[i].rele[j].col==true){
            {
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
    }
}

void mostrar(struct disco art[50], int artcant)
{

    for (int i = 0; i < artcant; i++)
    {
        // cargando disco art
        puts("Nombre real:");
        printf("%s", art[i].nomr);
        puts("Nombre real:");
        printf("%s", art[i].nomar);
        puts("Pais de origen:");
        printf("%s", art[i].pais);
        puts("Edad:");
        printf("%i", art[i].edad);
        puts("Fecha de inicio de su carrera:");
        puts("Ano:");
        printf("%i", art[i].fecha.ano);
        puts("Mes:");
        printf("%i", art[i].fecha.mes);

        for (int j = 0; j < art[i].albcant; j++)
        {
            puts("Titulo del album:");
            printf("%s", art[i].rele[j].titulo);
            puts("mes y ano de emision del disco");
            puts("Ano:");
            printf("%i", art[i].rele[j].emi.ano);
            puts("Mes:");
            printf("%i", art[i].rele[j].emi.mes);

            for (int k = 0; k < art[i].rele[j].musicant; k++)
            {
                puts("Nombre de la cancion");
                printf("%s", art[i].rele[j].music[k].nomc);
                puts("Duracion de la cancion:");
                puts("Min:");
                printf("%i", art[i].rele[j].music[k].dur.min);
                puts("Seg:");
                printf("%i", art[i].rele[j].music[k].dur.seg);
                puts("Nombre del autor:");
                printf("%s", art[i].rele[j].music[k].autor);
                puts("Genero musical:");
                printf("%s", art[i].rele[j].music[k].genero);
            }

            puts("Nombre de la diquera:");
            printf("%s", art[i].rele[j].disq.nomd);
            puts("Ciudad de asentamiento:");
            printf("%s", art[i].rele[j].disq.asen);
            puts("Monto por el contrato del disco:");
            art[i].rele[j].disq.monto = validar(0.1, 3.40282e+038);

            if(art[i].rele[j].col==true){
            puts("Nombre del colaborador:");
            printf("%s", art[i].rele[j].feat.nomcolab);
            puts("Pais:");
            printf("%s", art[i].rele[j].feat.pais);
            puts("Genero:");
            printf("%s", art[i].rele[j].feat.genero);
            puts("Numero de canciones que realizaron juntos:");
            art[i].rele[j].feat.numc = validar(0, 20);
            }
        }
    }
}

int cuatro(struct disco art[50], int artcant)
{
    char nombre[20];
    int aux;
    printf("Ingrese el nombre del artista para buscar la cancion con mas duracion:");
    scanf("%s", nombre);

    // if (str1.compare(str2) != 0)
    // std::cout << str1 << " is not " << str2 << '\n';

    for (int i = 0; i < artcant; i++)
    {
        int mayordur; //mayor duracion 
        string cancion;
        
        if (strcmp(art[i].nomar, nombre) == 0)
        {
            for (int j = 0; j < art[i].albcant; j++)
            {
                for (int z = 0; z < art[i].rele[j].musicant-1; z++)
                {
                    if (art[i].rele[j].music[z].dur.min > art[i].rele[j].music[z + 1].dur.min)
                    {
                        aux = art[i].rele[j].music[z].dur.min;
                        art[i].rele[j].music[z].dur.min = art[i].rele[j].music[z + 1].dur.min;
                        art[i].rele[j].music[z + 1].dur.min = aux;
                    }
                }
            }
        
            for (int j=0; j < art[i].albcant-1;j++)
            {
                if(art[i].rele[j].music[art[i].rele[j].musicant].dur.min > art[i].rele[j+1].music[art[i].rele[j].musicant].dur.min)
                {
                    mayordur = art[i].rele[j].music[art[i].rele[j].musicant].dur.min; 
                    cancion = art[i].rele[j+1].music[art[i].rele[j].musicant].nomc;
                    art[i].rele[j].music[art[i].rele[j].musicant].dur.min = art[i].rele[j+1].music[art[i].rele[j].musicant].dur.min;
                    art[i].rele[j+1].music[art[i].rele[j].musicant].dur.min = mayordur;
                }
            }
        }

        printf("La cancion con mas duracion es %s",cancion);
    }


}

int main()
{
    int artcant;          // cantidad artistas
    struct disco art[50]; // artistas
    cargar(art, artcant);
    mostrar(art, artcant);
}

