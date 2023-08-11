#include <stdio.h>

int main(void)
{
    int nota, acumulador = 0, i = 0;
    float promedio;

    do
    {
        printf("Ingrese nota: ");
        scanf("%d", &nota);

        if ((nota >= 0) && (nota <= 10))
        {
            acumulador += nota;
            i++;
        }
        else if ((nota == -1) && (i < 3))
        {
            printf("Continue agregando notas\n");
            // para evitar que salga del while
            // le asigno un valor cualquiera a nota
            // antes de abandonar el if
            nota = 0;
        }
        else
        {
            if (nota != -1)
            {
                printf("Fuera de rango\n");
            }
        }

    } while (nota != -1);

    promedio = (float)acumulador / i;
    printf("El promedio es: %.2f\n", promedio);

    return 0;
}