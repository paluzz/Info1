#include <stdio.h>
#define NUMEROS ((int)10)

int main(void)
{
    int input, mayor = -999, menor = 999;

    for (int i = 0; i < NUMEROS; i++)
    {

        printf("Ingrese un numero: ");
        scanf("%d", &input);

        if (input > mayor)
        {
            mayor = input;
        }
        else if (input < menor)
        {
            menor = input;
        }
    }

    printf("El numero Mayor es : %d \nEl numero Menor es: %d \n", mayor, menor);

    return 0;
}