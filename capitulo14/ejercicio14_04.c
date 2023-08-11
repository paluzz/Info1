#include <stdio.h>
#define CANT ((int)10)
void imprimir(int v[], int);

int main(void)
{
    int naturales[CANT], negativos[CANT], par[CANT], impar[CANT];
    int input, i = 0, j = 0, k = 0, w = 0, contador = 0;

    while (contador < CANT)
    {
        printf("Ingrese numero: ");
        scanf("%d", &input);

        if (input >= 0)
        {
            naturales[i] = input;

            if ((input % 2) == 0)
            {
                par[j] = input;
                j++;
            }
            else
            {
                impar[k] = input;
                k++;
            }
            i++;
        }
        else
        {
            negativos[w] = input;

            if ((input % 2) == 0)
            {
                par[j] = input;
                j++;
            }
            else
            {
                impar[k] = input;
                k++;
            }
            w++;
        }
        contador++;
    }

    printf("Hay %d Positivos y son: ", i);
    imprimir(naturales, i);
    printf("Hay %d Negativos y son: ", w);
    imprimir(negativos, w);
    printf("Hay %d Pares y son: ", j);
    imprimir(par, j);
    printf("Hay %d impares y son: ", k);
    imprimir(impar, k);

    return 0;
}

void imprimir(int v[], int longitud)
{

    int i = 0;
    while (i < longitud)
    {
        printf("%d ", v[i]);
        i++;
    }
    printf("\n");
}
