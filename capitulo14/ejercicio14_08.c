#include <stdio.h>
#define CANT ((int)16)
int longitud(char[]);
void strReplace(char[], char, char);
int strCount(char[], char);

int main(void)
{
    char palabra[CANT], caracter;
    int contador = 0;

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    printf("Ingrese un caracter: ");
    scanf("%*c%c", &caracter);

    contador = strCount(palabra, caracter);
    strReplace(palabra, caracter, '*');

    printf("Se ha cambiado el caracter '%c' unas %d veces\n", caracter, contador);
    printf("La palabra nueva es: %s\n", palabra);
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
void strReplace(char v[], char old, char new)
{
    for (int i = 0; i < longitud(v); i++)
    {
        if (v[i] == old)
        {
            v[i] = new;
        }
    }
}

int strCount(char v[], char c)
{
    int contador = 0;
    for (int i = 0; i < longitud(v); i++)
    {
        if (v[i] == c)
        {
            contador++;
        }
    }
    return contador;
}
