#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char ruta[50], *p = NULL, *q = NULL, contenido[2000];
    FILE *fp;

    printf("ingrese ruta y nombre del archivo: ");
    fgets(ruta, sizeof(ruta), stdin);

    // filtramos
    p = strchr(ruta, '\x0A');
    if (p != NULL)
    {
        *p = '\0';
    }

    // abrimos archivo
    fp = fopen(ruta, "r");
    if (fp == NULL)
    {
        printf("Ruta incorrecta / archivo inexistente\n");
        return -1;
    }

    // hacemos cosas
    while (!feof(fp))
    {
        q = fgets(contenido, sizeof(contenido), fp);
        if (q == NULL)
        {
            printf("Error contenido\n");
            return -2;
        }
        else
        {
            printf("%s", contenido);
        }
    }
    printf("\n");

    // cerramos
    fclose(fp);
    return 0;
}