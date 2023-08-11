#include <stdio.h>

int main(void)
{
    int primero, segundo;

    printf("Ingrese nota primer parcial: ");
    scanf("%d", &primero);

    if (primero >= 0 && primero <= 10)
    {
        printf("Ingrese nota segundo parcial: ");
        scanf("%d", &segundo);

        if (segundo >= 0 && segundo <= 10)
        {
            if (primero < 6 || segundo < 6)
            {
                printf("Debe recuperar algun parcial\n");
            }
            else
            {
                if (primero >= 7 && segundo >= 8)
                {
                    printf("Promociona\n");
                }
                else
                {
                    printf("Firma la materia\n");
                }
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 0;
}