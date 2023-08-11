#include <stdio.h>
int factorial(int);
int main(void)
{
    int a;
    printf("ingrese num: ");
    scanf("%d", &a);
    a = factorial(a);
    printf("Factorial = %d\n", a);

    return 0;
}

int factorial(int n)
{
    int resultado = 1;
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            resultado *= i;
        }
    }
    else if (n == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = 0;
    }

    return resultado;
}