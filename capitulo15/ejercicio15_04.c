#include <stdio.h>
#define CANT ((int)10)
int *myMax(int *dataPtr, int dataCant)
{
    int *p, temp;
    p = dataPtr;
    temp = dataPtr[0];

    for (int i = 0; i < dataCant; i++)
    {
        if (*(dataPtr + i) > temp)
        {
            temp = *(dataPtr + i);
            *p = i;
        }
    }
    return p;
}
int main(void)
{
    int v[CANT], largo = 0;
    int *p;
    p = &v[0];

    for (int i = 0; i < CANT; i++)
    {
        printf("ingrese dato %d: ", i);
        scanf("%d", &v[i]);
        largo++;
    }

    p = myMax(p, largo);

    printf("El maximo se encuentra en: %d\n", *p);
    return 0;
}