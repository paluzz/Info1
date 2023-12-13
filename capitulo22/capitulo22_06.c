#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    int r, i, *n = NULL, *nm = NULL;
    n = (int *)malloc(sizeof(n) * 1);
    if (n == NULL)
    {
        printf("Error memoria\n");
        return -2;
    }
    fp = fopen("entero.bin", "r");
    if (fp == NULL)
    {
        printf("Error al abrir archivo\n");
        return -1;
    }

    for (i = 0; i < 10; i++)
    {
        r = fread(&n[i], sizeof(n[0]), 1, fp);
        if (r < 0)
        {
            printf("error escritura\n");
            return -1;
        }
        else
        {
            nm = (int *)realloc(n, sizeof(nm) * (i + 1));
            if (nm != NULL)
            {
                n = nm;
            }
        }
    }

    // imprimimos vector
    for (i = 0; i < 10; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
    // imprimimos hexa
    for (i = 0; i < 10; i++)
    {
        printf("%02x ", n[i]);
    }
    printf("\n");

    free(n);
    fclose(fp);
    return 0;
}