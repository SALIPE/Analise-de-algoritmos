#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "commons.h"

void insertionSort(int n, int *v)
{

    for (int j = 1; j < n; j++)
    {
        int x = v[j];
        int i;
        for (i = j - 1; i >= 0 && v[i] > x; i--)
        {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main()
{
    int *array;

    int size, i, sorted, q;
    clock_t start;
    clock_t end;

    size = 20;

    array = geraVetorDecrescente(size);

    printf("Vetor antes:\n");
    imprimeVetor(array, size);

    start = clock();
    insertionSort(size, array);
    end = clock();

    printf("Vetor depois:\n");
    imprimeVetor(array, size);

    printf("time: %lf\n", (double)(end - start) / (double)CLOCKS_PER_SEC);

    free(array);

    return 0;
}