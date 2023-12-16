#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *traducir(char *str, int *posicion, int posicionCant)
{
    int l = strlen(str);
    int i, j, k, space = -1, z, num;
    char *traduccion;
    traduccion = (char *)malloc(sizeof(char) * l);
    char aux[10];
    char espacio[] = " ";

    // buscamos posicion del vector menor

    // no llegue a tiempo, aqui deberia usar un while
    for (z = 0, num = 1; z < posicionCant; z++)
    {
        if (num == posicion[z])
        {
            printf("num = %d %d\n", num, z);
            // recorremos string
            for (i = 0, j = 0, k = 0; i < l; i++)
            {
                // copiamos el string en aux
                if (str[i] != ' ')
                {
                    aux[j] = str[i];
                    j++;
                }
                else
                {
                    space++;
                    aux[j] = '\0';
                    j = 0;
                    printf("space = %d\n", space);
                    if (z == space)
                    {
                        printf("aux = %s\n", aux);
                        strcat(traduccion, aux);
                        strcat(traduccion, espacio);
                        k++;
                    }
                }
            }
            num++;
        }
    }

    return traduccion;
}

int main(void)
{
    char mensaje[] = "aca de dos dos el el ella estos exnovio Gachi hay mas mira novio O Pachi que que Sagitario sea son tambien y ya yo ";
    int posicion[] = {4, 5, 2, 25, 18, 20, 17, 24, 21, 15, 9, 3, 1, 19, 10, 16, 8, 12, 6, 11, 14, 7, 23, 13, 22};
    int cant = 25;

    printf("mensaje: %s\n", traducir(mensaje, posicion, cant));

    return 0;
}
