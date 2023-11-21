#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_ARREGLO 10000
#define REPETICIONES 100

// Implementación del algoritmo Insertion Sort
void insertionSort(int arreglo[], int tamano) 
{
    int i, bandera, j;
    for (i = 1; i < tamano; i++) {
        bandera = arreglo[i];
        j = i - 1;

        while (j >= 0 && arreglo[j] > bandera) {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = bandera;
    }
}

// Implementación del algoritmo Quick Sort
void intercambiar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int arreglo[], int bajo, int alto) {
    int pivote = arreglo[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        if (arreglo[j] < pivote) {
            i++;
            intercambiar(&arreglo[i], &arreglo[j]);
        }
    }
    intercambiar(&arreglo[i + 1], &arreglo[alto]);
    return (i + 1);
}

void quickSort(int arreglo[], int bajo, int alto) {
    if (bajo < alto) {
        int indicePivote = particionar(arreglo, bajo, alto);

        quickSort(arreglo, bajo, indicePivote - 1);
        quickSort(arreglo, indicePivote + 1, alto);
    }
}

// Implementación del algoritmo Bubble Sort
void bubbleSort(int arreglo[], int tamano) {
    for (int i = 0; i < tamano - 1; i++) {
        for (int j = 0; j < tamano - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                intercambiar(&arreglo[j], &arreglo[j + 1]);
            }
        }
    }
}

// Función para calcular el tiempo de ejecución en milisegundos
double calcularTiempo(clock_t inicio, clock_t fin) {
    return ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
}

int main() {
    int arregloInsertion[TAMANO_ARREGLO];
    int arregloQuick[TAMANO_ARREGLO];
    int arregloBubble[TAMANO_ARREGLO];

    // Genera un arreglo aleatorio de 10,000 elementos
    for (int i = 0; i < TAMANO_ARREGLO; i++) {
        arregloInsertion[i] = arregloQuick[i] = arregloBubble[i] = rand() % 10000;
    }

    // Ejecuta 100 ordenamientos independientes para Insertion Sort
    double tiemposInsertion[REPETICIONES];
    for (int i = 0; i < REPETICIONES; i++) {
        clock_t inicioInsertion = clock();
        insertionSort(arregloInsertion, TAMANO_ARREGLO);
        clock_t finInsertion = clock();

        tiemposInsertion[i] = calcularTiempo(inicioInsertion, finInsertion);
    }

    // Ejecuta 100 ordenamientos independientes para Quick Sort
    double tiemposQuick[REPETICIONES];
    for (int i = 0; i < REPETICIONES; i++) {
        clock_t inicioQuick = clock();
        quickSort(arregloQuick, 0, TAMANO_ARREGLO - 1);
        clock_t finQuick = clock();

        tiemposQuick[i] = calcularTiempo(inicioQuick, finQuick);
    }

    // Ejecuta 100 ordenamientos independientes para Bubble Sort
    double tiemposBubble[REPETICIONES];
    for (int i = 0; i < REPETICIONES; i++) {
        clock_t inicioBubble = clock();
        bubbleSort(arregloBubble, TAMANO_ARREGLO);
        clock_t finBubble = clock();

        tiemposBubble[i] = calcularTiempo(inicioBubble, finBubble);
    }

    // Calcula y presenta estadísticas resumidas para Insertion Sort
    double promedioInsertion = 0, minInsertion = tiemposInsertion[0], maxInsertion = tiemposInsertion[0];
    for (int i = 0; i < REPETICIONES; i++) {
        promedioInsertion += tiemposInsertion[i];

        if (tiemposInsertion[i] < minInsertion) {
            minInsertion = tiemposInsertion[i];
        }

        if (tiemposInsertion[i] > maxInsertion) {
            maxInsertion = tiemposInsertion[i];
        }
    }
    promedioInsertion /= REPETICIONES;

    printf("Insertion Sort:\n");
    printf("Promedio: %.6f segundos\n", promedioInsertion);
    printf("Minimo: %.6f segundos\n", minInsertion);
    printf("Maximo: %.6f ms\n", maxInsertion);

    // Calcula y presenta estadísticas resumidas para Quick Sort
    double promedioQuick = 0, minQuick = tiemposQuick[0], maxQuick = tiemposQuick[0];
    for (int i = 0; i < REPETICIONES; i++) {
        promedioQuick += tiemposQuick[i];

        if (tiemposQuick[i] < minQuick) {
            minQuick = tiemposQuick[i];
        }

        if (tiemposQuick[i] > maxQuick) {
            maxQuick = tiemposQuick[i];
        }
    }
    promedioQuick /= REPETICIONES;

    printf("\nQuick Sort:\n");
    printf("Promedio: %.6f segundos\n", promedioQuick);
    printf("Minimo: %.6f segundos\n", minQuick);
    printf("Máximo: %.6f segundos\n", maxQuick);

    // Calcula y presenta estadísticas resumidas para Bubble Sort
    double promedioBubble = 0, minBubble = tiemposBubble[0], maxBubble = tiemposBubble[0];
    for (int i = 0; i < REPETICIONES; i++) {
        promedioBubble += tiemposBubble[i];

        if (tiemposBubble[i] < minBubble) {
            minBubble = tiemposBubble[i];
        }

        if (tiemposBubble[i] > maxBubble) {
            maxBubble = tiemposBubble[i];
        }
    }
    promedioBubble /= REPETICIONES;

    printf("\nBubble Sort:\n");
    printf("Promedio: %.6f segundos\n", promedioBubble);
    printf("Mínimo: %.6f segundos\n", minBubble);
    printf("Máximo: %.6f segundos\n", maxBubble);

    return 0;
}


