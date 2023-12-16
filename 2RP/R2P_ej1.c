#include <stdio.h>
#include <stdlib.h>

float pasajePromedio(char *archivoViajes, float *tarifa, int *viajes, int tarifaCant)
{

    if (archivoViajes == NULL)
    {
        printf("nombre incorrecto\n");
        return -1;
    }
    // leer archivo separado con puntos y comas ---- cant viajes
    FILE *fp;
    int r, i = 0;
    float prom = 0;
    int valores[100];
    fp = fopen(archivoViajes, "r");
    if (fp == NULL)
    {
        printf("error apertura\n");
        return -1;
    }

    // leemos el archivo
    while (!feof(fp))
    {
        r = fscanf(fp, "%d;", &valores[i]);
        i++;
        if (r < 0)
        {
            printf("Error lectura\n");
        }
    }

    for (int j = 0; j < i; j++)
    {
        printf("valores: %d\n", valores[j]);
    }

    // cerramos archivo
    fclose(fp);

    for (int j = 0; j < i; j++)
    {
        prom += (float)(valores[j]);
    }
    prom /= i;

    return prom;
}

int main()
{

    float tarifa[] = {80, 64, 56, 48};
    int viajes[] = {1, 21, 31, 41};
    float prom;

    // prom = pasajePromedio("",tarifa,viajes,20);
    prom = pasajePromedio("tarifaViajes.txt", tarifa, viajes, 20);
    // prom = pasajePromedio("tarifaViajes.txt",tarifa,viajes,5);
    // prom = pasajePromedio("tarifaViajes.txt",tarifa,viajes,50);
    // prom = pasajePromedio("tarifaViajes.txt",tarifa,viajes,15);
    printf("El prom es: %0.2f\n", prom);
    return 0;
}
