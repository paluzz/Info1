#include <stdio.h>
#define CANT 5
float promedio(float *dataPtr, int dataCant)
{
    float p = 0;
    int i;
    for (i = 0; i < dataCant; i++)
    {
        // sumar todos los valores
        // dividirlo cantidad total
        p += *(dataPtr + i);
    }

    return (p / dataCant);
}

int main(void)
{
    float v[CANT] = {1, 2, 3, 4, 5};
    float q;

    q = promedio(&v[0], CANT);

    // inicializando vector con puntero
    printf("El promedio es %.2f\n", q);

    return 0;
}