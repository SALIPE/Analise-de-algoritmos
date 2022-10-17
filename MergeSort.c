#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int *geraVetorDecrescente(int n)
{
    int i;
    int *A;
    A = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        A[i] = n - i;
    }
    return A;
}

int *createArray(int size)
{

    int *newAr;
    newAr = malloc(sizeof(int) * (size + 1));
    newAr[size] = INT_MAX;

    return newAr;
}

void imprimeVetor(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void intercale(int *array, int init, int q, int size)
{
    int i, j, k;
    int n1 = q - init + 1;
    int n2 = size - q;

    int *l = createArray(n1);
    int *r = createArray(n2);

    for (i = 0; i < n1; i++)
    {
        l[i] = array[init + i];
    }

    for (j = 0; j < n2; j++)
    {
        r[j] = array[q + j + 1];
    }

    i = 0;
    j = 0;
    for (k = init; k <= size; k++)
    {
        if (l[i] <= r[j])
        {
            array[k] = l[i];
            i++;
        }
        else
        {
            array[k] = r[j];
            j++;
        }
    }
}

void mergeSort(int *array, int init, int size)
{
    int q;
    if (init < size)
    {
        q = (init + size) / 2;
        mergeSort(array, init, q);
        mergeSort(array, (q + 1), size);
        intercale(array, init, q, size);
    }
}

int main()
{

    int *array;

    int size;
    clock_t start;
    clock_t end;

    size = 120000;

    array = geraVetorDecrescente(size);
    // imprimeVetor(array, size);
    start = clock();
    mergeSort(array, 0, (size - 1));
    end = clock();
    // imprimeVetor(array, size);

    printf("time: %lf\n", (double)(end - start) / (double)CLOCKS_PER_SEC);

    free(array);

    return 0;
}