#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *traducir(char *str, int *posicion, int posicionCant)
{
    int i, j, z, l = strlen(str), flag = 1;
    char aux[10];
    char mat[25][10];
    char espacio[] = " ";
    char *filtrado = (char *)malloc(sizeof(char) * l);

    if (filtrado == NULL || str == NULL || posicionCant < 1)
    {
        return NULL;
    }

    // copiado str en mat
    for (i = 0, j = 0, z = 0; i < l; i++)
    {
        if (str[i] != ' ')
        {
            aux[j] = str[i];
            j++;
        }
        else
        {
            aux[j] = '\0';
            j = 0;
            // cada palabra en una posicion
            strcpy(mat[z], aux);
            z++;
        }
    }
    i = 0, j = 1;
    // buscamos el orden y armamos el string
    while (flag)
    {
        // reiniciamos loop
        if (i == posicionCant)
        {
            i = 0;
        }

        // si encontramos el orden
        if (posicion[i] == j)
        {
            // lo ponemos en el string
            strcat(filtrado, mat[i]);
            strcat(filtrado, espacio);
            j++;
        }
        i++;

        // Condicion de salida
        if (j == posicionCant)
        {
            flag = 0;
        }
    }
    return filtrado;
}

int main(void)
{
    char frase[] = "aca de dos dos el el ella estos exnovio Gachi hay mas mira novio O Pachi que que Sagitario sea son tambien y ya yo ";
    int orden[] = {4, 5, 2, 25, 18, 20, 17, 24, 21, 15, 9, 3, 1, 19, 10, 16, 8, 12, 6, 11, 14, 7, 23, 13, 22};
    int tamano = 25;
    char *traducido = traducir(frase, orden, tamano);

    printf("Traducido: %s\n", traducido);
    free(traducido);
    return 0;
}