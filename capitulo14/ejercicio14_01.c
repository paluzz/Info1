#include <stdio.h>
#define CANT ((int)27)
#define Ñ ((char)241)
// Como 'ñ' tiraba "warning Wmultichar", uso el codigo en ASCII
// prototipos
void imprimir(char[]);
void alfabeto(char[]);

int main(void)
{
    char v[CANT];

    alfabeto(v);

    imprimir(v);

    return 0;
}

void alfabeto(char v[])
{
    int i = 0;
    for (char letra = 'a'; letra <= 'z'; letra++, i++)
    {
        if (letra != Ñ)
        {
            v[i] = letra;
        }
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