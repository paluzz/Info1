#include <stdio.h>

int main(void)
{
    int num1, num2, division, resto;

    printf("ingrese un numero: ");
    scanf("%d", &num1);
    printf("ingrese un numero: ");
    scanf("%d", &num2);

    if (num2 == 0)
    {
        printf("No se puede dividir por 0\n");
    }
    else
    {
        division = num1 / num2;
        resto = num1 % num2;
        printf("El cociente es: %d\n", division);
        printf("El resto es: %d\n", resto);
    }

    return 0;
}