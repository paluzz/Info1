#include <stdio.h>
#include <math.h>

float areaCirculo(float);

int main(void)
{
    float radio, area;

    printf("ingrese radio: ");
    scanf("%f", &radio);

    area = areaCirculo(radio);
    printf("El Area del circulo es %.2f\n", area);

    return 0;
}

float areaCirculo(float radio)
{
    return (M_PI * pow(radio, 2));
}