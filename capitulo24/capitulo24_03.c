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

int matrizEscribir(char *nombre, int *p, int filas, int columnas)
{
    if (p == NULL || nombre == NULL)
    {
        return -1;
    }

    int cantWrite;
    FILE *fp;
    fp = fopen(nombre, "w");
    if (fp == NULL)
    {
        return -2;
    }

    cantWrite = fwrite(p, sizeof(*p), (filas * columnas), fp);
    if (cantWrite < 0)
    {
        return -3;
    }

    fclose(fp);
    return 1;
}
int main(void)
{
    int *q = matrizCrear(3, 3);

    int c = matrizEscribir("matriz.txt", q, 3, 3);
    if (c > 0)
    {
        printf("Matriz guardada exitosamente\n");
        free(q);
    }
    return 0;
}