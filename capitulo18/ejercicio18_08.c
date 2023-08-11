#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *imprimirBinario(int n)
{
    // solo positivos
    if (n < 0)
    {
        return NULL;
    }
    int longitud = 0, i = 0, j;
    int *v = (int *)malloc(sizeof(int));
    int *a = NULL;
    char *bin = NULL;

    if (v == NULL)
    {
        return NULL;
    }

    while (n > 0)
    {
        // convertimos a binario
        v[i] = n % 2;
        n /= 2;
        longitud++;
        i++;
        a = (int *)realloc(v, sizeof(v) * i + 1);
        if (a != NULL)
        {
            v = a;
        }
    }
    // agregamos primer valor
    v[i] = n;
    bin = (char *)malloc(sizeof(char) * longitud);
    // invertimos el vector y lo convertimos a char
    for (i = 0, j = longitud - 1; i < longitud; i++, j--)
    {
        bin[i] = v[j] + '0';
    }
    bin[i] = '\0';

    return bin;
}
int main(void)
{
    char *binario = NULL;

    binario = imprimirBinario(5);
    printf("esperado: 101\tobtenido: %s\n", binario);
    free(binario);
    binario = imprimirBinario(43);
    printf("esperado: 101011\tobtenido: %s\n", binario);
    free(binario);
    binario = imprimirBinario(-5);
    printf("esperado: NULL\tobtenido: %s\n", binario);
    free(binario);
    return 0;
}