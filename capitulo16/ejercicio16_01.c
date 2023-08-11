#include <stdio.h>
#include <stdlib.h>
#define Ñ ((char)241)

int main(void)
{
    int i = 0;
    char *p;
    p = (char *)malloc(sizeof(char) * ('z' - 'a')); // longitud -> 25
    if (p == NULL)
    {
        return -1;
    }

    for (char letra = 'a'; letra <= 'z'; letra++, i++)
    {
        if (letra != Ñ)
        {
            *(p + i) = letra;
        }
    }

    printf("%s\n", p);
    free(p);
    return 0;
}