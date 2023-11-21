#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaBinaria(int lista[], int numElementos, int elemento);
int busquedaSecuencial(int lista[], int numElementos, int elemento);

int main() 
{
    int i,numeroBuscar;

    srand(time(NULL));
    int lista[50000];

    printf("Lista sin ordenar: \n\n");

    for (i = 0; i < 50000; i++) 
	{
        lista[i] = rand() % 50000;
        //printf("%d, ", lista[i]);
    }
    printf("\n\n");
    
	elemento=rand() % 50000;
    printf("Elemento a buscar: %d",elemento);
    

    
    // Llamada a la función de búsqueda binaria
    
	for (int i = 0; i < 100; i++)
	{
		lock_t tic = clock();
		posicion = busquedaBinaria(lista, num, elemento);
		clock_t toc = clock();// Termina cronómetro
    	printf("\nTiempo de ejecucion vuelta %d: %f segundos\n",i, (double)(toc - tic) / CLOCKS_PER_SEC);	
	}

    
    if (posicion != -1) 
	{
        printf("Posicion:%d\n", posicion);
    } else 
	{
        printf("Elemento no se encuentra\n");
    }
    
    
    	for (int i = 0; i < 100; i++)
	{
		lock_t tic = clock();
		busquedaSecuencial(lista, num, elemento);
		clock_t toc = clock();// Termina cronómetro
    	printf("\nTiempo de ejecucion vuelta %d: %f segundos\n",i, (double)(toc - tic) / CLOCKS_PER_SEC);	
	}

    
    return 0;
}

int busquedaBinaria(int lista[], int numElementos, int elemento)
 {
    int primero = 0;
    int ultimo = numElementos - 1;
    int mitad;
    
    while (primero <= ultimo) {
        mitad = (primero + ultimo) / 2;
        
        if (lista[mitad] < elemento) {
            primero = mitad + 1;
        } else if (lista[mitad] == elemento) {
            return mitad;  // Devuelve la posición si encuentra el elemento
        } else {
            ultimo = mitad - 1;
        }
    }
    
    return -1;  // Devuelve -1 si el elemento no se encuentra
}

// Función de búsqueda secuencial
int busquedaSecuencial(int lista[], int numElementos, int elemento)
 {
    int bandera = 0;

    for (int i = 0; i < numElementos; i++) {
        if (lista[i] == elemento) {
            printf("Elemento en posicion: %d\n", i + 1);
            bandera = 1;
            break;
        }
    }

    if (bandera == 0) 
	{
        printf("Elemento no se encuentra\n");
    }

    return bandera;
}

