#include <stdio.h>

int main(int args, char *argv[])
{
    if (args != 2)
    {
        printf("Uso: %s <archivo>\n", argv[0]);
        return -1;
    }

    FILE *fp;
    char *archivo = argv[1];
    int tam = 0;

    fp = fopen(archivo, "r");
    if (fp == NULL)
    {
        printf("Error '%s' no encontrado\n", archivo);
        printf("Uso: %s <archivo>\n", argv[0]);
        return -2;
    }

    // puntero al final del archivo
    fseek(fp, 0, SEEK_END);
    // cantidad de caracteres --> 1 char = 1 byte
    tam = ftell(fp);
    if (tam < 0)
    {
        printf("Error al obtener el tamaño del archivo\n");
        return -3;
    }
    printf("El tamaño es: %d Bytes\n", tam);

    fclose(fp);

    return 0;
}