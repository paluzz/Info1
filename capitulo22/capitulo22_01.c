#include <stdio.h>

void printHex(void *dataPtr, int dataSize)
{
    char *dataAux;
    dataAux = (char *)dataPtr;
    for (int i = 0; i < dataSize; i++)
    {
        printf("%x ", *(dataAux + i));
    }
    printf("\n");
}
