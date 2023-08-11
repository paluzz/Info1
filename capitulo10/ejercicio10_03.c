#include <stdio.h>

int main(void)
{
    char caracter;

    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);

    if (caracter >= '0' && caracter <= '9')
    {
        printf("Es un número.\n");
    }
    else if (caracter >= 'a' && caracter <= 'z')
    {
        printf("Es una letra minúscula.\n");
    }
    else if (caracter >= 'A' && caracter <= 'Z')
    {
        printf("Es una letra mayúscula.\n");
    }
    else
    {
        printf("Es otro carácter.\n");
    }

    return 0;
}