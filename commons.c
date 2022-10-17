#include "commons.h"
#include <stdio.h>
#include <stdlib.h>

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