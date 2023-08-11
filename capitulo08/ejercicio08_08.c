#include <stdio.h>

int main(void)
{
    char leter;
    printf("Ingrese un caracter: ");
    scanf("%c", &leter);

    printf("El codigo ASCII para la letra '%c' es: %d; 0x%x\n", leter, leter, leter);

    return 0;
}