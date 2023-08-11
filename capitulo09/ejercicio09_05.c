#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main(void)
{
    int angulo;
    float radian, coseno;

    printf("Ingrese un número: ");
    scanf("%d", &angulo);

    radian = ((float)angulo * PI) / 180;
    coseno = cosf(radian);

    printf("El Coseno de %d° es : %.3f\n", angulo, coseno);

    return 0;
}