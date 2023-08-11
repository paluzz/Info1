#include <stdio.h>

int main(void)
{
    float num1;
    int entero;

    printf("Ingrese un numero: ");
    scanf("%f", &num1);

    entero = (int)num1;
    printf("La parte entera es %d\n", entero);
    printf("La parte decimal es: %f\n", num1 - (float)entero);

    return 0;
}