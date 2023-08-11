#include <stdio.h>
#include <stdlib.h>
#define PRIMO ((int)1)
#define ERROR ((int)-1)

void imprimirVector(int v[], int longitud)
{

    int i = 0;
    while (i < longitud)
    {
        printf("%d ", v[i]);
        i++;
    }
    printf("\n");
}
int esPrimo(int n)
{
    int primo = 1;
    if (n <= 0)
    {
        primo = -1;
    }
    else if (n == 1)
    {
        primo = 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if ((n % i) == 0)
            {
                primo = 0;
                break;
            }
        }
    }

    return primo;
}

int *calcularPrimos(int n, int *cant)
{
    if (n <= 1)
    {
        return NULL;
    }
    int contador = 0;
    int *primo, *primoRllc;
    primo = (int *)malloc(sizeof(int));
    if (primo == NULL)
    {
        return NULL;
    }

    for (int i = 0; i <= n; i++)
    {
        if (PRIMO == esPrimo(i))
        {
            primo[contador] = i;
            contador++;
            primoRllc = (int *)realloc(primo, sizeof(int *) * (contador));
            primo = primoRllc;
        }
    }
    *cant = contador;
    return primo;
}

int main(void)
{
    int cant;
    int num;
    int *primos;
    printf("Ingrese numero limite: ");
    scanf("%d", &num);
    primos = calcularPrimos(num, &cant);

    if (primos == NULL)
    {
        printf("ERROR\n");
    }
    else
    {
        imprimirVector(primos, cant);
    }
    free(primos);

    return 0;
}