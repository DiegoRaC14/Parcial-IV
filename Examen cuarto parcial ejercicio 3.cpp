#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_ARREGLO 50000//Tamaño del arreglo original
#define REPETICIONES 100 //Veces que se repite el programa


int busquedaSecuencial(int arreglo[], int tamano, int elemento);// Implementación de la búsqueda secuencial
int busquedaBinaria(int arreglo[], int inicio, int fin, int elemento);// Implementación de la búsqueda binaria
double calcularTiempo(clock_t inicio, clock_t fin);// Función para calcular el tiempo de ejecución 

int main() 
{
    int arreglo[TAMANO_ARREGLO];

    // Genera un arreglo ordenado de 50,000 elementos
    for (int i = 0; i < TAMANO_ARREGLO; i++) 
	{
        arreglo[i] = i;
    }

    // Inicializa la semilla para generar números aleatorios
    srand(time(NULL));

    // Ejecuta 100 búsquedas independientes para la búsqueda secuencial
    double tiemposSecuencial[REPETICIONES];
    for (int i = 0; i < REPETICIONES; i++) 
	{
        int elementoBuscado = rand() % TAMANO_ARREGLO;

        clock_t inicioSecuencial = clock();
        busquedaSecuencial(arreglo, TAMANO_ARREGLO, elementoBuscado);
        clock_t finSecuencial = clock();

        tiemposSecuencial[i] = calcularTiempo(inicioSecuencial, finSecuencial);
    }

    // Ejecuta 100 búsquedas independientes para la búsqueda binaria
    double tiemposBinaria[REPETICIONES];
    for (int i = 0; i < REPETICIONES; i++) {
        int elementoBuscado = rand() % TAMANO_ARREGLO;

        clock_t inicioBinaria = clock();
        busquedaBinaria(arreglo, 0, TAMANO_ARREGLO - 1, elementoBuscado);
        clock_t finBinaria = clock();

        tiemposBinaria[i] = calcularTiempo(inicioBinaria, finBinaria);
    }

    // Calcula y presenta estadísticas resumidas para la búsqueda secuencial
    double promedioSecuencial = 0, minSecuencial = tiemposSecuencial[0], maxSecuencial = tiemposSecuencial[0];
    for (int i = 0; i < REPETICIONES; i++) {
        promedioSecuencial += tiemposSecuencial[i];

        if (tiemposSecuencial[i] < minSecuencial) {
            minSecuencial = tiemposSecuencial[i];
        }

        if (tiemposSecuencial[i] > maxSecuencial) {
            maxSecuencial = tiemposSecuencial[i];
        }
    }
    promedioSecuencial /= REPETICIONES;

    printf("Busqueda Secuencial:\n");
    printf("Promedio: %.6f segundos\n", promedioSecuencial);
    printf("Minimo: %.6f segundos\n", minSecuencial);
    printf("Maximo: %.6f segundos\n", maxSecuencial);

    // Calcula y presenta estadísticas resumidas para la búsqueda binaria
    double promedioBinaria = 0, minBinaria = tiemposBinaria[0], maxBinaria = tiemposBinaria[0];
    for (int i = 0; i < REPETICIONES; i++) {
        promedioBinaria += tiemposBinaria[i];

        if (tiemposBinaria[i] < minBinaria) {
            minBinaria = tiemposBinaria[i];
        }

        if (tiemposBinaria[i] > maxBinaria) {
            maxBinaria = tiemposBinaria[i];
        }
    }
    promedioBinaria /= REPETICIONES;

    printf("\nBusqueda Binaria:\n");
    printf("Promedio: %.6f segundos\n", promedioBinaria);
    printf("Minimo: %.6f segundos\n", minBinaria);
    printf("Maximo: %.6f segundos\n", maxBinaria);

    return 0;
}

// Implementación de la búsqueda secuencial
int busquedaSecuencial(int arreglo[], int tamano, int elemento) {
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == elemento) {
            return i; // Retorna la posición si se encuentra el elemento
        }
    }
    return -1; // Retorna -1 si no se encuentra el elemento
}

// Implementación de la búsqueda binaria
int busquedaBinaria(int arreglo[], int inicio, int fin, int elemento) 
{
    while (inicio <= fin)
	 {
        int medio = inicio + (fin - inicio) / 2;
        
        if (arreglo[medio] == elemento) {
            return medio; // Retorna la posición si se encuentra el elemento
        }

        if (arreglo[medio] < elemento) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1; // Retorna -1 si no se encuentra el elemento
}

double calcularTiempo(clock_t inicio, clock_t fin) 
{
    return ((double) (fin - inicio) * 1000) / CLOCKS_PER_SEC;
}



