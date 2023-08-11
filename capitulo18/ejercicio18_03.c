#include <stdio.h>
#include <string.h>
void contarCaracteres(char *dataPtr, int *dataCntPtr)
{
    int c = 0, i, l = strlen(dataPtr);

    for (i = 0; i < l; i++)
    {
        c = *(dataPtr + i);
        *(dataCntPtr + c) = *(dataCntPtr + c) + 1;
    }
}
int main(void)
{
    int vectCnt[256];
    int i;
    for (i = 0; i < 255; i++)
    {
        vectCnt[i] = 0;
    }
    contarCaracteres("AABBCCC", &vectCnt[0]);
    for (i = 0; i < 255; i++)
    {
        if (vectCnt[i] != 0)
        {
            printf("%d\n", vectCnt[i]);
        }
    }
    return 0;
}