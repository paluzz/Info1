#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int cantidad, i;
    printf("Ingrese longitud: ");
    scanf("%d", &cantidad);
    char *p;
    p = (char *)malloc(sizeof(char) * cantidad);
    if (p == NULL)
    {
        return -1;
    }

    printf("Llene el texto: ");
    for (i = 0; i <= cantidad; i++)
    {
        scanf("%c", &p[i]);
    }
    printf("texto ingresado: %s\n", p);

    printf("texto invertido: \n");
    for (i = cantidad; i > 0; i--)
    {
        printf("%c", *(p + i));
    }
    printf("\n");

    free(p);

    return 0;
}