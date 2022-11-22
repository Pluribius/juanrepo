#include<iostream>
#include<conio.h>
#include<stdio.h>
#define maxf 3
#define maxc 4 

using namespace std;

/*Realice un programa que permita leer 2 
matrices de 3x4 c/u.
realice un programa que permita ordenar ascendentemente o descendentemente 
segun solicit el usuario. este ordenamiento sera combinado por filas */

void malditasea(int p[maxc*2])
{
   printf("mostrando arreglo temporal \n");
   for (int i = 0; i < maxc*2; i++)
   {
    printf("%i",p[i]); printf(" | ");
   }
   printf("\n");
}

void cargar(int M[maxf][maxc])
{
    

    for(int i=0;i<maxf;i++)
    {
        for(int j=0;j<maxc;j++)
        {
            printf("Ingrese el elemento de la matriz M[%i][%i]:",i,j);
            scanf("%i",&M[i][j]);
        }
    }

}

void llenar(int M[maxf][maxc],int N[maxf][maxc],int p[maxc*2],int n)
{
    int pos=0;
    
   for (int i = 0; i < 4; i++)
   {
    
    p[i]=M[n][i];
    
    pos++;
    printf("pos:%i\n",pos);
   }
   malditasea(p);
   
     for (int i = pos+1; i < 4; i++)
   {
    p[i]=N[n][i];
    
   }
   malditasea(p);
   
}

void vaciar(int M[maxf][maxc],int N[maxf][maxc],int p[maxc*2],int n)
{
        int pos=0;
   for (int i = 0; i < maxc; i++)
   {
    
    M[i][n]=p[i];
    pos++;
    
   }
     for (int i = pos+1; i < maxc; i++)
   {
    N[i][n]=p[i];
    
   }
   
}

void ordenar(int M[maxf][maxc],int N[maxf][maxc])

{
    int i,j,aux,n=0;
    int p[maxc*2];
    int cambio=0;
    do{
        
        llenar(M,N,p,n);
        do 
        {
            cambio=0;
            
            for(i=0;i<maxc*2;i++)
                if(p[i]>p[i+1])
                {
                aux=p[i];
                p[i]=p[i+1];
                p[i+1]=aux;
                cambio=1;
                }

        }while(cambio==1);

    vaciar(M,N,p,n);

    n++;
    }while (n<maxf);
   

}

void imprimir(int m[maxf][maxc])
{
    
    printf("\n");
    for(int i=0;i<maxf;i++)
    {
        printf("\n");
        for(int j=0;j<maxc;j++)
        {

            printf("%i",m[i][j]);
            printf("|");
        }
    }  
    printf("\n");
}

int main()
{
    int a[maxf][maxc],b[maxf][maxc];
    printf("cargue la matriz A\n");
    cargar(a);
    printf("cargue la matriz B\n");
    cargar(b);
    printf("mostrando la matriz A\n");
    imprimir(a);
    printf("mostrando la matriz B\n");
    imprimir(b);


    printf("ordenando...\n");
    ordenar(a,b);
    printf("subrutina terminada\n");
     printf("mostrando la matriz A\n");
    imprimir(a);
    printf("mostrando la matriz B\n");
    imprimir(b);


    
    
   

}