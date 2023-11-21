#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función de ordenamiento por inserción


int main() 
{
    int i, n;

    srand(time(NULL));
    printf("Numero de elementos a ordenar: ");
    scanf("%d", &n);
    int lista[10000];

    printf("\nLista sin ordenar: \n\n");

    for (i = 0; i < n; i++) 
	{
        lista[i] = rand() % 10000;
        printf("%d, ", lista[i]);
    }
    printf("\n\n");

    // Llamada a la función de ordenamiento por inserción
    ordenamientoInsercion(lista, n);

    printf("Lista ordenada: \n");
    for (i = 0; i < n; i++) {
        printf("%d, ", lista[i]);
    }

    return 0;
}

void ordenamientoInsercion(int lista[], int numElementos);
{
    int i, posAnterior, numeroActual;

    for (i = 0; i < numElementos; i++) {
        numeroActual = lista[i];
        posAnterior = i - 1;

        while (posAnterior >= 0 && lista[posAnterior] > numeroActual) {
            lista[posAnterior + 1] = lista[posAnterior];
            posAnterior--;
        }

        lista[posAnterior + 1] = numeroActual;
    }
}
