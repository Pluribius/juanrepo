#include<iostream>
#include<conio.h>
#include<stdio.h> 
#include<string.h>
#define maxv 40
#define maxc 12
using namespace std;

/*una empresa alquila vehiculos para competencias deseando llevar un regristro de sus 40 unidades 
esto incluye  Placa,Serial,Modelo y ano. tambien se leva un control de las participaciones en competencias 
mensual, estimandose un maximo de 12 al ano, es decir,no todos los meses se compiten. En cada cometencia se tiene 
la fecha mes y ano, cliente que lo alquilo (nombre,rif,telefono),km recorridos en la competencia y monto facturado. Cada vehiculo 
tiene un kilometraje recorrido, que se debe  actualizar con las competencias cada vez que lo solicita.

-se quiere dado un kilomatraje minimo, determinar cuales vehiculos requieren mantenimiento. pid. placa y vehiculo
-dado un cliente, indique el monto de su mayor factura en diciembre. */

struct fecha
{
    int mes, ano;
};

struct cliente
{
    string nombre, rif;
    int tlf;
};

struct competencias
{
    struct fecha fec;
    struct cliente cli;
    float krec; //km recorridos 
    float monto;
};

struct vehiculo
{
    string placa, serial, modelo;
    int ano, numc; //numc=numero de competencias 
    struct competencias com[maxc];
    float kmtot; //kilmetraje total  
};

void matenim(struct vehiculo car[maxv])
{
    float kmin; //kilometraje minimo 

    printf("Kilometraje minimo para realizar mantenimiento:");
    scanf("%f",&kmin);

    for(int i=0; i<maxv; i++)
    {
        for(int j=0; j<car[i].numc; j++)
        {
            car[i].kmtot = car[i].kmtot + car[i].com[j].krec;
        }

        if(car[i].kmtot >= kmin){ printf("El vehiculo %i de placa %s requiere mantenimineto",i,car[i].placa); }
    }
}

void cargar(struct vehiculo car[maxv])
{
    for(int i=0; i<)
}

int main()
{
    struct vehiculo car[maxv];
    matenim(car);
    //mayordic(car);
}

