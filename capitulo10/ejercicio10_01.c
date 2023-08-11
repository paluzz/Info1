#include <stdio.h>

int main(void)
{
    int n;

    printf("ingrese un numero: ");
    scanf("%d", &n);

    if ((n % 2) == 0)
    {
        printf("Es par\n");
    }
    else
    {
        printf("Es impar\n");
    }

    return 0;
}