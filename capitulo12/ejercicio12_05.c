#include <stdio.h>
#define NUMEROS ((int)10)
#define PAR ((int)0)

int main(void)
{
    int input, par = 0, impar = 0;

    for (int i = 0; i < NUMEROS; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &input);
        if (input >= 0)
        {
            if (input % 2 == PAR)
            {
                par++;
            }
            else
            {
                impar++;
            }
        }
        else
        {
            printf("Solo numeros positivos \n");
            i--;
        }
    }

    printf("En total hay %d pares y %d impares\n", par, impar);
    return 0;
}