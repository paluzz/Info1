#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOMBRE_SIZE (32)
#define DATOS "./bDatos.txt"
#define CANT 10
struct data_S
{
    char nombre[NOMBRE_SIZE];
    unsigned int edad;
};

void imprimir(struct data_S *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        printf("%s,%d\r\n", (p + i)->nombre, (p + i)->edad);
    }
}
int main(void)
{
    FILE *fp;
    char nombre[32];
    int i, edad, r;

    struct data_S *p;
    p = (struct data_S *)malloc(sizeof(struct data_S) * CANT);
    if (p == NULL)
    {
        printf("Error memoria\n");
        return -3;
    }

    // abrimos archivo
    fp = fopen(DATOS, "r");
    if (fp == NULL)
    {
        printf("Archivo inexistente\n");
        return -1;
    }

    // hacemos cosas
    for (i = 0; i < CANT; i++)
    {
        // preguntar porque se lee asi el string y xq edad lleva &
        r = fscanf(fp, "%[^,],%d\r\n", nombre, &edad);
        if (r < 0)
        {
            printf("Error lectura");
            return -2;
        }
        else
        {
            strcpy((p + i)->nombre, nombre);
            (p + i)->edad = edad;
        }
    }

    // cerramos
    fclose(fp);

    // imprimimos
    imprimir(p, CANT);

    // liberamos
    free(p);

    return 0;
}