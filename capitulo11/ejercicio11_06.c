#include <stdio.h>

int main(void)
{
    int input, acumulador = 0;

    while (acumulador < 100)
    {
        printf("Ingrese numero: ");
        scanf("%d", &input);

        if ((acumulador + input) <= 100)
        {
            acumulador += input;
        }
        else
        {
            break;
        }
    }

    printf("%d\n", acumulador);

    return 0;
}