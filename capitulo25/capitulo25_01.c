// | si ponemos un 1 prende todo FV = V // VF = V // VV = V
// & apaga todo menos la igualdad de 1 FV = F // VF = F // VV = V
// ^ si ponemos 1, invierte ese bit FV = V // VF = V // VV = F
// ~ invierte totalidad
// >> mueve hacia la derecha x bits
// << hacia la izq
#include <stdio.h>

int leerBit(int palabra, int bit)
{
    if (bit < 0 || bit >= 8)
    {
        return -1;
    }
    // movemos el 1 al bit deseado
    int mascara = 1 << bit;

    // Comparamos el bit con palabra y el resultado (0 1) lo movemos al ultimo bit
    int valorBit = (palabra & mascara) >> bit;

    return valorBit;
}

int main(void)
{
    int palabra = 0x0F; // 00001111 en binario
    int i, valorBit;

    for (i = 0; i < 8; i++)
    {
        valorBit = leerBit(palabra, i);
        printf("El bit en la posición %d es: %d\n", i, valorBit);
    }

    return (0);
}