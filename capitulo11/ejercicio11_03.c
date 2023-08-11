#include <stdio.h>

int main(void)
{
    int input, acumulador = 0;
    float promedio;

    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese la nota #%d: ", i + 1);
        scanf("%d", &input);

        acumulador += input;
    }
    promedio = (float)acumulador / 10;
    printf("El promedio es: %.2f\n", promedio);

    return 0;
}
