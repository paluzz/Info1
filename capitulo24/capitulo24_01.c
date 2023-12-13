#include <stdio.h>
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
    int m[3][3];
    int c = 0;
    int *p = NULL;
    p = &m[0][0];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            *(p + (i * 3) + j) = c;
            c++;
        }
    }

    matrizImprimir(p, 3, 3);
    free(p);
    return 0;
}