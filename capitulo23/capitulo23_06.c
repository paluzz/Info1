#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **splitStr(char *str, char c, int *cant)
{
    // Verificar si el string de entrada es NULL
    if (str == NULL)
    {
        return NULL;
    }

    int l = strlen(str);
    int palabras = 0;
    char aux[50];
    char **split = NULL;

    // Contamos la cantidad de palabras
    for (int i = 0; i < (l + 1); i++)
    {
        if (*(str + i) == c || *(str + i) == '\0')
        {
            palabras++;
        }
    }

    // devolvemos cantidad de palabras
    *cant = palabras;

    split = (char **)malloc(sizeof(char *) * (palabras));
    if (split == NULL)
    {
        printf("Error memoria\n");
        return NULL;
    }

    for (int i = 0, j = 0, k = 0; i < (l + 1); i++)
    {
        if ((*(str + i) != c) && (*(str + i) != '\0'))
        {
            // copiamos el string en uno auxiliar
            aux[k] = *(str + i);
            k++;
        }
        else
        {
            aux[k] = '\0';

            *(split + j) = (char *)malloc(sizeof(char) * (k));
            if (*(split + j) == NULL)
            {
                printf("Error memoria\n");
                return NULL;
            }

            strcpy(*(split + j), aux);

            j++;
            k = 0;
        }
    }
    return split;
}

int main(void)
{
    char str[] = "hola.mundo.zapallo.banana";
    int cant;
    char **separados = splitStr(str, '.', &cant);

    for (int i = 0; i < 4; i++)
    {
        printf("%s\r\n", separados[i]);
        free(separados[i]);
    }
    free(separados);
    printf("cant: %d\n", cant);

    return 0;
}