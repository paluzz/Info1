#include <stdio.h>
#include <math.h>

int main(void)
{
    int argumento;
    float logaritmo;

    printf("Ingrese un numero: ");
    scanf("%d", &argumento);

    logaritmo = log2f((float)argumento);
    printf("El logaritmo en base 2 de %d es: %.3f\n", argumento, logaritmo);

    return 0;
}