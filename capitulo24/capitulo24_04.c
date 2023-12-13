#include <stdio.h>
#include <stdlib.h>

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
int matrizLeer(char *nombre, int *p, int filas, int columnas)
{

    if (nombre == NULL)
    {
        return -2;
    }

    int cantRead;
    FILE *fp;
    int *q = NULL;

    q = malloc(sizeof(int) * (filas * columnas));
    if (q == NULL)
    {
        return -1;
    }

    fp = fopen(nombre, "r");
    if (fp == NULL)
    {
        return -3;
    }

    cantRead = fread(q, sizeof(*q), (filas * columnas), fp);
    if (cantRead < 0)
    {
        return -4;
    }
    else
    {
        p = q;
    }
    return 1;
}
int main(void)
{
    int m[3][3];
    int *q;
    q = &m[0][0];
    int c = matrizLeer("matriz.txt", q, 3, 3);

    if (c > 0)
    {
        matrizImprimir(q, 3, 3);
    }

    return 0;
}