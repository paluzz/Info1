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
    int i = 0, flag = 0, cantWrite, edad;
    char nombre[NOMBRE_SIZE];
    FILE *fp;
    struct data_S *p = NULL, *rp = NULL;

    p = (struct data_S *)malloc(sizeof(struct data_S));
    if (p == NULL)
    {
        printf("Error al pedir memoria\n");
        return -1;
    }
    // abrimos archivo
    fp = fopen(DATOS, "w");
    if (fp == NULL)
    {
        printf("Error al abrir archivo\n");
        return -2;
    }

    while (!flag)
    {
        printf("Ingrese nombre: ");
        scanf("%s", nombre);
        printf("Ingrese edad: ");
        scanf("%d", &edad);

        // salida
        if (edad == -1)
        {
            flag = 1;
        }
        else
        {
            rp = (struct data_S *)realloc(p, sizeof(struct data_S) * (i + 1));
            if (rp != NULL)
            {
                p = rp;
            }
            strcpy((p + i)->nombre, nombre);
            (p + i)->edad = edad;
            i++;
        }
    }

    // escribimos archivo
    cantWrite = fwrite(p, sizeof(struct data_S), i, fp);
    if (cantWrite < 0 || cantWrite != i)
    {
        printf("Error escritura\n");
        return -4;
    }
    else
    {
        printf("escritura exitosa! \n");
    }

    // liberamos y cerramos
    free(p);
    fclose(fp);

    // me complique la vida usando punteros cuando podria haber escrito uno por uno
    return 0;
}