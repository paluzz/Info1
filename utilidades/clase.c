#include <stdio.h>

void contar(int c)
{
    int i;
    printf("Conteo: ");
    for (i = c; i >= 0; i--)
    {
        printf("%d, ", i);
    }
    printf("\r\n");
}

void contarR(int c)
{
    printf("%d, ", c);
    if (c > 0)
    {
        contarR(c - 1);
    }
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * factorial(n - 1));
    }
}
int main(void)
{
    int c, f;
    printf("ingrese: ");
    scanf("%d", &c);

    f = factorial(c);
    printf("factorial %d", f);
    /*
    contar(c);
    printf("Conteo recursivo: ");
    contarR(c);*/
    printf("\r\n");
    return 0;
}