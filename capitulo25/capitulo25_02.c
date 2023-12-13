// | si ponemos un 1 prende todo FV = V // VF = V // VV = V
// & apaga todo menos la igualdad de 1 FV = F // VF = F // VV = V
// ^ si ponemos 1, invierte ese bit FV = V // VF = V // VV = F
// ~ invierte totalidad
// >> mueve hacia la derecha x bits
// << hacia la izq
#include <stdio.h>
#include <stdlib.h>

int negarBit(int palabra, int bit)
{
    if (bit < 0 || bit >= 8)
    {
        return -1;
    }

    int mascara = 1 << bit;

    // aplicamos XOR para negar ese bit
    int valorBit = palabra ^ mascara;

    return valorBit;
}
// funcion auxiliar
void imprimirBin(int n)
{
    // solo positivos
    if (!(n < 0))
    {
        int longitud = 0, i = 0, j;
        int *v = (int *)malloc(sizeof(int));
        int original = n;
        int *a = NULL;
        char *bin = NULL;

        if (v != NULL)
        {
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
            printf("%d : %s\n", original, bin);
            free(bin);
            free(v);
        }
    }
}

int main(void)
{
    int palabra = 89;
    int bit = 2;
    int valorNegado;

    printf("original\n");
    imprimirBin(palabra);

    valorNegado = negarBit(palabra, bit);
    printf("Negando el bit %d \n", bit);
    imprimirBin(valorNegado);
    return 0;
}