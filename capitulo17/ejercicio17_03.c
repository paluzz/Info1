#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int subStr(char *str, int pos, int len, char *strRes)
{
    int i, j;
    int longitud = strlen(str);

    for (i = 0; i < len; i++)
    {
        j = pos + i;
        *(strRes + i) = *(str + j);
    }

    strRes[len] = '\0';

    return (pos < longitud && len > 0) ? TRUE : FALSE;
}
int main(void)
{
    char str[] = "hola como te va";
    int pos[] = {0, 13, 13, 0, 16};
    int len[] = {4, 2, 3, 0, 10};
    int quitado;

    for (int i = 0; i < 5; i++)
    {
        char *strRes;
        strRes = (char *)malloc(sizeof(char) * (len[i]));
        quitado = subStr(str, pos[i], len[i], strRes);
        if (quitado == TRUE)
        {
            printf("El string quitado es '%s'\n", strRes);
        }
        else
        {
            printf("No se pudo quitar str\n");
        }
        free(strRes);
    }

    return 0;
}