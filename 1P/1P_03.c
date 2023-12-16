#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CANT 3
char *odlaw(char *dibujo, char *wally0, char *wally1)
{
    // recorrerlo
    char *p, *q;
    int l = strlen(wally0), distancia = 0;
    p = strstr(dibujo, wally0);

    if (p != NULL)
    {
        q = strstr(dibujo, wally1);
        if (q != NULL)
        {
            distancia = ((q) - (p + l));
            printf("distancia: %d\n", distancia);
            if (distancia == CANT)
            {
                return p;
            }
        }
    }
    return NULL;
}

int main(void)
{
    char *p;
    // char dibujo[] = "___AAA123ZZZ_____"; // OK
    // char dibujo[] = "___AAA1234ZZZ_____"; // NO OK
    char dibujo[] = "___AAA1234_____"; // NO OK
    char wally0[] = "AAA";
    char wally1[] = "ZZZ";

    p = odlaw(dibujo, wally0, wally1);

    if (p == NULL)
    {
        printf("No lo encontre \n");
    }
    else
    {
        printf("impresion: %s\n", p);
    }

    return 0;
}
