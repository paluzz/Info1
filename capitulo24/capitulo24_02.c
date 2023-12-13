#include <stdio.h>
#include <stdlib.h>

int *matrizCrear(int filas, int columnas)
{
    int *p;
    p = (int *)malloc(sizeof(int) * (filas * columnas));
    if (p == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(p + (i * columnas) + j) = 0;
        }
    }
    return p;
}

void matrizImprimir(int *p, int filas, int columnas)
{
    if (p != NULL)
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                printf("%d\t", *(p + (i * columnas) + j));
            }
            printf("\n");
        }
    }
}

int main(void)
{
    int *q = matrizCrear(3, 3);
    matrizImprimir(q, 3, 3);

    free(q);
    return 0;
}