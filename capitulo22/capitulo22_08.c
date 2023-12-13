#include <stdio.h>
#include <stdlib.h>
#include "printHex.h"

int main(int args, char *argv[])
{
    if (args != 2)
    {
        // gcc capitulo22_08.c -o print
        printf("Uso: %s <origen>\n", argv[0]);
        return -1;
    }
    char *origen = argv[1];
    FILE *fp;
    int tam, cantRead;
    char *p = NULL;

    fp = fopen(origen, "r");
    if (fp == NULL)
    {
        printf("error apertura, '%s' no encontrado\n", origen);
        return -2;
    }
    // SEEK_END -> puntero final del archivo
    fseek(fp, 0, SEEK_END);

    // Obtenemos tamaño total del archivo
    tam = ftell(fp);
    if (tam < 0)
    {
        printf("Error al obtener el tamaño del archivo\n");
        fclose(fp);
        return -3;
    }
    // si el tamaño total es impar entonces le agregamos 1+
    if (tam % 2 == 1)
    {
        tam += 1;
    }
    tam /= 2;

    // SEEK_SET -> al principio
    fseek(fp, tam, SEEK_SET);

    p = (char *)malloc(sizeof(*p) * tam);
    if (p == NULL)
    {
        printf("Error memoria\n");
        return -4;
    }

    cantRead = fread(p, sizeof(*p), tam, fp);
    if (cantRead < 0)
    {
        printf("Error lectura\n");
        return -5;
    }

    printHex(p, tam);
    free(p);
    fclose(fp);
    return 0;
}