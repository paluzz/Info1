#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int leerTexto(char *nombre, char **textoPtr)
{
    int lineas = 0, read, l;
    char contenido[100];
    char *str = NULL;
    str = *textoPtr;

    FILE *fp;
    fp = fopen(nombre, "r");
    if (fp == NULL)
    {
        printf("Error apertura\n");
        return -1;
    }

    for (int i = 0; i < 4; i++)
    {
        read = fscanf(fp, "%s\r\n", contenido);
        if (read < 0)
        {
            printf("Error lectura\n");
            return -2;
        }

        l = strlen(contenido);
        contenido[l] = '\0';

        str = (char *)malloc(sizeof(char) * (l + 1));
        if (str == NULL)
        {
            printf("Error memoria\n");
            return -3;
        }

        strcpy(str, contenido);
        *(textoPtr + i) = str;
        lineas++;
    }
    fclose(fp);

    return lineas;
}
int main(int args, char *argv[])
{
    if (args != 2)
    {
        printf("Uso: %s  <archivo>\n", argv[0]);
        return -1;
    }

    char *texto[4];
    char *archivo = argv[1];
    int lineas;
    lineas = leerTexto(archivo, texto);

    if (lineas > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%s\r\n", texto[i]);
            free(texto[i]);
        }
    }

    return 0;
}