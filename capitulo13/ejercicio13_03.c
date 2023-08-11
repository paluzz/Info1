#include <stdio.h>

char mayuscula(char);
char minuscula(char);
char numero(char);
int filtroASCII(char);

int main(void)
{
    char c;
    printf("Ingrese caracter: ");
    scanf("%c", &c);

    printf("Return: %d\n", filtroASCII(c));

    return 0;
}

char mayuscula(char c)
{
    return (c >= 'A' && c <= 'Z') ? c : -1;
}
char minuscula(char c)
{
    return (c >= 'a' && c <= 'z') ? c : -1;
}
char numero(char c)
{
    return (c >= '0' && c <= '9') ? c : -1;
}

int filtroASCII(char caracter)
{
    int filtro;
    if (caracter == mayuscula(caracter))
    {
        filtro = 0;
    }
    else if (caracter == minuscula(caracter))
    {
        filtro = 1;
    }
    else if (caracter == numero(caracter))
    {
        filtro = 2;
    }
    else
    {
        filtro = 3;
    }

    return filtro;
}
