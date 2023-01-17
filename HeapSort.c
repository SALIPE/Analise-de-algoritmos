#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "commons.h"

void maxHeapify(int *v, int raiz, int fundo)
{
    int pronto, filhoMax, tmp;

    pronto = 0;
    while ((raiz * 2 <= fundo) && (!pronto))
    {
        if (raiz * 2 == fundo)
        {
            filhoMax = raiz * 2;
        }
        else if (v[raiz * 2] > v[raiz * 2 + 1])
        {
            filhoMax = raiz * 2;
        }
        else
        {
            filhoMax = raiz * 2 + 1;
        }

        if (v[raiz] < v[filhoMax])
        {
            tmp = v[raiz];
            v[raiz] = v[filhoMax];
            v[filhoMax] = tmp;
            raiz = filhoMax;
        }
        else
        {
            pronto = 1;
        }
    }
}

void buildMaxHeap(int *v, int n)
{
    int i;

    for (i = (n / 2); i >= 0; i--)
    {
        maxHeapify(v, i, n - 1);
    }
}

void heapSort(int *v, int n)
{
    buildMaxHeap(v, n);

    for (int i = n - 1; i >= 1; i--)
    {
        int tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        maxHeapify(v, 0, i - 1);
    }
}

int main()
{

    clock_t start;
    clock_t end;
    int size = 30;

    int *array = geraVetorDecrescente(size);

    printf("Vetor antes:\n");
    imprimeVetor(array, size);

    start = clock();
    heapSort(array, size);
    end = clock();

    printf("Vetor depois:\n");
    imprimeVetor(array, size);

    printf("time: %lf\n", (double)(end - start) / (double)CLOCKS_PER_SEC);

    free(array);

    return 0;
}