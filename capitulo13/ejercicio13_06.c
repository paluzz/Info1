#include <stdio.h>
int esPrimo(int);

int main(void)
{
    int num;
    printf("Ingrese num: ");
    scanf("%d", &num);

    printf("return esPrimo: %d\n", esPrimo(num));
    return 0;
}

int esPrimo(int n)
{
    int primo = 1;
    if (n <= 0)
    {
        primo = -1;
    }
    else if (n == 1)
    {
        primo = 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if ((n % i) == 0)
            {
                primo = 0;
                break;
            }
        }
    }

    return primo;
}