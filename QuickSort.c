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
int *geraVetorCrescente(int n)
{
    int i;
    int *A;
    A = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        A[i] = i;
    }
    return A;
}
void imprimeVetor(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void exchange(int *array, int i, int j)
{
    int key = array[i];
    array[i] = array[j];
    array[j] = key;
}

int partition(int *array, int p, int r)
{
    int x = array[r];
    int i = p;

    for (int j = p; j < r; j++)
    {
        if (array[j] <= x)
        {

            exchange(array, i, j);
            i++;
        }
        exchange(array, i + 1, r);
    }
    return i + 1;
}

void quicksort(int *array, int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quicksort(array, p, q - 1);
        quicksort(array, q + 1, r);
    }
}

int main()
{

    int *array;

    int size;
    clock_t start;
    clock_t end;

    size = 20;

    array = geraVetorDecrescente(size);
    imprimeVetor(array, size);
    start = clock();
    quicksort(array, 0, (size - 1));
    end = clock();
    imprimeVetor(array, size);

    printf("time: %lf\n", (double)(end - start) / (double)CLOCKS_PER_SEC);

    free(array);

    return 0;
}