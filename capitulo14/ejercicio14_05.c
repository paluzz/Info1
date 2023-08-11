#include <stdio.h>
#define CANT ((int)16)
#define FALSE ((int)-1)

char minuscula(char);
void toUpperCase(char[]);
void imprimir(char[]);

int main(void)
{
    char palabra[CANT];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    toUpperCase(palabra);
    imprimir(palabra);

    return 0;
}
char minuscula(char c)
{
    return (c >= 'a' && c <= 'z') ? c : FALSE;
}

void toUpperCase(char v[])
{
    int i = 0;
    while (v[i] != '\0')
    {
        if (v[i] == minuscula(v[i]))
        {
            v[i] += ('A' - 'a');
        }
        i++;
    }
}

void imprimir(char v[])
{
    int i = 0;
    while (v[i] != '\0')
    {
        printf("%c", v[i]);
        i++;
    }
    printf("\n");
}