/*
    ESTE ARCHIVO ES PARA GENERAR EL EJEMPLO DE 23_05
*/
#include <stdio.h>
#include <string.h>

int main(int args, char *argv[])
{
    if (args != 2)
    {
        printf("%s  <archivo>\n", argv[0]);
        return -9;
    }
    char *archivo = argv[1];
    char *contenido[50] = {"Hola", "Manzana", "Perro", "Gato"};
    int r;
    FILE *fp;
    fp = fopen(archivo, "w");
    if (fp == NULL)
    {
        printf("Error apertura\n");
        return -1;
    }

    for (int i = 0; i < 4; i++)
    {
        r = fprintf(fp, "%s\r\n", contenido[i]);
        if (r < 0)
        {
            printf("Error\n");
            return -2;
        }
    }

    fclose(fp);

    return 0;
}