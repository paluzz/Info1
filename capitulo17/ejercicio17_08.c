#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int reemplazaStr(char *str, char *strBuscar, char *strNueva)
{
    int longitud = strlen(str), contador = 0, i;
    int longBuscar = strlen(strBuscar);
    int longNueva = strlen(strNueva);
    char aux[longitud], *p;
    p = strstr(str, strBuscar);

    while (p != NULL)
    {
        // guardamos el string despues de la palabra buscada
        for (i = 0; *(p + i + longBuscar) != '\0'; i++)
        {
            *(aux + i) = *(p + i + longBuscar);
        }
        aux[i] = '\0';
        // reemplazamos la palbra deseada
        for (i = 0; i < longNueva; i++)
        {
            *(p + i) = *(strNueva + i);
        }
        // le pegamos el string guardado anteriormente
        for (i = 0; *(aux + i) != '\0'; i++)
        {
            *(p + i + longNueva) = *(aux + i);
        }

        p[i + longNueva] = '\0';
        contador++;

        p = strstr(str, strBuscar);
    }

    return contador;
}
int main(void)
{
    char str[100] = "texto zorro texto gato perro perrotexto perro zorro texto zorro gato";
    char *buscar[] = {"texto", "gato", "perro", "zorro", " "};
    char *nueva[] = {"nuevo", "cambio", "loro", "chanchito", "__"};
    int cantidad;

    for (int i = 0; i < 5; i++)
    {
        printf("Str '%s': %s\n", buscar[i], str);
        cantidad = reemplazaStr(str, buscar[i], nueva[i]);
        printf("Str '%s': %s\n", nueva[i], str);
        printf("Cantidad de veces reemplazado: %d\n\n", cantidad);
        strcpy(str, "texto zorro texto gato perro perrotexto perro zorro texto zorro gato");
    }

    return 0;
}