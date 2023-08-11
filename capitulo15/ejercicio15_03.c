#include <stdio.h>
#define CANT 6
int orden(int *dataPtr, int dataCant)
{
    int status, creciente = 1, decreciente = 1;

    for (int i = 1; i < dataCant; i++)
    {
        if (*(dataPtr + i - 1) > *(dataPtr + i))
        {
            // a > b ? decreciente => apagamos la otra opcion
            creciente = 0;
        }

        else if (*(dataPtr + i - 1) < *(dataPtr + i))
        {
            // a < b ? creciente => apagamos la otra opcion
            decreciente = 0;
        }
    }

    if (creciente)
    {
        status = 1;
    }
    else if (decreciente)
    {
        status = -1;
    }
    else
    {
        status = 0;
    }
    return status;
}

int main(void)
{
    int v1[CANT] = {1, 2, 3, 4, 5, 6};
    int v2[CANT] = {1, 4, 6, 2, 1, 8};
    int v3[CANT] = {10, 9, 8, 7, 6};
    int v4[CANT] = {10, 9, 0, 7, 6};
    int *v[] = {v1, v2, v3, v4}; // vector para recorrer los otros vectores

    for (int i = 0; i < 4; i++)
    {
        if (orden(v[i], CANT) == 1)
        {
            printf("el vector #%d esta ordenado crecientemente\n", i + 1);
        }
        else if (orden(v[i], CANT) == -1)
        {
            printf("el vector #%d esta ordenado decrecientemente\n", i + 1);
        }
        else
        {
            printf("el vector #%d no esta ordenado\n", i + 1);
        }
    }

    return 0;
}