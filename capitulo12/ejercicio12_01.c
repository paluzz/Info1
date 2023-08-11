#include <stdio.h>
#define CANT ((int)100)

int main(void)
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (numero > CANT)
    {
        printf("El numero %d es mayor a %d\n", numero, CANT);
    }

    return 0;
}