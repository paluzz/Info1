#include <stdio.h>

int main(void)
{
    float num1, num2;

    printf("ingrese un numero: ");
    scanf("%f", &num1);
    printf("ingrese un numero: ");
    scanf("%f", &num2);

    printf("La suma de %f y %f es igual a %f\n", num1, num2, num1 + num2);

    return 0;
}