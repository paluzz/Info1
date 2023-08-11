#include <stdio.h>

int main(void)
{
    float number;

    printf("Ingrese numero: ");
    scanf("%f", &number);

    printf("El numero ingresado es: %0.2f\n", number);

    return 0;
}