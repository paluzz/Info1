#include <stdio.h>

int main(void)
{
    float floatNum;
    char caracter;
    printf("Ingrese letra: ");
    scanf("%c", &caracter);
    fflush(stdin);
    printf("Ingrese número: ");
    scanf("%f", &floatNum);

    printf("El número ingresado es : %c\n", caracter);
    printf("El número ingresado es : %f\n", floatNum);

    return 0;
}