#include <stdio.h>
#define CANT ((int)16)
#define TRUE ((int)1)
#define FALSE ((int)0)

int longitud(char[]);
int igualdad(char[], char[]);
int alfabeto(char[], char[]);

int main(void)
{
    char palabraUno[CANT], palabraDos[CANT];

    printf("Ingrese una palabra: ");
    scanf("%s", palabraUno);
    printf("Ingrese otra palabra: ");
    scanf("%s", palabraDos);

    if (igualdad(palabraUno, palabraDos) == TRUE)
    {
        printf("Las dos palabras son iguales\n");
    }
    else
    {
        if (alfabeto(palabraUno, palabraDos) == TRUE)
        {
            printf("El orden alfabetico es %s, %s\n", palabraUno, palabraDos);
        }
        else
        {
            printf("El orden alfabetico es %s, %s\n", palabraDos, palabraUno);
        }
    }

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

int igualdad(char a[], char b[])
{
    int status = TRUE, i = 0;
    int longA = longitud(a), longB = longitud(b);
    if (longA == longB)
    {
        while (i < longA)
        {
            if (a[i] != b[i])
            {
                status = FALSE;
                i = longA;
            }
            i++;
        }
    }
    else
    {
        status = FALSE;
    }

    return status;
}

int alfabeto(char a[], char b[])
{
    int status = TRUE, size;
    int longA = longitud(a), longB = longitud(b);

    if (longA < longB)
    {
        size = longA;
    }
    else
    {
        size = longB;
    }

    for (int i = 0; i < size; i++)
    {
        if (a[i] < b[i])
        {
            status = TRUE;
            i = size;
        }
        else if (a[i] > b[i])
        {
            status = FALSE;
            i = size;
        }
    }
    return status;
}
