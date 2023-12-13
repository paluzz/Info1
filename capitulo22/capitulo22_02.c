#include <stdio.h>
#include <string.h>
#include "printHex.h"
#define CANT 13
int main(void)
{
    FILE *fp;
    int cantRead, l;
    char str[CANT];

    // abrimos
    fp = fopen("./prueba.txt", "r");
    if (fp == NULL)
    {
        printf("Error al abrir archivo\n");
        return -1;
    }

    // hacemos cosas
    cantRead = fread(&str[0], sizeof(str[0]), CANT, fp);
    if (cantRead < 0)
    {
        printf("Error al leer archivo\n");
        return -1;
    }
    else
    {
        l = strlen(str);
        str[l] = '\0';
        printf("%s\n", str);

        printHex(str, l);
    }
    // cerramos
    fclose(fp);

    return 0;
}
