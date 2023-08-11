#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i = 0;
    char *p, *pRealloc;
    p = (char *)malloc(sizeof(char) * i);

    if (p == NULL)
    {
        return -1;
    }
    printf("ingrese letra: ");
    scanf("%c", &p[i]);

    while (*(p + i) != '!')
    {
        i++;
        pRealloc = (char *)realloc(p, sizeof(*p) * (i));
        if (pRealloc != NULL)
        {
            p = pRealloc;
            printf("ingrese letra: ");
            scanf("%*c%c", &p[i]);
        }
    }

    printf("Letras ingresadas:");
    for (int i = 0; *(p + i) != '!'; i++)
    {
        printf("%c", *(p + i));
    }
    printf("\n");

    free(p);

    return 0;
}