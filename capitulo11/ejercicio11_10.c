#include <stdio.h>

int main(void)
{
    int input, numero, digitos = 0;

    printf("Ingrese un numero: ");
    scanf("%d", &input);

    numero = input;

    while (numero != 0)
    {
        numero /= 10;
        digitos++;
    }
    printf("El numero %d tiene %d digitos\n", input, digitos);

    return 0;
}