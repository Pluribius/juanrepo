#include <iostream>
#include <stdio.h>
#include <windows.h>
#define max 8

void leer(int arr[max][max],int x)
{
    printf("subrutina de llenar\n");
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("[%i][%i]: ",i,j);
            scanf("%i",arr[i][j]);
            printf("\n");
        }
        
    }
    
}
void imprimir(int arr[max][max],int x)
{
    printf("subrutina de imprimir\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("[%i]",arr[i][j]);
        }
        printf("\n");
    }
}
void ordenar(int arr[max][max],int x)
{
    printf("subrutina de ordenar\n");
}
void exportar(int arr[max][max],int x)
{
    printf("subrutina de exportar\n");
}
void importar(int arr[max][max],int x)
{
    printf("subrutina de importar\n");
}

int main()
{
    int arr[max][max];
    int x=0;
    redo:printf("introduzca el tamaño de la matriz\n");
    scanf("%i",&x);
    if((x<0)||(x>max))
    {
        printf("variable invalida\n");
        goto redo;
    }

    leer(arr,x);
     system("cls");
    printf("matriz introducida");
    imprimir(arr,x);

}