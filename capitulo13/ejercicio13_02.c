#include <stdio.h>
#include <math.h>

float perimetroCirculo(float);

int main(void)
{
    float radio, perim;

    printf("ingrese radio: ");
    scanf("%f", &radio);

    perim = perimetroCirculo(radio);
    printf("El Perimetro del circulo es %.2f\n", perim);

    return 0;
}

float perimetroCirculo(float radio)
{
    return (2 * M_PI * radio);
}