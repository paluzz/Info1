#include <stdio.h>

int main(void)
{
    int entero = 0xA;

    printf("Ingrese un numero en HEXADECIMAL: ");
    scanf("%x", &entero);

    printf("El numero ingresado fue 0x%x (hexadecimal), %d (decimal) , 0%o (octal)\n", entero, entero, entero);

    return 0;
}