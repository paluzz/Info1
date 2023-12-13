#include <stdio.h>

int main(void)
{
    FILE *fp;
    int r;
    // abrimos al final del archivo
    fp = fopen("./prueba.txt", "a");
    if (fp == NULL)
    {
        printf("Error al abrir archivo\n");
        return -1;
    }

    r = fwrite("Adios!", 1, 6, fp);
    if (r < 0)
    {
        printf("Error escritura\n");
        return -1;
    }

    fclose(fp);

    return 0;
}