#include <stdio.h>

int fibonacci(int n)
{
    // Casos base: Fibonacci de 0 es 0 y de 1 es 1.
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    // Caso recursivo: Fibonacci de n es la suma de Fibonacci de (n-1) y (n-2).
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    // Imprime los primeros 10 términos de la serie de Fibonacci.
    int i;
    for (i = 0; i < 10; ++i)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
