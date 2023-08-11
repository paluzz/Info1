#include <stdio.h>
#define PRIMO ((int)1)
#define NO_PRIMO ((int)0)

int main(void)
{
    int input, primo = PRIMO;

    printf("Ingrese un numero: ");
    scanf("%d", &input);

    if ((input == 0) || (input == 1))
    {
        primo = NO_PRIMO;
    }
    else
    {
        for (int i = 2; i < input; i++)
        {
            if ((input % i) == NO_PRIMO)
            {
                primo = NO_PRIMO;
                break;
            }
        }
    }

    if (primo == PRIMO)
    {
        printf("El numero %d es primo\n", input);
    }
    else
    {
        printf("El numero %d no es primo\n", input);
    }

    return 0;
}