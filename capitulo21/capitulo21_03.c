#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    int i, r;

    // abrimos archivo
    fp = fopen("./prueba.txt", "w");
    if (fp == NULL)
    {
        printf("Error al abrir archivo \n");
        return -1;
    }

    // modificamos
    for (i = 1; i < 100; i += 2)
    {
        r = fprintf(fp, "%d ", i);
        if (r < 0)
        {
            printf("error de escritura\n");
            return -2;
        }
    }

    // cerramos
    fclose(fp);

    return 0;
}