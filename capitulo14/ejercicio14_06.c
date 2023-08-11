#include <stdio.h>
#define CANT ((int)16)
int longitud(char[]);

int main(void)
{
    char palabra[CANT];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    printf("La longitud es: %d\n", longitud(palabra));

    return 0;
}

int longitud(char v[])
{
    int i = 0;
    while (v[i] != '\0')
    {
        i++;
    }
    return i;
}