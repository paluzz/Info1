#include <stdio.h>
#define CERO ((int)0)

int main(void)
{
    int input;
    float factorial = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &input);

    if (input > CERO)
    {
        for (int i = 1; i <= input; i++)
        {
            factorial *= (float)i;
        }
        printf("El factorial de %d es: %.0f\n", input, factorial);
    }
    else if (input == CERO)
    {
        factorial = 1;
        printf("El factorial de %d es: %.0f\n", input, factorial);
    }
    else
    {
        printf("No se puede calcular factorial de negativos\n");
    }

    return 0;
}