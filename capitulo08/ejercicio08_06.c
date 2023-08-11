#include <stdio.h>

int main(void)
{
    int entero;

    printf("Ingrese un numero: ");
    scanf("%d", &entero);

    printf("El numero ingresado fue %d (decimal), 0x%x (hexagesimal) , 0%o (octal)\n", entero, entero, entero);

    return 0;
}