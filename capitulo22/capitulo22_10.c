#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DATOS "bDatos.bin"
#define NOMBRE_SIZE (32)
struct data_S
{
    char nombre[NOMBRE_SIZE];
    int edad;
};

int main(void)
{
    int cantRead;
    struct data_S data;
    FILE *fp;
    // abrimos archivo
    fp = fopen(DATOS, "r");
    if (fp == NULL)
    {
        printf("Error apertura\n");
        return -1;
    }

    while (!feof(fp))
    {
        // leemos uno por uno
        cantRead = fread(&data, sizeof(struct data_S), 1, fp);
        if (cantRead < 0)
        {
            printf("Error lectura\n");
            return -2;
        }
        // nos aseguramos que haya leido algo
        else if (cantRead > 0)
        {
            // imprimimos uno por uno
            printf("Nombre: %s\n", data.nombre);
            printf("Edad: %d\n", data.edad);
        }
    }

    // cerramos archivo
    fclose(fp);

    return 0;
}