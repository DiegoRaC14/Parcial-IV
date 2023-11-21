/*Programa que cuenta el tiempo de la multiplicación de dos matrices*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int multiplicarMatrices(int matriz1[30][30], int matriz2[30][30], int resultado[30][30]);

int main() 
{
    srand(time(NULL));

    int matriz1[30][30];
    int matriz2[30][30];
    int resultado[30][30];

    printf("\nMatriz 1 de 30x30\n\n");
    for (int i = 0; i < 30; i++) 
	{
        for (int j = 0; j < 30; j++)
		{
            matriz1[i][j] = rand() % 10;
            printf("%d, ", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz 2 de 30x30\n\n");
    for (int i = 0; i < 30; i++) 
	{
        for (int j = 0; j < 30; j++) 
		{
            matriz2[i][j] = rand() % 10;
            printf("%d, ", matriz2[i][j]);
        }
        printf("\n");
    }
	
	//Empieza el benchmark
	clock_t tic = clock();
    multiplicarMatrices(matriz1, matriz2, resultado);//Función que multiplica las matrices

	
    printf("\nResultado de la multiplicacion de las matrices:\n\n");
    for (int i = 0; i < 30; i++) 
	{
        for (int j = 0; j < 30; j++)
		{
            printf("%d, ", resultado[i][j]);
        }
        printf("\n");
    }
 
    clock_t toc = clock();// Termina cronómetro
    printf("\033[31m");
    printf("\nTiempo de ejecucion: %f segundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    printf("\033[0m");
    
    return 0;
}

int multiplicarMatrices(int matriz1[30][30], int matriz2[30][30], int resultado[30][30])//Función que multiplica las matrices
{
    for (int i = 0; i < 30; i++) 
	{
        for (int j = 0; j < 30; j++) 
		{
            resultado[i][j] = 0;
            
			for (int k = 0; k < 30; k++) 
			{
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

