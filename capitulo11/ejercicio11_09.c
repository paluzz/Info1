#include <stdio.h>

int main(void)
{
    int secreto = 0, adivinacion, intento = 0, flag = 0;

    printf("Ingrese un numero SECRETO: ");
    scanf("%d", &secreto);

    do
    {
        if ((secreto < 0) || (secreto > 9))
        {
            printf("Numero fuera del rango [0,9]\n");
            printf("Ingrese un numero SECRETO: ");
            scanf("%d", &secreto);
            intento = 0;
        }
        else
        {
            printf("Adivine el numero: ");
            scanf("%d", &adivinacion);

            if ((adivinacion < 0) || (adivinacion > 9))
            {
                printf("Numero fuera del rango [0,9]\n");
            }

            else if (adivinacion == secreto)
            {
                printf("GANASTE\n");
                printf("Ingrese un numero SECRETO: ");
                scanf("%d", &secreto);
                intento = 0;
            }

            else
            {
                intento++;
                if (intento == 3)
                {
                    printf("NO GANASTE INTENTALO OTRA VEZ\n");
                    printf("Ingrese un numero SECRETO: ");
                    scanf("%d", &secreto);
                    intento = 0;
                }
            }
        }
    } while (!flag);

    return 0;
}