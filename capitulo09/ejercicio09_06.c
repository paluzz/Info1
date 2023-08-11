#include <stdio.h>
#include <math.h>

int main(void)
{
    int primero, segundo;
    float hipotenusa, adyacente, opuesto;

    printf("Ingrese un numero: ");
    scanf("%d", &primero);
    printf("Ingrese un numero: ");
    scanf("%d", &segundo);

    adyacente = pow((float)primero, 2);
    opuesto = pow((float)segundo, 2);
    hipotenusa = sqrt(adyacente + opuesto);

    printf("La hipotenusa es : %.4f\n", hipotenusa);

    return 0;
}