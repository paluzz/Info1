#include <stdio.h>

int main(void)
{
    FILE *fp;
    int n, r, i;
    fp = fopen("entero.bin", "w");
    if (fp == NULL)
    {
        printf("Error al abrir archivo\n");
        return -1;
    }

    for (i = 0; i < 10; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &n);
        r = fwrite(&n, sizeof(n), 1, fp);
        if (r < 0)
        {
            printf("error escritura\n");
            return -1;
        }
    }

    fclose(fp);
    return 0;
}