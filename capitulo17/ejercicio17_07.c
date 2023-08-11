#include <stdio.h>
#include <string.h>

int insertStr(char *strDest, int pos, char *strOrg)
{
    int longDest = strlen(strDest);
    int longOrg = strlen(strOrg);
    int longFinal = (longDest + longOrg);
    int i;
    char aux[longFinal];

    if (pos <= longDest)
    {
        // guardamos el original y le clavamos el \0
        strcpy(aux, strDest);
        *(aux + pos) = '\0';

        // pegamos el string en el \0
        strcat(aux, strOrg);

        // copiamos el resto
        for (i = (pos + longOrg); i < (longFinal); i++, pos++)
        {
            *(aux + i) = *(strDest + pos);
        }
        aux[longFinal] = '\0';

        // devolvemos strDest modificado
        strcpy(strDest, aux);
    }

    // longitud inicial y final son distintas? -> TRUE, else FALSE;
    return (longDest != strlen(strDest)) ? longOrg : 0;
}
int main(void)
{
    char strDest[20] = "hola";
    int pos[] = {0, 4, 2, 100, 0};
    char *strOrg[] = {"XX", "XX", "XX", "XX", ""};
    int agregado;

    for (int i = 0; i < 5; i++)
    {
        agregado = insertStr(strDest, pos[i], strOrg[i]);
        printf("El nuevo string es '%s'\n", strDest);
        printf("La cantidad agregada es %d\n", agregado);
        strcpy(strDest, "hola");
    }

    return 0;
}