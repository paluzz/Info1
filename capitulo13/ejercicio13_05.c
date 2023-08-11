#include <stdio.h>
#include <math.h>
float calcHipo(float, float);

int main(void)
{
    float a, b, c;
    printf("Ingrese num: ");
    scanf("%f", &a);
    printf("Ingrese num: ");
    scanf("%f", &b);

    c = calcHipo(a, b);
    printf("Hipotenusa: %.2f\n", c);
    return 0;
}

float calcHipo(float catetoA, float catetoB)
{
    float a, b;
    a = pow(catetoA, 2);
    b = pow(catetoB, 2);
    return sqrtf(a + b);
}