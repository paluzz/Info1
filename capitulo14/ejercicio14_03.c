#include <stdio.h>
#define CANT ((int)100)
#define FALSE ((int)-999)

float rango(float a, float b, float c);

int main(void)
{
    float alturas[CANT], h1, h2;
    int contador = 0, i = 0, flag = 0;

    while (!flag)
    {
        printf("Ingrese alturas en metros #%d: ", i + 1);
        scanf("%f", &alturas[i]);

        if ((alturas[i] < 0) || (i == CANT))
        {
            flag = 1;
        }
        else
        {
            i++;
        }
    }

    printf("Ingrese intervalo de altura #1: ");
    scanf("%f", &h1);
    printf("Ingrese intervalo de altura #2: ");
    scanf("%f", &h2);

    if ((h1 == h2) || (h1 < 0) || (h2 < 0))
    {
        printf("Rango invalido.\n");
    }
    else
    {
        i = 0;
        while (alturas[i] != '\0')
        {
            if (alturas[i] == rango(alturas[i], h1, h2))
            {
                contador++;
            }
            i++;
        }
        if (h1 < h2)
        {
            printf("La cantidad de personas en el rango de %.2fm y %.2fm son: %d\n", h1, h2, contador);
        }
        else
        {
            printf("La cantidad de personas en el rango de %.2fm y %.2fm son: %d\n", h2, h1, contador);
        }
    }

    return 0;
}

float rango(float a, float b, float c)
{
    float t;
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
    return (a >= b && a <= c) ? a : FALSE;
}